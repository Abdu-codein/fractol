










when plotting the real and fake
due to the size of the window not the same as the shape to be created
math width = max real - min real == max im - min im

mand lives on -2 to 0.5 on width naturally
just to have breathing spae, the width of box will be equal to 
0.6 - (-2) = 2.6
to match the height
mandelbrot is equal on both sides heights wise so half that number
1.3 and -1.3

ASPECT RATIO is equal to width / height

MANDEL looks best with 1.3 to -1.3 height (2.6).
real width = height total - aspect ratio 
now to set up, x.imag is always equal to -2
so -2 * the real width is = to the x.real

JULIA looks best with height -2 to 2 (4)
usign that
real width = height total - aspect ratio
because juia always stays centered, we divide the real width by 2



hoxking works by waiting for an input from the user in the back, there are 3 hooks (that are used)

keyboard;
int handle_key (int keycode, void *param)

(to be called we do), mlx_key_hook(data.win_ptr, handle_key, &data)

mouse;
int handle_mouse(int button, int x, int y, void *param);

(to be called we do), mlx_mouse_hook(data.win_ptr, handle_mouse, &data)

X button;
int handle_close(void*param);

(to be called we do), mlx_hook(data.win_ptr, 17, 0, handle_close, &data)