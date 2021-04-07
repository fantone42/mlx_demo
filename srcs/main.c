#include "minirt.h"

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars 
{
    void    *mlx;
    void    *win;
}               t_vars;

int             close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int             key_hook(int keycode, t_vars *vars)
{
    // void    *vars;
    
    // printf("Hello from key_hook! %d\n", keycode);
    if (keycode == 53)
        close_window(vars);
    return (0);
}

void           my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
    t_vars vars;
    t_data  img;

    int x = -1;
    int y = -1;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "window");
    img.img = mlx_new_image(vars.mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // mlx_pixel_put(mlx, window, 800, 600, 255);
    while (y++ < 20)
    {
        // printf("y = %d\n", y);
        x = -1;
        while (x++ < 20)
        {
            // printf("x = %d\n", x);
            // mlx_pixel_put(vars.mlx, vars.win, x, y, create_trgb(0, 255, 0, 255));
            my_mlx_pixel_put(&img, x, y, create_trgb(0, 255, 0, 255));
        }
    }
    // printf("keycode = %d", keycode);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<17, close_window, &vars);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_loop(vars.mlx);
    return (0);
}