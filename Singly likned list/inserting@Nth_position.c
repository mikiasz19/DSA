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
void insert(int data, int n)
{
    node *new_node = (node *)malloc(sizeof(node));
    (*new_node).data = data;
    (*new_node).link = NULL;
    if (n == 1)
    {
        (*new_node).link = head;
        head = new_node;
        return;
    }
    node *new_node2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        new_node2 = (*new_node2).link;
    }
    (*new_node).link = (*new_node2).link;
    (*new_node2).link = new_node;
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
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 1);
    insert(5, 2);
    insert(6, 3); // 4, 5, 6, 1, 2, 3
    printing();
    freeing();
}