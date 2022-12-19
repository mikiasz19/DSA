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
        node *temp1 = (node *)malloc(sizeof(node));
        (*temp1).data = data;
        (*temp1).next = head;
        (*temp1).prev = NULL;
        if (head != NULL)
        {
            (*head).prev = temp1;
        }
        head = temp1;
    }
    else
    {
        node *temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = (*temp2).next;
        }
        node *temp3 = (node *)malloc(sizeof(node));
        (*temp3).data = data;
        (*temp3).next = (*temp2).next;
        (*temp3).prev = temp2;
        if ((*temp2).next != NULL)
        {
            (*temp2).next->prev = temp3;
        }
        (*temp2).next = temp3;
    }
}
void delete(int n)
{
    node *temp4 = head;
    if (n == 1)
    {
        head = (*temp4).next;
        free(temp4);
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp4 = (*temp4).next;
    }
    node *temp5 = (*temp4).next;
    (*temp4).next = (*temp5).next;
    free(temp5);
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
    delete (1);
    delete (4); // 6, 2, 7, 3, 4
    printing();
    freeing();
}