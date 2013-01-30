set terminal postscript eps color "Times-Roman" 14
set output "resultat4array.eps"
set key right bottom
set xlabel "n"
set ylabel "coût amorti (µs)"
# set logscale x 10
# set logscale y 10
set xrange [0:]
set yrange [0:]
plot "resultat_array30.txt" using ($1):($3) with linespoints title "stack (30)", \
     "resultat_array100.txt" using ($1):($3) with linespoints title "stack (100)", \
     "resultat_array1000.txt" using ($1):($3) with linespoints title "stack (1000)", \
     "resultat_array2x.txt" using ($1):($3) with linespoints title "stack (*2)"
