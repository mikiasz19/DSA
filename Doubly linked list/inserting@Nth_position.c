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
     node *temp1 = (node *)malloc(sizeof(node));
    (*temp1).data = data;
    (*temp1).prev = NULL;
    if (n == 1)
    {
        (*temp1).next = head;
        head = temp1;
        return;
    }
    else
    {
        node *temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = (*temp2).next; // n-1
        }
        (*temp1).next = (*temp2).next; // bond between n and n-1
        // sewing
        (*temp2).next = temp1;
        (*temp1).prev = temp2;
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
