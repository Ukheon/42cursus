#include "../mlx/mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "hi hello");
	mlx_loop(mlx);
}
