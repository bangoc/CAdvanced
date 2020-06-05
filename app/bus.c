#include "DebugPrintf/debug_printf.h"
#include "c-vector/cvector.h"
#include "igraph/igraph.h"
#include "libfdr/jrb.h"
#include "mylib/containers.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *station;
  char *route;
} BStop;

int collect_id_jrb(void *key, void *val, void *u) {
  igraph_vector_push_back((igraph_vector_t*)u, ((Jval*)val)->i);
  return 0;
}

JRB station_route_id = NULL;
JRB id_bstop = NULL;
igraph_vector_t weights;
igraph_vector_t edges;
const int kNext = 1;
const int kChange = 100000;
int vertices_count = 0;

void free_id_bstop() {
  JRB ptr;
  jrb_traverse(ptr, id_bstop) {
    BStop *bs = (BStop*)ptr->val.v;
    free(bs->station);
    free(bs->route);
    free(bs);
  }
  jrb_free_tree(id_bstop);
}

void free_station_route_id() {
  JRB ptr;
  jrb_traverse(ptr, station_route_id) {
    JRB routes_on_stop = ptr->val.v;
    JRB r;
    jrb_traverse(r, routes_on_stop) {
      free(r->key.s);
    }
    jrb_free_tree(r);
    free(ptr->key.s);
  }
  jrb_free_tree(station_route_id);
}

JRB get_or_create(JRB root, char *station) {
  JRB node = jrb_find_str(root, station);
  JRB routes_on_stop = NULL;
  if (node) {
    routes_on_stop = node->val.v;
    printfInfo("found station! on %s", station);
  } else {
    routes_on_stop = make_jrb();
    jrb_insert_str(root, strdup(station),
      (Jval){.v = routes_on_stop});
  }
  return routes_on_stop;
}

BStop *make_bstop(char *station, char *route) {
  BStop *bstop = (BStop*)malloc(sizeof(BStop));
  bstop->station = strdup(station);
  bstop->route = strdup(route);
  return bstop;
}

void remove_trailing(char *s) {
  int len = strlen(s);
  while (len > 0 && isspace(s[len - 1])) {
    s[len - 1] = '\0';
    --len;
  }
}

void store_edge(int f, int t, int wt) {
  igraph_vector_push_back(&edges, f);
  igraph_vector_push_back(&edges, t);
  igraph_vector_push_back(&weights, wt);
  printfInfo("Edge(%d, %d):%d", f, t, wt);
}

int read_input(const char *inp_name) {
  station_route_id = make_jrb();
  id_bstop = make_jrb();
  igraph_vector_init(&weights, 0);
  igraph_vector_init(&edges, 0);
  char station[1000];
  char route[100];
  FILE *f = fopen(inp_name, "r");
  int id = 0;
  while(!feof(f)) {
    fscanf(f, "%[^:]%*[:]", route);
    int prev = -1;
    while (fscanf(f, " %[^>\n]", station) > 0) {
      remove_trailing(station);
      JRB routes_on_stop = get_or_create(station_route_id, station);
      if (jrb_find_str(routes_on_stop, route)) {
        printfError("Duplicate station on route %s (%s)", route, station);
        return 1;
      }
      jrb_insert_str(routes_on_stop, strdup(route), (Jval){.i = id});
      jrb_insert_int(id_bstop,
        id, (Jval){.v = make_bstop(station, route)});
      printfInfo("(%s, %s):%d", station, route, id);
      if (prev >= 0) {
        store_edge(prev, id, kNext);
      }
      prev = id++;
      fscanf(f, "%*[>]");
      if (fscanf(f, "%[\n]", station) > 0) {
        break;
      }
    }
  }
  fclose(f);
  vertices_count = id;
  return 0;
}

int change_on_station(void *key, void *val, void *u) {
  JRB routes = ((Jval*)val)->v;
  JRB i1, i2;
  jrb_traverse(i1, routes) {
    jrb_traverse(i2, routes) {
      if (i1 != i2) {
        store_edge(i1->val.i, i2->val.i, kChange);
      }
    }
  }
  return 0;
}

void define_route_change() {
  jrb_foreach(station_route_id, change_on_station, NULL);
}

igraph_t g;

void build_graph() {
  igraph_empty(&g, vertices_count, IGRAPH_DIRECTED);
  igraph_add_edges(&g, &edges, 0);
  printfInfo("Số lượng đỉnh: %d \n", igraph_vcount(&g));
  printfInfo("Số lượng cạnh: %d\n", igraph_ecount(&g));
}

