#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node* next;
};

node* create(int Array[])
{
    node *p, *pre, *head;
    head = new node;//等价于 (node*)malloc(sizeof(node))
    head->next = NULL;
    pre = head;
    for(int i=0; i <5; i++)
    {
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int main()
{
    int Array[5] = {1,2,3,4,5};

    node* L = create(Array);
    L = L->next;
    while(L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    return 0;  
}