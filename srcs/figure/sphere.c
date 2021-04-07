#include "minirt.h"

t_sphere    *new_sphere(float radius, t_vector *center)
{
    t_sphere    *sphere;
    
    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        error_exit(-1);
    sphere->center = center;
    sphere->radius = radius;
	return (sphere); 
}