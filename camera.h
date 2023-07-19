#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class camera {
    public:
        camera() {}
        ray get_ray(double u, double v) const;
        
    private:
        const float aspect_ratio = 16.0 / 9.0;
        float viewport_height = 2.0;
        float viewport_width = aspect_ratio * viewport_height;
        float focal_length = 1.0;
        vec3 origin = point3(0,0,0);
        vec3 horizontal = vec3(viewport_width, 0, 0);
        vec3 vertical = vec3(0, viewport_height, 0);
        vec3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,focal_length);
};

#endif