#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include <memory>

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r, std::shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;
    
    public:
        point3 center;
        double radius;
        std::shared_ptr<material> mat_ptr;
};

#endif