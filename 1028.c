#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct record{
	int id;
	char name[9];
	short grade;
} RECORD;
int cmp1(const void *a, const void *b)
{
	return ((RECORD*)a)->id - ((RECORD*)b)->id;
}
int cmp2(const void *a, const void *b)
{
	RECORD *x = (RECORD*)a, *y = (RECORD*)b;
	int s = strcmp(x->name, y->name);
	return s == 0 ? x->id - y->id : s;
}
int cmp3(const void *a, const void *b)
{
	RECORD *x = (RECORD*)a, *y = (RECORD*)b;
	return x->grade == y->grade ? x->id - y->id : x->grade - y->grade;
}
int main()
{
	int n, c, i, x;
	scanf("%d%d", &n, &c);
	RECORD r[n];
	for(i=0; i<n; i++)
	{
		scanf("%d%s%d", &r[i].id, r[i].name, &x);
		r[i].grade = x;
	}
	switch(c)
	{
		case 1:
			qsort(r, n, sizeof(r[0]), cmp1);
			break;
		case 2:
			qsort(r, n, sizeof(r[0]), cmp2);
			break;
		default:
			qsort(r, n, sizeof(r[0]), cmp3);
			break;
	}
	for(i=0; i<n; i++)
	{
		printf("%06d %s %d\n", r[i].id, r[i].name, r[i].grade);
	}
	return 0;
}