#pragma once

#include <math.h>

class vec3
{
public:
    vec3() : e{0, 0, 0} {}
    vec3(double x) : e{x, x, x} {}
    vec3(double x, double y, double z) : e{x, y, z} {}

    inline double x() const { return e[0]; }
    inline double y() const { return e[1]; }
    inline double z() const { return e[2]; }

    inline double r() const { return e[0]; }
    inline double g() const { return e[1]; }
    inline double b() const { return e[2]; }

#pragma region Operator Overloading
    vec3 &operator+=(vec3 &v)
    {
        e[0] += v.x();
        e[1] += v.y();
        e[2] += v.z();
        return *this;
    }
    vec3 &operator-=(vec3 &v)
    {
        e[0] -= v.x();
        e[1] -= v.y();
        e[2] -= v.z();
        return *this;
    }
    vec3 &operator*=(double s)
    {
        e[0] *= s;
        e[1] *= s;
        e[2] *= s;
        return *this;
    }
    vec3 &operator/=(double s)
    {
        e[0] /= s;
        e[1] /= s;
        e[2] /= s;
        return *this;
    }

    double operator[](int i) const
    {
        return e[i];
    }
    double &operator[](int i)
    {
        return e[i];
    }

    vec3 operator+(vec3 v)
    {
        return vec3(x() + v.x(), y() + v.y(), z() + v.z());
    }

    vec3 operator-(vec3 v)
    {
        return vec3(x() - v.x(), y() - v.y(), z() - v.z());
    }
    vec3 operator*(double s)
    {
        return vec3(x() * s, y() * s, z() * s);
    }
    vec3 operator/(double s)
    {
        return vec3(x() / s, y() / s, z() / s);
    }

    vec3 operator+(const vec3 v) const
    {
        return vec3(x() + v.x(), y() + v.y(), z() + v.z());
    }

    vec3 operator-(const vec3 v) const
    {
        return vec3(x() - v.x(), y() - v.y(), z() - v.z());
    }
    vec3 operator*(const double s) const
    {
        return vec3(x() * s, y() * s, z() * s);
    }
    vec3 operator/(const double s) const
    {
        return vec3(x() / s, y() / s, z() / s);
    }

#pragma endregion

    double length_squared() const
    {
        return x() * x() + y() * y() + z() * z();
    }

    double length() const
    {
        return sqrt(length_squared());
    }

    vec3 normalized() 
    {
        return *this / length();
    }

    vec3 &normalize()
    {
        return *this /= length();
    }

private:
    double e[3];
};

using color = vec3;
using point = vec3;

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}