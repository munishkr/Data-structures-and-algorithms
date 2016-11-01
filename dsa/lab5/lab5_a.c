#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p1, p2;
void swapPointers(int* a, int* b)
{
	int temp;

	//swap function logic

	temp = *a;
	*a = *b;
	*b = temp;
	printf("\nvalue of a and b after swapping is %d and %d ", *a, *b);
}
void printPointerValue(int* a)
{
	printf("\nvalue of a is:%d ", *a);
}

int compareInts(int* a, int* b)
{
	if ((*a) > (*b))
		return 1;
	else
		return 0;
}
int compareStrings(char *c1, char *c2 )
{
	int i;

	for (i = 0; i < strlen(c1) && strlen(c2); i++) {
		if (c1[i] > c2[i])
			return 1;
		else
			return 0;

	}
	if (i < strlen(c2))
		return 0;
	else return 1;
}
int countTillThisNum(int num)
{
	if (num == 1) {
		printf("%d \n", num );
		return 0;
	}
	countTillThisNum(num - 1 );
	printf("%d\n", num);

}

int main()
{
	int x, y, n;
	char s1[5], s2[5];

	printf("\nenter the value of a and b: ");
	scanf("%d %d", &x, &y);
	printf("\nvalue of a and b before swapping is %d and %d", x, y);
	swapPointers(&x, &y);
	printPointerValue(&x);
	printf("\nEnter string 1");
	scanf("%s", s1);
	printf("\nEnter string 2");
	scanf("%s", s2);
	compareStrings(s1, s2);
	printf("\nenter the number till which the series is to be printed");
	scanf("%d", &n);
	countTillThisNum(n);
}
