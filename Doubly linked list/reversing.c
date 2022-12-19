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
void pushing(int x)
{
    // pointer to node
    node *new_node = (node *)malloc(sizeof(node));
    (*new_node).data = x;
    (*new_node).next = head;
    (*new_node).prev = NULL;
    // safety checking
    if (head != NULL)
    {
        (*head).prev = new_node;
    }
    head = new_node;
}
void reversing()
{
    node *curr, *nextt, *prevv;
    curr = head;
    nextt = NULL;
    prevv = NULL;
    while (curr != NULL)
    {
        nextt = (*curr).next;
        (*curr).next = prevv;
        prevv = curr;
        curr = nextt;
    }
    head = prevv;
    for (node *i = head; i != NULL; i = (*i).next)
    {
        printf(" %d", (*i).data);
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
        pushing(x);
    }
    printf("Main: ");
    printing();
    printf("\n");
    printf("Reversed: ");
    reversing();
    freeing();
}