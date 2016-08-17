#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
 
int main(int argc,char *argv[])	{
	FILE *fp;
	int i,j,th,temp;
	int r,c;
	float sumtotal=0;
	/*selecting the file to be printed*/ 
	fp=fopen(argv[1],"r");
		if(strcmp(argv[1],"1.txt")){
		r=198;c=200;
		}
	else if(strcmp(argv[1],"2.txt"))
		{r=1200;c=1920;}
	else if(strcmp(argv[1],"3.txt"))
		{r=10967;c=10004;}
	//time calculation
	double t=clock();
	///////////////////////////////////////////////////////////*dynamic memory allocation partA of ques*///////////////////////////////////////
	int **array;
	array=(int **)malloc(r*sizeof(int *));
	for(i=0;i<r;i++){
		array[i]=(int *)malloc(c*sizeof(int));
		}
		int histo[256]={0};
		i=0;j=0;
	while(fscanf(fp,"%d",&temp)==1)
	{
		for(;j<c;j++)
		{
			array[i][j]==temp;
			if(j==c)
			{
				i++;j=0;
			}
			break;
		}
		histo[temp]++;
		sumtotal+=temp;
	}
	t=clock()-t;
	t=t/CLOCKS_PER_SEC;
	printf("time taken for accessing the file :%f ms\n",t);
	///////////////////////////////////////////////////////////*clusterising the data*///////////////////////////////////////////////////////
	t=clock();
	float cfreq[256]={0};
	float cumul=0;
	float freq[256]={0};
	long double meanA[256]={0} ,meanB[256]={0};
	cfreq[0]=histo[0];
	for(i=1;i<256;i++){
		cfreq[i]=cfreq[i-1]+histo[i];
	}
	t=clock()-t;
	t=t/CLOCKS_PER_SEC;
	printf("time taken for thresholding :%f ms\n",t);
	//////////////////////////////////////////////////////////*mean of clucter a nd cluster b*////////////////////////////////////////////////
	for(i=0;i<256;i++){
		meanA[i]=0;
		for(j=0;j<=i;j++){
			meanA[i]+=histo[j]*j;
		}
		meanB[i]=sumtotal-meanA[i];
		meanA[i]=meanA[i]/cfreq[i];
		meanB[i]=meanB[i]/((r*c)-cfreq[i]);
	}
	//////////////////////////////////////////////////////////*standard deviation of cluster A and B*////////////////////////////////////////
	double sdA[256]={0},sdB[256]={0};

	for(i=0;i<256;i++){
		sdA[i]+=sqrt(histo[i]*(i-meanA[i]))*(histo[i]*(i-meanA[i]));
		sdB[i]+=sqrt(histo[i]*(i-meanB[i]))*(histo[i]*(i-meanB[i]));
		sdA[i]=sdA[i]/cfreq[i];
		sdB[i]=sdB[i]/cfreq[i];
	}
	///////////////////////////////////////////////////////////*discriminative index*////////////////////////////////////////////////////////
	double disindex[256]={0};
	for(i=0;i<256;i++){
		disindex[i]=meanA[i]-meanB[i]/sqrt((sdA[i]*sdA[i])+(sdB[i]*sdB[i]));
	}
	///////////////////////////////////////////////////////////*nratio calculation*//////////////////////////////////////////////////////////
	double nratio[256]={0};
	for(i=0;i<256;i++){
		nratio[i]=cfreq[i]/((r*c)-cfreq[i]);
	}
		printf("\n");
		FILE *fd,*fd1,*fd2;
		fd=fopen("result.dat","w");
		fd1=fopen("result1.dat","w");
		fd2=fopen("result2.dat","w");
		for(i=0;i<256;i++){
		fprintf(fd,"%d      %lf      %lf\n",i,disindex[i],nratio[i]);
		fprintf(fd1,"%d      %lf\n",i,nratio[i]);
		fprintf(fd2,"%lf      %lf\n",disindex[i],nratio[i]);
		}
		fclose(fd);
	////////////////////////////////////////////////////////////*GNU plot*//////////////////////////////////////////////////////////////////
	char *commandsForGnuplot[] = {"set title \"Threshold vs DiscriminativeIndex\"", "set xrange[0:254]", "set yrange[0:90]", "plot 'result.dat' with lines"};
    char *commandsForGnuplot1[] = {"set title \"Threshold vs nratio\"", "set xrange[0:254]", "set yrange[0:1]", "plot 'result1.dat' with lines"};
    char *commandsForGnuplot2[] = {"set title \"discriminative index vs nratio\"", "set xrange[0:254]", "set yrange[0:1]", "plot 'result2.dat' with lines"};
    
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    for(i=0;i<4;i++)
    {
        fprintf(gnuplotPipe, "%s\n", commandsForGnuplot[i]);
        fprintf(gnuplotPipe, "%s\n", commandsForGnuplot1[i]);
        fprintf(gnuplotPipe, "%s\n", commandsForGnuplot2[i]);
     }

	////////////////////////////////////////////////partB///////////////////////////////////////////////////////
		FILE* fp2 = fopen("1.txt","r");
		int array1[198][200];
		for(i=0;i<198;i++){
			for(j=0;j<200;j++){
				fscanf(fp2,"%d ",&array1[i][j]);
			}
		}
		/////////////////////////////////////*clustering*/////////////////////////////////////////////////////////
		int k;double cA=0,cB=0;
		for(i=0;i<256;i++){
			for(j=0;j<198;j++){
				for(k=0;k<200;k++){
					if(array1[j][k]<=i)
					{cA++;}
					else
					{cB++;}
				}
			}
		}	
		///////////////////////////////////*mean*/////////////////////////////////////////////////////////////////
		double mean_a=0,mean_b=0;
		t=clock();
		for(k=0;k<256;k++){
		for(i=0;i<198;i++){
			for(j=0;j<200;j++){
				if(array1[i][j]<=k)
					mean_a+=array1[i][j];
				else
					mean_b+=array1[i][j];
			}
		}
		mean_a=mean_a/cA;
		mean_b=mean_b/cB;
		}
		t=clock()-t;
		t=t/CLOCKS_PER_SEC;
		printf("time taken for accessing the file :%f ms\n",t);
		printf("mean_a %lf",mean_a);
		fclose(fp);
		fclose(fp2);
}		


