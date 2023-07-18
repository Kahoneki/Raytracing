#include "vec3.h"


//Object utility functions
vec3& vec3::operator+=(const vec3 &v) { //parameter being a reference to the actual object saves us from making a copy, this is fine to do because we aren't modifying v (its const)
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this; //we return the current vector to allow for multiple += operations to be chained together. i.e.: a += b += c
}

vec3& vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3 vec3::operator-() const {
    return vec3(-e[0], -e[1], -e[2]);
}

vec3& vec3::operator/=(const double t) {
    return *this *= 1/t;
}

double vec3::length() const {
    return sqrt(length_squared());
}

double vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

////////


//General utility functions
std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.x() + v.x() ,u.y() + v.y(), u.z() + v.z());
}

vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.x(), t*v.y(), t*v.z());
}

vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

double dot(const vec3 &u, const vec3 &v) {
    return u.x() * v.x()
         + u.y() * v.y()
         + u.z() * v.z();
}

vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

vec3 unit_vector(vec3 v) {
    return v / v.length();
}