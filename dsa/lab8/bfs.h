int bfs(struct Graph * g,int src,int des)
{
 int b,arr[g->v];
 for(int i=0;i<g->v;i++)
 	arr[i]=0;
 struct node * faltu =NULL;
 struct queue * m =createqueue();

 enqueue(m,src);
 arr[src]=1;

 while(!isempty(m))
 {
 	b=dequeue(m);
 	arr[b]=2;
 	faltu =g->a[b].head;
 	while(faltu!=NULL)
 	{
 		if(arr[faltu->dest] == 0)
 		{
 			enqueue(m,faltu->dest);
 			arr[faltu->dest]=1;
 			if(faltu->dest == des)
 				return 1;
 		}
 		faltu=faltu->next;
 	}
 }
 return 0;
}
