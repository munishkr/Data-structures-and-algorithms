void dijksta(struct Graph *t,int src,int goal)
{
 int vertex=t->v,i;//intializing no of vertices
 int poss[vertex],size=vertex,parent[vertex];
 struct structure arr[vertex],po;
 for(i=0;i<vertex;i++)
 {
 	arr[i].wei=78913245;
 	arr[i].ver=i;
        poss[i]=i;
        parent[i]=-1;
 }
 arr[src].wei = 0;
 struct node * crawl=NULL;
 while (size-1)
 {
        po = extract(arr,poss,size);
        size--;
        crawl=t->a[po.ver].head;
        while (crawl!=NULL)
        {
            if((poss[crawl->dest] < size) && (po.wei!=78913245) && (crawl->weight + po.wei < arr[poss[crawl->dest]].wei))
            {
                arr[poss[crawl->dest]].wei=po.wei+crawl->weight;
                parent[crawl->dest]=po.ver;
                decreasekey(arr,poss,crawl->dest);
            }
            crawl=crawl->next;
        }
 }
 printf("%d ",arr[poss[goal]].wei);
 int trace = goal;
 while(parent[trace]!=-1)
 {
  	printf("%d ",parent[trace]);
  	trace = parent[trace];
 }
}
