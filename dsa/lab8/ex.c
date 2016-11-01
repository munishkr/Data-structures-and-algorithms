#include"g1.h"
#include"krushkals.h"

int main()
{
 int vertex,edges,src,dest,weight,i;
 printf("enter number of vertices and edges\n");
 scanf("%d %d", &vertex, &edges);

 struct edge pintu[edges];

 struct Graph * g = creategraph(vertex);

 for(i=0;i<edges;i++)
 {
  scanf("%d %d %d", &src, &dest, &weight);
  undirectededge(g,src,dest,weight);
  pintu[i].src=src;
  pintu[i].dest=dest;
  pintu[i].weight=weight;
 }
 krushu(pintu,edges,vertex);
 return 0;
}
