#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 p; //hitpoint
    vec3 normal;
    double t; //distance along ray
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif