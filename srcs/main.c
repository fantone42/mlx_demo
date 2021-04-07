#include "minirt.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

int main(void)
{
    void    *mlx;
    void    *window;
    t_data  img;

    int x = 100;
    int y = 100;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "window");
    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //mlx_pixel_put(mlx, window, 800, 600, 255);
    while (y++ < 200)
    {
        x = 100;
        while (x++ < 200)
            mlx_pixel_put(mlx, window, x, y, 0x0000FFFF);
    }
    //mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}