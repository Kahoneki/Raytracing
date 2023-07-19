#include "hittable_list.h"

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        //closest_so_far gets passed in as the t_max parameter so that if the function returns true, the t value will be in the range t_min to closest_so_far and so t will be the newest closest_so_far
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
            // std::cerr << temp_rec.normal << std::endl;
        }
    }
    return hit_anything;
}


void hittable_list::clear() {
    objects.clear();
}


void hittable_list::add(shared_ptr<hittable> object) {
    objects.push_back(object);
}