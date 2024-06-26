# the Mandelbrot fractal
visualizing the Mandelbrot set. requires Gnuplot to run

### directions for now:

- get the appropriate view window/formula by uncommenting blocks in `mandelbrot.cpp` and `gnuplotter.gp` (I promise I will be better at this later)

- compile the code: `g++ -o mandelbrot.out mandelbrot.cpp`

- create the data file: `./mandelbrot.out`

- plot the data: `gnuplot -p gnuplotter.gp`

most of the color images (4k resolution, 128 iterations) take around 400-800 million computations to generate! (can definitely be optimized, though)

### basic Mandelbrot plot

similar to the original 1978 dot-matrix printout, just with higher resolution

![basicMandelbrot](pics/mandelbrot.jpeg)

### 2D Mandelbrot plot

higher res than the previous

![2dMandelbrot](pics/mandelbrot.png)

### 3D Mandelbrot plot

where height represents number of iterations

![3dMandelbrot](pics/mandelbrot3D.png)

### color Mandelbrot plot

where color represents number of iterations

![colorMandelbrot](pics/mandelbrotColor.png)

### Mandelbrot 5-bulb

zooming in to one of the bulbs on the main cardioid

![mandelbrotZoom5Bulb](pics/mandelbrot5Bulb.png)

### Mandelbrot 5-bulb further zoom

further zoom-in of previous; shows some self-similarity 

![mandelbrotZoom5BulbSimilar](pics/mandelbrot5BulbSimilar.png)

### Mandelbrot seahorses

located between the main cardioid and main bulb

![mandelbrotSea](pics/mandelbrotSeahorses.png)

### Mandelbrot elephants

located in the valley of the main cardioid

![mandelbrotEleph](pics/mandelbrotElephants.png)

### burning ship fractal

made by taking the absolute values of the components of z before squaring. *fractal has been flipped vertically for aesthetic purposes; scale is inaccurate - the numbers on the y-axis should be the negative of what is displayed

![burningShipMain](pics/burningShipColor.png)

### burning ship satellite

zoom in to the second-largest ship, found near the tail of the largest. very pretty & one of my favorites

![burningShipSat](pics/burningShipSatellite1.png)