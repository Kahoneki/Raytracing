#include "colour.h"
#include "ray.h"
#include "vec3.h"

#include "hittable_list.h"
#include "sphere.h"

#include <iostream>

#include <cmath>

const double infinity = std::numeric_limits<double>::infinity();

// double hit_sphere(const point3& center, double radius, const ray& r) {
//     vec3 oc = r.origin() - center;
//     auto a = r.direction().length_squared();
//     auto half_b = dot(oc, r.direction());
//     auto c = oc.length_squared() - radius*radius;
//     auto discriminant = half_b*half_b - a*c;
//     if (discriminant < 0)
//         return -1.0;
//     else
//         return (-half_b-sqrt(discriminant))/a;
// }

colour ray_colour(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r,0,infinity,rec)) {
        return 0.5*(rec.normal+colour(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*colour(1.0,1.0,1.0) + t*colour(0.5,0.7,1.0);

    // auto t = hit_sphere(point3(0,0,-1),0.5,r);
    // if (t>0.0) {
    //     vec3 N = unit_vector(r.at(t) - vec3(0,0,-1)); //Normal calculated by subtracting sphere centre from hitpoint on sphere
    //     return 0.5*colour(N.x()+1, N.y()+1, N.z()+1); //Shifting normal from range [-1, 1] to [0,2], then multiplying by 0.5 to shift into range [0,1] for appropriate rgb values
    // }

    // //Generating a background gradient by linearly interpolating two colours based on the direction of the ray (whether its y component is positive or negative)
    // t = 0.5*(unit_direction.y() + 1.0);
}

int main() {
    
    //Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 1200;
    const int image_height = static_cast<int>(image_width/aspect_ratio);

    
    //World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));


    //Camera    
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0,0,0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,focal_length);


    //Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j=image_height-1; j>=0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i)/(image_width-1);
            auto v = double(j)/(image_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            colour pixel_colour = ray_colour(r, world);
            write_colour(std::cout, pixel_colour);
        }
    }

    std::cerr << "\nDone. :]\n";
}