#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/resource.h>
#include <time.h>
double** mainmatrix(int n, float beta)
{
	double upper_diagonal[n];
	double lower_diagonal[n];
	double main_diagonal[n];
	double right_vector[n];

	double val = (n-1)*(n-1);

	int i, j;

	for (i = 0; i < n; i++) {
		upper_diagonal[i] = val;
		lower_diagonal[i] = val;
		main_diagonal[i] = -2 * val - beta;
		if (i == 0)
			right_vector[i] = val;
		else
			right_vector[i] = 0;
	}
	double **arr = (double**)malloc(n * sizeof(double *));
	for (i = 0; i < n; i++)
		arr[i] = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j)
				arr[i][j] = main_diagonal[i];
			else if ((i < j) && ((j - i) == 1))
				arr[i][j] = upper_diagonal[i];
			else if ((i > j) && ((i - j) == 1))
				arr[i][j] = lower_diagonal[i];
			else
				arr[i][j] = 0;
		}
	}
	arr[0][1]=0;
	arr[0][0]=1;
	arr[n-1][n-1]=1;
	arr[n-1][n-2]=-1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%lf \t", arr[i][j]);
		printf("\n");
	}

	int k;
	double c, x[n], sum = 0.0;



	for(j=0; j<n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=0; i<n; i++)
        {
            if(i>j)
            {
                c=arr[i][j]/arr[j][j];
                for(k=0; k<=n; k++)
                {
                    arr[i][k]=arr[i][k]-c*arr[j][k];
                }
            }
        }
    }
    x[n-1]=arr[n-1][n]/arr[n-1][n-1];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=0; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+arr[i][j]*x[j];
        }
        x[i]= (arr[i][n+1]-sum)/arr[i][i];
    }

	double t_exact[n];
	double e = 0.0;
	for (i = 0; i < n; i++)
		t_exact[i] = cosh((double)sqrt(beta) * (1 - ((double)i / (double)n))) / cosh((double)sqrt(beta));

	//error analysis
	for (i = 1; i <= n; i++)
		e += sqrt((t_exact[i] - x[i]) * (t_exact[i] - x[i]) / n);

	//writing to FILE
	FILE *fp;
	fp = fopen("results.dat", "w");
	for (i = 1; i <= n; i++) {
		fprintf(fp, "%d\t%lf\t%lf", i, t_exact[i], x[i]);
		fprintf(fp, "\n");
	}
	printf("\n%lf is the error in calculation ", e);
	fclose(fp);

	//graph plotting
	FILE *gnuplotPipe;
	char *commandsForGnuplot[] = { "set title \"analytical  vs  actual\"", "set xrange[0.01:10.000]", "set yrange[0.00001:1.000]", "plot 'result.dat' with lines" };

	gnuplotPipe = popen("gnuplot -persistent", "w");
	for (i = 0; i < 4; i++)
		fprintf(gnuplotPipe, "%s\n", commandsForGnuplot[i]);
	return 0;
}



int main()
{
	int N;
	float Beta;
	struct rusage r_usage;
	double t = clock();

	printf("Enter the value of N (the number of discrete points) ");
	scanf("%d", &N );
	printf("Enter the value of beta");
	scanf("%f", &Beta);
	mainmatrix(N, Beta);
	t = clock() - t;
	t = t / CLOCKS_PER_SEC;
	printf("\ntime taken for execution :%f ms\n", t);
	getrusage(RUSAGE_SELF, &r_usage);
	printf("Memory usage: %ld bytes\n", r_usage.ru_maxrss);
}
