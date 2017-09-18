#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct pepl{
    char name[9];
    int age, worth;
} PEPL;
int cmp(const void *a, const void *b)
{
    PEPL *x = (PEPL*)a, *y = (PEPL*)b;
    return x->worth == y->worth ? (x->age == y->age ? strcmp(x->name, y->name) : x->age - y->age) : y->worth - x->worth;
}
int main()
{
	int n, m, i, j, k, x, y, z;
    scanf("%d%d", &n, &m);
    PEPL p[n];
    for(i=0; i<n; i++)
    {
        scanf("%s%d%d", p[i].name, &p[i].age, &p[i].worth);
    }
    qsort(p, n, sizeof(PEPL), cmp);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d", &z, &x, &y);
        printf("Case #%d:\n", i);
        k = 0;
        for(j=0; j<n&&k<z; j++)
        {
            if(p[j].age >= x && p[j].age <= y)
            {
                printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
                k++;
            }
        }
        if(k == 0)
        {
            puts("None");
        }
    }
	return 0;
}