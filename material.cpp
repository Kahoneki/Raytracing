#include "material.h"

bool lambertian::scatter(const ray& r_in, hit_record& rec, colour& attenuation, ray& scattered) const {
    auto scatter_direction = rec.normal + random_unit_vector();
    //If random_unit_vector() = -rec.normal exactly, the scatter direction will be 0 which leads to bad values.
    if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}


bool metal::scatter(const ray& r_in, hit_record& rec, colour& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere()); //fuzz represents the radius of the unit sphere used to offset scattered ray
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}