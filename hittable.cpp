#include "hittable.h"

//Make normal always face against incident ray (i.e.: when ray enters surface, normal points against ray (out of surface), when ray exits surface, normal points against ray (inside surface))
void hit_record::set_face_normal(const ray& r, const vec3& outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal :-outward_normal;
}