#include "../mlx/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}               t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}
int close_window(t_mlx_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
}

int main(void)
{
    t_mlx_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1500, 1500, "My Window");

    mlx_key_hook(data.win_ptr, handle_input, &data);
    mlx_hook(data.win_ptr, 17,0, close_window,&data);
    mlx_loop(data.mlx_ptr);
}