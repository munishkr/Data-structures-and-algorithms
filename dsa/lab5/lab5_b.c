#include <stdio.h>
#include <stdlib.h>





//function returns a 2d matrix initalized by random integers
int** maker(int n, int m)
{

	int i, j;
	int **d = (int**)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++)
		d[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d\t", d + j);
			d[i][j] = d + j;
		}
		printf("\n");
	}
	d = realloc(d, n * m);

	return d;
}

//function writes the matrix to file
void writer(int **d, int n, int m, char* filename)
{
	int i, j;
	FILE* fp;

	fp = fopen(filename, "w");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			fprintf(fp, "%d\t", d[i][j] );
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void printDelete(int **d, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d\t", d[i][j]);
		printf("\n");
	}
	free(d);
}

//main driver function
int main()
{
	int rows, cols;
	int **a;
	char file[20];

	printf("enter the number of rows and columns:");
	scanf("%d %d", &rows, &cols);
	a = maker(rows, cols);
	printf("\nenter the file name:");
	scanf("%s", file);
	printf("//////////writing the above matrix into the file///////////\n");
	writer(a, rows, cols, file);
	printf("\nDONE\n\n");
	printf("//////////Printing and freeing the matrix pointer/////////\n");
	printDelete(a, rows, cols);
}
