#include "material.h"
#include <cmath>

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


bool dielectric::scatter(const ray& r_in, hit_record& rec, colour& attenuation, ray& scattered) const {
    attenuation = colour(1.0, 1.0, 1.0);
    double refraction_ratio = rec.front_face ? (1.0/ir) : ir;

    vec3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = (refraction_ratio * sin_theta) > 1.0;
    vec3 direction;

    if (cannot_refract)
        direction = reflect(unit_direction, rec.normal);
    else
        direction = refract(unit_direction, rec.normal, refraction_ratio);

    scattered = ray(rec.p, direction);
    return true;
}


double dielectric::reflectance(double cosine, double ref_idx) {
    //Use Schlick's approximation for reflectance
    auto r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1-cosine),5);
}