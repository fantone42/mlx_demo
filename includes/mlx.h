#ifndef		MLX_H
# define	MLX_H

void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int		mlx_loop (void *mlx_ptr);
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif /* MLX_H */
