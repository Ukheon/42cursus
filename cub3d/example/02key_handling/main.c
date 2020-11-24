#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

//Only param->x will be used.
void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)//Action when W key pressed
		param->x++;
	else if (keycode == KEY_S) //Action when S key pressed
		param->x--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int main()
{
		void *mlx;
		void *win;
		void *img;
		t_param		param;
		int		img_width;
		int 	img_height;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		img = mlx_xpm_file_to_image(mlx, "../textures/wall_n.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, win, img, 50, 50);
		mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
		param_init(&param);
		mlx_loop(mlx);
		return (0);
}
