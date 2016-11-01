int rem=0,pre=0;

void dfsrec(struct stack * s,int * flag,struct Graph * g,int *last,int *first)
{
 struct node * temp = NULL;
 temp = g->a[peek(s)].head;
 while(temp!=NULL)
 {
	if(flag[temp->dest] == 0)
	{
	 	 push(temp->dest,s);
	 	 first[pre]=temp->dest;
	 	 pre=pre+1;
	   	 flag[temp->dest]=1;
	   	 dfsrec(s,flag,g,last,first);
	}
   	temp=temp->next;
 }
 last[rem]=pop(s);
 rem=rem+1;
}

void dfs(struct Graph * g)
{
 int vertex = g->v,i;
 int flag[vertex],last[vertex],first[vertex];
 for(i=0;i<vertex;i++)
 {
 	last[i]=0;
 	first[i]=0;
 	flag[i]=0;
 }
 struct stack * s = create();
 for(i=0;i<vertex;i++)
 {
 	if(flag[i] == 0)
 	{
 		push(i,s);
 		flag[i]=1;
 		first[pre]=i;
 		pre=pre+1;
 		dfsrec(s,flag,g,last,first);
 	}
 }
}
