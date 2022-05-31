#pragma once

#include "vector.hpp"

class ray {
public:
    ray() {}
    ray(point p, vec3 v)
        : orig(p), dir(v) {}

    point at(double t) {
        return orig + dir*t;
    }

    point origin() const {
        return orig;
    }

    vec3 direction() const {
        return dir;
    }

private:
    point orig;
    vec3 dir;
};