long min_cost = -1;
cvector_vector_type(cvector_vector_type(int)) paths = NULL;
void free_paths() {
  for (int i = 0; i < cvector_size(paths); ++i) {
    cvector_free(paths[i]);
  }
  cvector_free(paths);
  paths = NULL;
}

igraph_vector_t ifrom, ito;

int identify_station(igraph_vector_t *v, char *station) {
  JRB node = jrb_find_str(station_route_id, station);
  if (node) {
    jrb_foreach(((JRB)(node->val.v)), collect_id_jrb, v);
    return 0;
  }
  printfError("Station %s not found", station);
  return 1;
}

cvector_vector_type(int) convert_ivec2cvec(igraph_vector_t *in) {
  cvector_vector_type(int) out = NULL;
  for (int i = 0; i < igraph_vector_size(in); ++i) {
    cvector_push_back(out, (int)VECTOR(*in)[i]);
  }
  return out;
}

long get_path_cost(igraph_vector_t *edges) {
  long cost = 0;
  for (int i = 0; i < igraph_vector_size(edges); ++i) {
    int eid = (int)VECTOR(*edges)[i];
    int ewt = (int)VECTOR(weights)[eid];
    printfInfo(" %d:%d", eid, ewt);
    cost += ewt;
  }
  return cost;
}

void find_shortest_paths() {
  igraph_vs_t vs_to;
  igraph_vector_ptr_t vecs, evecs;
  igraph_vector_ptr_init(&vecs, igraph_vector_size(&ito));
  igraph_vector_ptr_init(&evecs, igraph_vector_size(&ito));
  for (int i = 0; i < igraph_vector_ptr_size(&vecs); i++) {
      VECTOR(vecs)[i] = calloc(1, sizeof(igraph_vector_t));
      igraph_vector_init(VECTOR(vecs)[i], 0);
      VECTOR(evecs)[i] = calloc(1, sizeof(igraph_vector_t));
      igraph_vector_init(VECTOR(evecs)[i], 0);
  }
  igraph_vs_vector(&vs_to, &ito);

  for (int f = 0; f < igraph_vector_size(&ifrom); ++f) {
    igraph_get_shortest_paths_dijkstra(&g, &vecs,
      &evecs, VECTOR(ifrom)[f], vs_to,
      &weights, IGRAPH_OUT, NULL, NULL);
    for (int i = 0; i < igraph_vector_ptr_size(&vecs); i++) {
        long cost = get_path_cost(VECTOR(evecs)[i]);
        if (cost < min_cost || min_cost < 0) {
          min_cost = cost;
          free_paths();
        }
        if (cost == min_cost) {
          cvector_push_back(paths, convert_ivec2cvec(VECTOR(vecs)[i]));
        }
    }
  }
  for (int i = 0; i < igraph_vector_ptr_size(&vecs); i++) {
    igraph_vector_destroy(VECTOR(vecs)[i]);
    free(VECTOR(vecs)[i]);
    igraph_vector_destroy(VECTOR(evecs)[i]);
    free(VECTOR(evecs)[i]);
  }
  igraph_vs_destroy(&vs_to);
  igraph_vector_ptr_destroy(&vecs);
  igraph_vector_ptr_destroy(&evecs);
}

void display_output() {
  printf("Min cost is: %li\n", min_cost);
  for (int i = 0; i < cvector_size(paths); ++i) {
    cvector_vector_type(int) p = paths[i];
    for (int j = 0; j < cvector_size(p); ++j) {
      JRB node = jrb_find_int(id_bstop, p[j]);
      BStop *bs = (BStop*)node->val.v;
      printf("%s(%s) > ", bs->station, bs->route);
    }
    printf("\n");
  }
}

void free_glob() {
  free_id_bstop();
  free_station_route_id();
  free_paths();
  igraph_vector_destroy(&ifrom);
  igraph_vector_destroy(&ito);
  igraph_vector_destroy(&edges);
  igraph_vector_destroy(&weights);
  igraph_destroy(&g);
}

int main(int argc, char *argv[]) {
  if (read_input(argv[1])) {
    return 1;
  }
  define_route_change();
  igraph_vector_init(&ifrom, 0);
  igraph_vector_init(&ito, 0);
  if (identify_station(&ifrom, argv[2]) ||
      identify_station(&ito, argv[3])) {
    return 1;
  }
  build_graph();
  find_shortest_paths();
  display_output();
  free_glob();
  return 0;
}