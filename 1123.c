#include<stdio.h>
#include<malloc.h>
static short max(short a, short b)
{
    return a > b ? a : b;
}
typedef struct node {
    int val;
    struct node *l, *r;
} NODE;
NODE* L(NODE* root)
{
    NODE* a = root->r;
    root->r = a->l;
    a->l = root;
    return a;
}
NODE* R(NODE* root)
{
    NODE* a = root->l;
    root->l = a->r;
    a->r = root;
    return a;
}
NODE* LR(NODE* root)
{
    root->l = L(root->l);
    return R(root);
}
NODE* RL(NODE* root)
{
    root->r = R(root->r);
    return L(root);
}
short getHeight(NODE* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max(getHeight(root->l), getHeight(root->r)) + 1;
}
NODE* insert(int val, NODE* root)
{
    if(root == NULL)
    {
        root = (NODE*)malloc(sizeof(NODE));
        root->r = root->l = NULL;
        root->val = val;
    }
    else if(val < root->val)
    {
        root->l = insert(val, root->l);
        if(getHeight(root->l) - getHeight(root->r) == 2)
        {
            root = val < root->l->val ? R(root) : LR(root);
        }
    }
    else
    {
        root->r = insert(val, root->r);
        if(getHeight(root->r) - getHeight(root->l) == 2)
        {
            root = val > root->r->val ? L(root) : RL(root);
        }
    }
    return root;
}
void free1(NODE* a)
{
    if(a == NULL)
    {
        return;
    }
    free1(a->l);
    free1(a->r);
    free(a);
}
int main()
{
    short n, i, j = 0;
    int x;
    scanf("%hd", &n);
    NODE* a[n];
    short b[n];
    scanf("%d", &x);
    NODE* root = (NODE*)malloc(sizeof(NODE)), *head;
    root->r = root->l = NULL;
    root->val = x;
    for(i=1; i<n; i++)
    {
        scanf("%d", &x);
        root = insert(x, root);
    }
    a[0] = root;
    b[0] = 0;
    i = 1;
    while(j < n)
    {
        head = a[j];
        if(head->l != NULL)
        {
            b[i] = (b[j] << 1) + 1;
            a[i++] = head->l;
            
        }
        if(head->r != NULL)
        {
            b[i] = (b[j] << 1) + 2;
            a[i++] = head->r;
        }
        j++;
    }
    printf("%d", a[0]->val);
    for(i=1; i<n; i++)
    {
        printf(" %d", a[i]->val);
    }
    if(b[n - 1] == n - 1)
    {
        puts("\nYES");
    }
    else
    {
        puts("\nNO");
    }
    free1(root);
	return 0;
}