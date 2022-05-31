#include <iostream>

#include "sphere.hpp"
#include "ray.hpp"
#include "vector.hpp"
#include "color.hpp"

color get_ray_color(ray r)
{
    using namespace Shapes;
    sphere sph = sphere(point(0, 0, -1), 0.5);
    auto sphere_hit = Sphere::ray_hit(sph, r);
    if (sphere_hit > 0.0)
    {
        vec3 N = (r.at(sphere_hit) - vec3(0, 0, -1)).normalized();
        return color(N.x() + 1, N.y() + 1, N.z() + 1) * 0.5;
    }

    vec3 dir = r.direction().normalized();
    double t = 0.5 * (dir.y() + 1.0);
    return color(1.0, 1.0, 1.0) * (1.0 - t) + color(0.5, 0.7, 1.0) * t;
}

typedef struct
{
    float width, height;
    float focal_length;
} viewport;

int main()
{
    using namespace std;

    const float ASPECT = 16.0 / 9.0;
    const int WIDTH = 300;
    const int HEIGHT = WIDTH / ASPECT;

    viewport viewport{ASPECT * 2.0, 2.0, 1.0};
    point origin = point(0.0, 0.0, 0.0);
    vec3 horizontal = vec3(viewport.width, 0.0, 0.0);
    vec3 vertical = vec3(0.0, viewport.height, 0.0);
    point lower_left_corner = origin - horizontal / 2.0 - vertical / 2.0 - vec3(0.0, 0.0, viewport.focal_length);

    cout << "P3" << endl;
    cout << WIDTH << " " << HEIGHT << endl;
    cout << "255" << endl;

    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            double u = double(i) / double(WIDTH);
            double v = double(j) / double(HEIGHT);

            ray r(origin, lower_left_corner + horizontal * u + vertical * v);
            Color::write(std::cout, get_ray_color(r));
        }
        cout << endl;
    }
}