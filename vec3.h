#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class vec3 {
    public:
        vec3() : e{0,0,0} {};
        vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}
    
        //Getters
        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}
        double operator[](int i) const {return e[i];}

        //Setters
        double& operator[](int i) {return e[i];}

        //Object utility functions
        vec3 operator-() const;
        vec3& operator+=(const vec3&v);
        vec3& operator*=(const double t);
        vec3& operator/=(const double t);
        double length() const;
        double length_squared() const;

    private:
        double e[3];
};


//General utility functions
std::ostream& operator<<(std::ostream& out, const vec3& v);
vec3 operator+(const vec3 &u, const vec3 &v);
vec3 operator-(const vec3 &u, const vec3 &v);
vec3 operator*(const vec3 &u, const vec3 &v);
vec3 operator*(double t, const vec3 &v);
vec3 operator*(const vec3 &v, double t);
vec3 operator/(vec3 v, double t);

double dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);
vec3 unit_vector(vec3 v);

vec3 random();
vec3 random(double min, double max);
vec3 random_in_unit_sphere();
vec3 random_unit_vector();
vec3 random_in_hemisphere(const vec3& normal);


//Type aliases for vec3
using point3 = vec3;    //3D point
using colour = vec3;    //RGB colour


#endif