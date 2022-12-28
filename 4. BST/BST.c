#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * Inserting
 * Searching
 * Deleting
 * Getting new node
 * Preorder
 * Postorder
 * Inorder
 * Finding MAX
 *
 */
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *insert(node *root, int data);
node *getnewnode(int data);
bool search(node *root, int data);
node *findmin(node *root);
int findmax(node *root);
int findheight(node *root);
node *preorder(node *root);
node *inorder(node *root);
node *postorder(node *root);
node *delete(node *root, int data);
void freeingl(node *root)
{
    while (root != NULL)
    {
        node *temp = (*root).left;
        free(root);
        root = temp;
    }
}
void freeingr(node *root)
{
    while (root != NULL)
    {
        node *temp = (*root).right;
        free(root);
        root = temp;
    }
}
int main(void)
{
    int number;
    node *root = NULL;
    root = insert(root, 25);
    insert(root, 24);
    insert(root, 26);
    insert(root, 23);
    insert(root, 27);
    insert(root, 22);
    insert(root, 28);
    insert(root, 21);
    insert(root, 20);
    insert(root, 29);
    insert(root, 5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 8);
    insert(root, 1);
    insert(root, 0);
    insert(root, 9);
    insert(root, 15);
    insert(root, 14);
    insert(root, 16);
    insert(root, 13);
    insert(root, 17);
    insert(root, 12);
    insert(root, 18);
    insert(root, 11);
    insert(root, 10);
    insert(root, 19);
    delete (root, 3);
    delete (root, 1);

    printf("Enter number be searched: ");
    scanf("%d", &number);
    if (search(root, number) == true)
    {
        printf(" _____");
        printf("\n|Found|\n");
        printf(" -----\n");
    }
    else
    {
        printf(" _________");
        printf("\n|Not Found|\n");
        printf(" ---------\n");
    }
    printf("\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nMAX = %d\n", findmax(root));

    freeingl(root);
    freeingr(root);
    postorder(root);
}
node *getnewnode(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    (*new_node).data = data;
    (*new_node).left = NULL;
    (*new_node).right = NULL;
    return new_node;
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = getnewnode(data);
    }
    else if (data <= (*root).data)
    {
        (*root).left = insert((*root).left, data);
    }
    else
    {
        (*root).right = insert((*root).right, data);
    }
    return root;
}
bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (data == (*root).data)//base condition
    {
        return true;
    }
    else if (data <= (*root).data)
    {
        return search((*root).left, data);
    }
    else
    {
        return search((*root).right, data);
    }
}
node *findmin(node *root)
{
     if (root == NULL)
    {
        root = NULL;
    }
    while ((*root).left != NULL)
    {
        root = (*root).left;
    }
    return root;
}
int findmax(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while ((*root).right != NULL)
    {
        root = (*root).right;
    }
    return (*root).data;
}
node *preorder(node *root)
{
    if (root != NULL)
    {
        printf(" %d", (*root).data);
        preorder((*root).left);
        preorder((*root).right);
    }
}
node *inorder(node *root)
{
    if (root != NULL)
    {
        inorder((*root).left);
        printf(" %d", (*root).data);
        inorder((*root).right);
    }
}
node *postorder(node *root)
{
    if (root != NULL)
    {
        postorder((*root).left);
        postorder((*root).right);
        printf(" %d", (*root).data);
    }
}
int findheight(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (findheight((*root).left) > findheight((*root).right))
    {
        return findheight((*root).left) + 1;
    }
    else
        return findheight((*root).right) + 1;
}
node *delete(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < (*root).data)
    {
        (*root).left = delete ((*root).left, data);
    }
    else if (data > (*root).data)
    {
        (*root).right = delete ((*root).right, data);
    }
    else
    {
        // no child
        if ((*root).left == NULL && (*root).right == NULL)
        {
            free(root);
            root = NULL;
        }
        // has one child
        else if ((*root).right == NULL)
        {
            node *temp = root;
            root = (*root).left;
            free(temp);
        }
        else if ((*root).left == NULL)
        {
            node *temp = root;
            root = (*root).right;
            free(temp);
        }
        // has two child
        else
        {
            node *temp = findmin((*root).right);
            (*root).data = (*temp).data;
            (*root).right = delete ((*root).right, (*temp).data);
        }
    }
    return root;
}
