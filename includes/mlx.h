#ifndef		MLX_H
# define	MLX_H

typedef struct  s_param {
    void        *mlx;
    void        *window;
}               t_param;

void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
void	*mlx_new_image(void *mlx_ptr,int width,int height);
int     mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

int		mlx_loop (void *mlx_ptr);
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

//hooks
int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
#endif /* MLX_H */
