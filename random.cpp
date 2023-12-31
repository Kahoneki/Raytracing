#include "random.h"
#include <cstdlib>

double random_double() {
    //Returns a random real in [0,1]
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    //Returns a random real in [min,max]
    return min + (max-min)*random_double();
}