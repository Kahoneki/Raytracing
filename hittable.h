#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include <memory>

class material;

struct hit_record {
    point3 p; //hitpoint
    vec3 normal;
    std::shared_ptr<material> mat_ptr; //will be set to the material of the object that the ray hits
    double t; //distance along ray
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif