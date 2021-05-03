/*
    2021/5/2
    单链表生成 插入 删除 查找
    by Adurey
*/
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
    for(int i=0; i <6; i++)
    {
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int search(node* head, int x)
{
    int count = 0;
    node* p = head->next;
    while(p)
    {
        if(p->data==x)
        {
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert(node* head, int pos, int x)
{
    node* p = head;
    for(int i = 0; i < pos-1; i++)
    {
        p = p->next;
    }
    node* q = new node;

    q->data = x;
    q->next = p->next;
    p->next = q;
}

void del(node* head, int x)
{
    node* p = head->next;
    node* pre = head;

    while(p)
    {
        if(p->data==x)
        {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }
        else
        {
            p = p->next;
            pre = pre->next;
        }
    }
}

int main()
{
    int Array[6] = {1,2,3,4,5,8};

    node* L = create(Array);
    insert(L, 2, 8);
    del(L, 8);
    int num = search(L,8);
    printf("num of 8: %d\n", num);
    L = L->next;
    while(L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    return 0;   
}