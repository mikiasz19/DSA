#include <stdlib.h>
#include <stdio.h>
// creating a node of 12 byte each to store data, next link and prev link
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
// declaring and initializing head
node *head = NULL;
void appending(int x)
{
    node *new_node1 = (node *)malloc(sizeof(node));
    (*new_node1).data = x;
    (*new_node1).next = NULL;
    if (head == NULL)
    {
        (*new_node1).prev = NULL;
        head = new_node1;
        return;
    }

    node *new_node2 = head;
    // traversing DLL
    while ((*new_node2).next != NULL)
    {
        new_node2 = (*new_node2).next;
    }
    (*new_node2).next = new_node1;
    (*new_node1).prev = new_node2;
}
void printing()
{
    for (node *i = head; i != NULL; i = (*i).next)
    {
        printf(" %d", (*i).data);
    }
}
void freeing()
{
    while (head != NULL)
    {
        node *j = head->next;
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