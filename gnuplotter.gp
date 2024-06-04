# to plot:
    # ~$ gnuplot
    # gnuplot> load 'gnuplotter.gp' 

# or in one go:
    # ~$ gnuplot -p gnuplotter.gp

# set title "The Mandelbrot Set"
set title "The Burning Ship Fractal"

set xlabel "Real"
set ylabel "Imaginary"
set terminal png size 4096, 4096

# BASIC PLOT
# set output "pics/mandelbrot.png"
# plot 'mandelPlot.dat' with dots lc rgb "black" notitle

# BASIC 3D PLOT B&W
# set output "pics/mandelbrot3D.png"
# splot 'mandelPlot.dat' with dots lc rgb "black" notitle

# COLOR PLOTS
set cblabel "Iterations"
set view map
set dgrid3d

# set output "pics/mandelbrotColor.png" # MAIN
# set xrange [-2:0.55]
# set yrange [-1.2:1.2]

# set output "pics/mandelbrot5Bulb.png" # 5-BULB
# set xrange [-0.66:-0.4]
# set yrange [0.45:0.7]

# set output "pics/mandelbrot5BulbSimilar.png" # FURTHER 5-BULB ZOOM
# set xrange [-0.604:-0.592]
# set yrange [0.658:0.668]

# set output "pics/mandelbrotSeahorses.png" # SEAHORSE VALLEY
# set xrange [-0.8:-0.76]
# set yrange [0.13:0.17]

# set output "pics/mandelbrotElephants.png" # ELEPHANT VALLEY
# set xrange [0.35:0.39]
# set yrange [0.075:0.115]

# set output "pics/mandelbrotSatellite.png" # ANTENNA SATELLITE (really crunchy quality for some reason?)
# set xrange [-1.79:-1.74]
# set yrange [-0.03:0.03]

# set output "pics/burningShipColor.png" # MAIN SHIP (top 1/3 cut off for some reason?)
# set xrange [-2:0.75]
# set yrange [-0.75:1.5]

set output "pics/burningShipSatellite1.png" # 2ND SHIP
set xrange [-1.8:-1.7]
set yrange [-0.015:0.09]

unset colorbox
# plot 'mandelPlot.dat' with image notitle
plot 'shipPlot.dat' with image notitle