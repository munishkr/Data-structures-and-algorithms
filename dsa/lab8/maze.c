#include"g1.h"
#include"binaryheap.h"
#include"dij.h"
int main()
{
 int vertex,edges,src,dest,weight,i,start,goal;
 printf("enter number of vertices and edges\n");
 scanf("%d %d", &vertex, &edges);
 
 int matrix[vertex][vertex];
 for(i=0;i<vertex;i++)
 {
 	for(int j=0;j<vertex;j++)
 		matrix[i][j]=0;
 }
 struct Graph * g = creategraph(vertex);
 
 for(i=0;i<edges;i++)
 {
  scanf("%d %d %d", &src, &dest, &weight);
  directededge(g,src,dest,weight);
  matrix[src][dest]=weight;
 }


 printf("enter start and final vertex\n");
 scanf("%d %d", &start, &goal);
 
 dijksta(g,start,goal);
 return 0;
}
