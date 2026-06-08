*This project has been created as part of the 42 curriculum by <*amardini*>*

# FRACT_OL
Difinition: In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension. Many fractals appear similar at various scales, as illustrated in successive magnifications of the Mandelbrot set.

In simplier words, a fractal is a shape that repeats endlessly as long as zoomed into the edges (in this project case, in two dimensional).




## Description:
This version of the project was done with the bonus, including 3 versions of a fractal shape, "Mandelbrot", "Julia", and "Burning ship".

### Fractal shapes:


### Outline of how code runs

### Additional information




## Instructions:
#### Compiling code:
- Before running code, Minilibx-linux.tgz has to be installed and added to the "Fract_ol" file (can be found on the project page and evaluation page).
    -   the makefile in this project can automatically converts the added code into useable functions.
> there is a chance permissions will be denied, to set;
```
chmod -R +x minilibx-linux
```
- then write `make all && make clean` to produce the fractol.a file.

#### Running Code:
###### 3 main inputs exist in this code:
1. For creating the Mandelbrot image;
> ./fractol mandelbrot

2. For creating the Julia image;
> ./fractol julia X Y
>> Where X & Y should be between 2.0 and -2.0.

3. For creating the Burning_ship image;
> ./fractol burning_ship

###### To manipulate the images:
1. To zoom into the middle `x` or to zoom towards the mouse pointer `scroll wheel up`.

2. To zoom out from the middle `z` or zoom relative to the mouse pointer `scroll wheel down`.

3. To move around `arrow keys`.

4. To increase iterations `+` or `left mouse click`.

5. To decrease iterations `-` or `right mouse click`.

6. To change colour effect
    - Red: `r`.
    - Blue: `b`.
    - Green: `g`.
    - psychedelic `p`.



## Resources:

- Wikipidia
    - Fractal ([Fractal page](https://en.wikipedia.org/wiki/Fractal))
    - Mandelbrot ([Mandelbrot page](https://en.wikipedia.org/wiki/Mandelbrot_set))
    - Julia ([Julia page](https://en.wikipedia.org/wiki/Julia_set))
    
- Google Gemini
    - Further explinations of new concepts.
    - Resource gathering, and information gathering.
    - Basic tests and code cleaning.

- 42 students
    - Initial explination of project.
    - help in parts of the code.

- Youtube
    - Understanding of fractals
    - Understanding of minilibX

- MiniLibx Concepts
    - Lib introduction and basics ([42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html))
    - specific events and hooks ([Tronche](https://tronche.com/gui/x/xlib/events/))

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