*This project has been created as part of the 42 curriculum by <*amardini*>*

# FRACT_OL
Definition: In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension. Many fractals appear similar at various scales, as illustrated in successive magnifications of the Mandelbrot set.

In simplier words, a fractal is a shape that repeats endlessly as long as zoomed into the edges (in this project case, in two dimensional).


## Description:
This version of the project was done with the bonus, including 3 versions of a fractal shape, "Mandelbrot", "Julia", and "Burning ship".

#### Fractal shapes:
For this project, the base of the fractal math for all 3 shapes is `z = a + bi` where i is an imaginary number of `square root of -1`.

In other words, `iterationX = z * z + y` with y being `(a^2 - b^2) + 2abi`.

Using this formula, we can find out the location of plotting for each point, as long as the above calculation doesn't "explode", (aka the output of the formula doesn't go past whatever boundries we have (in this code it being 4, (-2 to 2))).

#### Mandelbrot:
Mandelbrot has the best dimensions when the Y axis is the size of 2.6 (1.3 to -1.3) with the X axis being started at -2 and ends at the size to match the size of 2.6.

The mathmetical coordinations coor_x and coor_y are used to find the location on the graph for plotting the coordinate with the colour that comes from the iteration.

#### Julia:
Julia has the best dimensions when it is a perfect square (4), allowing the max and min for both imaginary and real to stay constant on -2 to 2.

zr and zi are the coord_x and coord_y, while the user added to this fractal is used as the constant, allowing different designs to occur, while the coordinations making i set the mathmetical location on the graph to find the colour and iterations.

#### Burning ship:
Burning Ship has the same idea as Mandelbrot for dimensions, as the best size for it is also 2.6.

zr and zi is set as the absolute value of themselves, allowing the design to be created. Due to the burning ship creation being upside down, `2abi` becomes `-2abi`.

##### Additional information regarding all shapes:
- A ratio is also found using the dimensions added by the user, allowing the size to look correct regardless to whatever the new inputted dimensions are.

- Coor X and Y is the mathematical graph location for that specific pixel, using the actual x/y pixel location as a base line and then finding the ratio between them, to find the exact location to plot on the graph.

### Outline of how code runs
1. The user inputs the fractol they are interested in, either 1 input (for mandelbrot and burning ship) or 3 (for julia).

2. It gets checked if what is inputted matches the "required" input text(s), if it matches, the design is set as the required one with all of the information it needs for it to function.
    - In regards to julia tho, an additional check is done for the inputted number to check if it is a valid number and can be turned into a float.

3. The Minilibx is set up after, witha a fail safe at each level incase any issue occurs, freeing and cleaning anything that was set up already.
    - Init connects to a surverm which later is used to create the window that appears to the user, afterwards a new_image is set for the pixels to "draw" on, ending with the address being set and populating information regarding the system, and the initialised window.

4. Max iterations is set, and the colour effect is se for the shapes to be initialised and created.

5. Create shape works pixel by pixel, by using the counters set as the dimensions as borders. Each pixel is set by first finding the iteration (setting up coord_x and coord_y (using to find the location in math then connecting it to it's position of the computer), and depending on the shape, it calls the correct fucntion to help decide if a plot is needed to be added or how far it was from the actual shape) which is then used to decide the colour and actually plot it in it's correct location on the computer grid (with the correct colour depending on what the user sets as the required).
    - After all that is completed for all of the pixels that are set by the window dimensions, the image set will be pushed to the window to be visible to the user.

6. Hooks are set next to allow mouse and keyboard inputs to be recorded and be a catalyst for an effect.

7. Keyboard hooks are set up first;
    - If `arrow keys` are pressed, the move function is called, finding the real total size (set up by the computer) then setting up how much to move when pressed, then using that to define how it moves (for example if the right key is pressed, to keep the size correctly, adding to the right side means you have to decrease form the left side too).
    - If `+` or `-` is pressed, the max iteration amount is increased/decreased by 5
    - If `x` or `z` is pressed, the zooming effects functions works, by finding the centre of the actual math dimensions, then using the centre, it checks for the right of it, then the left of it, and depending on the times, it finds out what it is, this allows it to correctly set the the min/max real/imaginary locations
    - If `r`, `g`, `b`, `p` is used, then the colour is set as the code for that specific colour.
    - If `Esc` is pressed, then the code cleans everything and exits ending the code.

With all of the above, after it is pressed, the effect is applied by recreating the shape by calling the same function used previously to create the image (point 5).

8. Mouse hooks are set up after;
    - If `right click` or `left click` is pressed, then the max iteration is increased by 5.
    - If `scroll up` or `scroll down` is used, then the zooming function is used. the main difference between this one and the keyboard version is instead of using the centre of the screen as the middle, it uses the position of the mouse as the centre "of the screen", and uses the same concept again to run.

Once again, after all this, the shape is replotted (concept of point 5).

9. A hook is added to check for if the X button on the top right of the screen is pressed, allowing a safe exit from the project.

10. Finally, mlx_loop is called, allowing for the system to "listen" to user inputs, and call the correct function from the above hooks to work and give out their response.


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
