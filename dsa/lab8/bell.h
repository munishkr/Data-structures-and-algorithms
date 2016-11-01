void bellman(struct Graph * g)
{
 int vertex = g->v,i,j,dis[g->v];
 for(i=0;i<vertex;i++)
 	dis[i]=123456789;
 struct node * temp = NULL;
 dis[0]=0;
 for(i=0;i<vertex;i++)
 {
 	for(j=0;j<vertex;j++)
 	{
 		temp=g->a[j].head;
 		while(temp!=NULL)
 		{
 			if(dis[j]!=123456789 && dis[temp->dest] > dis[j]+temp->weight)
 				dis[temp->dest]=dis[j]+temp->weight;
 			temp=temp->next;
 		}
 	}
 }
 for(j=0;j<vertex;j++)//to check negative cycles
 {
 	temp=g->a[j].head;
 	while(temp!=NULL)
 	{
 		if(dis[j]!=123456789 && dis[temp->dest] > dis[j]+temp->weight)
 		{
 			printf("negative cycle");
 			return ;
 		}
 		temp=temp->next;
 	}
 }
}
