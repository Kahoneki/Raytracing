#include "camera.h"

ray camera::get_ray(double s, double t) const {
    return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
}