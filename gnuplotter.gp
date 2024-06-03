# to plot:
# ~$ gnuplot
# gnuplot> load 'gnuplotter.gp' 

# or in one go:
# ~$ gnuplot -p gnuplotter.gp

set title "The Mandelbrot Set"
set xlabel "Real"
set ylabel "Imaginary"
set xrange [-2:0.75]
set yrange [-1.25:1.25]
# set term x11 
#  set size 1200, 1200

plot 'mandelPlot.dat' with dot