size_t i;
for (i = 0; i < cvector_size(v); ++i) {
  printf("v[%lu] = %d\n", i, v[i]);
}

int *it;
for (it = cvector_begin(v); it != cvector_end(v); ++it) {
  printf("v[%d] = %d\n", i, *it);
  ++i;
}

for (Dllist iter = p->flink; iter != p; iter = iter->flink) {
  printfInfo("%d", iter->val.i);
}

jrb_traverse(bn, b) {
  printf("%s", jval_s(bn->key));
}

for(JRB ptr = jrb_first(tree); ptr != jrb_nil(tree); ptr = jrb_next(ptr)) {
  printfInfo("%d(%c)<-%d", ptr->key.i, label[ptr->red], ptr->parent->key.i);
}