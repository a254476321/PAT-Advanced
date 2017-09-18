#include<stdio.h>
#include<malloc.h>
inline static short max(short a, short b)
{
    return a > b ? a : b;
}
typedef struct node
{
    int val;
    struct node *left, *right;
} NODE;
NODE* left(NODE* root)
{
    NODE *a = root->right;
    root->right = a->left;
    a->left = root;
    return a;
}
NODE* right(NODE* root)
{
    NODE *a = root->left;
    root->left = a->right;
    a->right = root;
    return a;
}
NODE* LR(NODE* root)
{
    root->left = left(root->left);
    return right(root);
}
NODE* RL(NODE* root)
{
    root->right = right(root->right);
    return left(root);
}
int getHeight(NODE* a)
{
    if(a == NULL)
    {
        return 0;
    }
    return max(getHeight(a->left), getHeight(a->right)) + 1;
}
void free1(NODE* root)
{
    if(root == NULL)
    {
        return;
    }
    free1(root->left);
    free1(root->right);
    free(root);
}
NODE* insert(int val, NODE* root)
{
    if(root == NULL)
    {
        root = (NODE*)malloc(sizeof(NODE));
        root->left = root->right = NULL;
        root->val = val;
    }
    else if(val < root->val)
    {
        root->left = insert(val, root->left);
        if(getHeight(root->left) - getHeight(root->right) == 2)
        {
            root = val < root->left->val ? right(root) : LR(root);
        }
    }
    else
    {
        root->right = insert(val, root->right);
        if(getHeight(root->right) - getHeight(root->left) == 2)
        {
            root = val > root->right->val ? left(root) : RL(root);
        }
    }
    return root;
}
int main()
{
    short n;
    int x;
    scanf("%hd", &n);
    NODE* root;
    root = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &root->val);
    root->left = root->right = NULL;
    while(--n)
    {
        scanf("%d", &x);
        root = insert(x, root);
    }
    printf("%d", root->val);
    free1(root);
	return 0;
}