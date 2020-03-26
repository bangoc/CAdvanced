#!/bin/bash
gcc -E recap1.c -I../../ > out1.c
gcc -E recap1.c -I../../ -DCVECTOR_LOGARITHMIC_GROWTH > out2.c