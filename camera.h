#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include <cmath>

const double pi = 3.14159265358979323846;

class camera {
    public:
        camera(
            point3 lookfrom,
            point3 lookat,
            vec3 vup,
            double vfov, //vertical field-of-view in degrees
            double aspect_ratio,
            double aperture,
            double focus_dist
        ) {
            auto theta = vfov * pi / 180.0; //convert to radians
            auto h = tan(theta/2);
            auto viewport_height = 2.0 * h;
            auto viewport_width = aspect_ratio * viewport_height;

            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w,u);

            origin = lookfrom;
            horizontal = focus_dist * viewport_width * u;
            vertical = focus_dist * viewport_height * v;
            lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist*w;

            lens_radius = aperture/2;
        }
        ray get_ray(double u, double v) const;
        
    private:
        vec3 origin;
        vec3 horizontal;
        vec3 vertical;
        vec3 lower_left_corner;
        vec3 u,v,w;
        double lens_radius;
};

#endif