#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *head = NULL;
void insert(int data, int n)
{
    if (n == 1)
    {
        node *new_node1 = (node *)malloc(sizeof(node));
        (*new_node1).data = data;
        (*new_node1).next = head;
        (*new_node1).prev = NULL;
        if (head != NULL)
        {
            (*head).prev = new_node1;
        }
        head = new_node1;
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp = (*temp).next;
        }
        node *new_node2 = (node *)malloc(sizeof(node));
        (*new_node2).data = data;
        (*new_node2).next = (*temp).next;
        (*new_node2).prev = temp;
        if ((*temp).next != NULL)
        {
            (*temp).next->prev = new_node2;
        }
        (*temp).next = new_node2;
    }
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
        node *j = (*head).next;
        free(head);
        head = j;
    }
}
int main(void)
{
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 3);
    insert(6, 2);
    insert(7, 4); // 1, 6, 2, 7, 5, 3, 4
    printing();
    freeing();
}