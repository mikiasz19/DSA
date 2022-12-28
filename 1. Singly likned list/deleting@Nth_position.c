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
    node *trav = head;
    while ((*trav).link != NULL)
    {
        trav = (*trav).link;
    }
    (*trav).link = new_node;
}
void deleting(int d)
{
    node *temp1 = head;
    if (d == 1)
    {
        head = temp1->link;
        free(temp1);
        return;
    }
    for (int i = 0; i < d - 2; i++)
    {
        temp1 = (*temp1).link; // arriving to n-1 position
    }
    node *temp2 = (*temp1).link;   // arriving to n position
    (*temp1).link = (*temp2).link; // storing the address of n+1 to n-1 position
    free(temp2);
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
    insert(6, 6); // 4, 1, 2, 3, 5, 6,
    printf("Before Deleting: ");
    printing();
    printf("\n");
    deleting(2); // 4, 2, 3, 5, 6
    deleting(1); // 2, 3, 5, 6
    deleting(4); // 2, 3, 5
    printf("After Deleting: ");
    printing();
    freeing();
}