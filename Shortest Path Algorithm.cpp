/*Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.
Generate a shortest path tree with the given source as the root. Maintain 2 sets, one which contains vertices visited and the ither which contains the vertices yet to be visited. At every step we find a vertex that is in the other set(not included set) which is at the minimum distance from the source.

Step1: create a set sptSet, that keeps the track of vertices included in the shortest path set. Initially this set is empty.
Step2: assign distance value to all vertices in the input graph. initialise all the distances as infinity. assign distance value as zero for the source vertex, so that it is picked first.
Step3: pick a vertex 'u' from the other set with the lowest distance value and which is not in the sptSet and include it in sptSet. Update distance value of all the vertices adjacent to 'u'. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if the sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v*/ 

#include <iostream>
using namespace std;
#include <limits.h>

#define V 9 //number of vertices in the graph

int minDist(int dist[], bool sptSet[]){     // utility function to find point with the minimum distance
int min=INT_MAX, min_index;
for(int v=0; v<V; v++){
    if(sptSet[v]==false && dist[v]<=min)
    min=dist[v], min_index=v;
    return min_index}}

void printAnswer(int dist[]){               //utility function to print the solution.

}