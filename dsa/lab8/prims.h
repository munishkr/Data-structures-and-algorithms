void prims(struct Graph * g,int vertex)
{
 int parent[vertex],flag[vertex],i,size=vertex,v,poss[vertex],p,sum=0;
 struct structure arr[vertex],t;
 for(i=0;i<vertex;i++)
 {
 	flag[i]=0;
 	arr[i].wei=123456789;
 	arr[i].ver=i;
 	poss[i]=i;
 }
 arr[0].wei=0;
 while(size)
 {
  	t=extract(arr,poss,size);
  	v=t.ver;
  	sum=sum+t.wei;
  	flag[v]=1;
  	--size;
  	struct node * crawl = g->a[v].head;
  	while(crawl!=NULL)
  	{
  		p=poss[crawl->dest];
  		if(flag[crawl->dest] == 0 && crawl->weight < arr[p].wei)
  		{
  			parent[crawl->dest]=v;
  			arr[p].wei=crawl->weight;
  			decreasekey(arr,poss,p);
  		}
  		crawl=crawl->next;
  	}
 }
 printf(" %d ",sum);
 for(i=0;i<vertex;i++)
 	printf("  %d ",parent[i]);
}
