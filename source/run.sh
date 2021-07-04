#!/bin/bash
echo -n  "">dijkstra.dat
echo -n "Collecting runtime measurement Data by using Dijkstra over Graph of 5 lac+ nodes and 20 lac+ edges...."
#running dijkstra algorithm to calculate time taken by algorithm to find shortest path to various nodes
g++ dijkstra.cpp
for(( i=1; i<=300000; i+=10000 ))
do
  ./a.out $i | sed -n 2p | sed -r 's/[[:blank:]]+/,/g'   | cut -f2,4 -d ',' | tr ',' '\t' >> dijkstra.dat
done
echo "ok Completed!"
#running dijkstra algorithm to calculate time taken by algorithm to find shortest path to various nodes
echo -n  "">astar.dat
echo -n "Collecting runtime measurement Data by using Astar Algorithm over Graph of 5 lac+ nodes and 20 lac+ edges...."
g++ astar.cpp
for(( i=1; i<=300000; i+=10000 ))
do 
  ./a.out $i | sed -n 2p | sed -r 's/[[:blank:]]+/,/g'   | cut -f2,4 -d ',' | tr ',' '\t' >> astar.dat
done 
echo "ok Completed!"
echo "Plotting Curve of No.of Nodes vs Time taken to calculate shortest path by both algorithms...."
sleep 4s
#plotting Curve of no. of nodes vs time taken
gnuplot run.p
#opening output file
eog output.png
#removing files no longer needed
rm dijkstra.dat
rm astar.dat
rm output.png
