#ifndef SPHERE_H
# define SPHERE_H

typedef struct  s_sphere
{
    float       radius;
    t_vector    *center;
}               t_sphere;

t_sphere    *new_sphere(float radius, t_vector *center);

#endif