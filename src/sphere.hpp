#pragma once

#include "vector.hpp"
#include "ray.hpp"

class sphere {
public:
    sphere(): orig(point(0,0,0)), r(0.0) {}
    sphere(point origin, double radius)
    : orig(origin), r(radius) {}

    inline point origin() const { return orig; }
    inline double radius() const { return r; }

    vec3 normal_at(vec3& v) {
        return (orig - v).normalized();
    }

private:
    point orig;
    double r;
};

namespace Shapes {
    namespace Sphere {
        double ray_hit(sphere s, ray r) {
            vec3 origin_to_center = r.origin() - s.origin();
            double a = r.direction().length_squared();
            double half_b = dot(origin_to_center, r.direction());
            double c = origin_to_center.length_squared() - s.radius() * s.radius();
            double discriminant = half_b*half_b - a*c;
            
            if(discriminant < 0.0) {
                return -1.0;
            }
            return (- half_b - sqrt(discriminant)) / a;
        }
    }
}