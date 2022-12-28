#include <stdio.h>
#include <stdlib.h>
// creating a node to store both data and the next link
typedef struct node
{
    int data;
    struct node *link;
} node;
// declaring and initializing the head node
node *head = NULL;
void appending(int x)
{
    // pointer to node
    node *new_node = (node *)malloc(sizeof(node));
    // we can also use syntactic sugar
    (*new_node).data = x;
    (*new_node).link = NULL;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node *trav = head;
    while ((*trav).link != NULL)
    {
        trav = (*trav).link;
    }
    (*trav).link = new_node;
}
void printing()
{
    for (node *i = head; i != NULL; i = (*i).link)
    {
        printf(" %d", (*i).data);
    }
}
void freeing()
{
    while (head != NULL)
    {
        node *j = head->link;
        free(head);
        head = j;
    }
}
int main(void)
{
    int n, x;
    printf("Number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("> ");
        scanf("%d", &x);
        appending(x);
    }
    printing();
    freeing();
}
