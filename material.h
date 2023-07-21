#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "hittable.h"

class material {
    public:
        virtual bool scatter(const ray& r_in, hit_record&rec, colour& attenuation, ray& scattered) const = 0;
};


//Default diffuse material
class lambertian : public material {
    public:
        lambertian(const colour& a) : albedo(a) {}

        virtual bool scatter(const ray& r_in, hit_record& rec, colour& attenuation, ray& scattered) const override;
    
    public:
        colour albedo;
};


class metal : public material {
    public:
        metal(const colour& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

        virtual bool scatter(const ray& r_in, hit_record& rec, colour& attenuation, ray& scattered) const override;

    public:
        colour albedo;
        double fuzz;
};

#endif