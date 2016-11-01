#include"g1.h"
#include"binaryheap.h"
#include"prims.h"
int main()
{
 int vertex,edges,i,src,dest,p,weight;
 printf("enter number of vertices and edges\n");
 scanf("%d %d", &vertex, &edges);

 struct Graph * g = creategraph(vertex);

 printf("enter src and dest of edge\n");
 for(i=0;i<edges;i++)
 {
 	scanf("%d %d %d", &src, &dest, &weight);
	directededge(g,src,dest,weight);
 }
 prims(g,vertex);

 return 0;
}
