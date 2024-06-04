# mandelbrot
visualizing the Mandelbrot set. requires Gnuplot to run

directions for now:
- get the appropriate view window/formula by uncommenting blocks in `mandelbrot.cpp` and `gnuplotter.gp` (I promise I will be better at this later)

- compile the code: `g++ -o mandelbrot.out mandelbrot.cpp`

- create the data file: `./mandelbrot.out`

- plot the data: `gnuplot -p gnuplotter.gp`