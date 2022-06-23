#include <stdio.h>
#include <stdlib.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
};