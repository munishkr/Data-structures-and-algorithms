struct structure
{
 int wei;
 int ver;
};

void heapify(struct structure * arr,int * poss,int size,int index)
{
 int right=2*index+2,left=2*index+1,smaller=index,t;
 if(left < size && arr[left].wei < arr[smaller].wei)
 	smaller=left;
 if(right < size && arr[right].wei < arr[smaller].wei)
 	smaller=right;
 if(smaller!=index)
 {
  	struct structure temp=arr[smaller];
  	arr[smaller]=arr[index];
  	arr[index]=temp;
  	poss[smaller]=index;
  	poss[index]=smaller;
  	
  	heapify(arr,poss,size,smaller);
 }
}

void decreasekey(struct structure * arr,int * poss,int index)
{
 int parent = (index-1)/2;
 while(parent>=0)
 {
  	if(arr[parent].wei > arr[index].wei)
  	{
  		struct structure temp=arr[parent];
  		arr[parent]=arr[index];
  		arr[index]=temp;
  		poss[parent]=index;
  		poss[index]=parent;
  		index=parent;
  		parent=(index-1)/2;
  	}
  	else break;
 }
}

struct structure extract(struct structure * arr,int * poss,int size)
{
 struct structure temp = arr[0];
 arr[0]=arr[size-1];
 poss[size-1]=0;
 poss[0]=size-1;
 
 heapify(arr,poss,size-1,0);
 return temp;
}

