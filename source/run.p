set term png font arial 12 size 800,600
set output 'output.png'
set xlabel 'No. of Nodes'
set ylabel 'Time(in ms)'
p 'dijkstra.dat' u 1:2 w linespoints t 'Dijkstra','astar.dat' u 1:2 w linespoints t 'Astar'
replot



