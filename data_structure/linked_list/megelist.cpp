#include <iostream>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Merge1( List L1, List L2 )
{
    List tmpL1,tmpL2,tmpL,L;
    L = (List)malloc(sizeof(struct Node));
    tmpL1 = L1->Next;
    tmpL2 = L2->Next;
    tmpL = L;

    while(tmpL1 && tmpL2)
    {
        if(tmpL1->Data<= tmpL2->Data)
        {
            tmpL->Next = tmpL1;
            tmpL = tmpL1;
            tmpL1 = tmpL1->Next;
        }
        else
        {
            tmpL->Next = tmpL2;
            tmpL = tmpL2;
            tmpL2 = tmpL2->Next;
        }
    }

    tmpL->Next = tmpL1 ? tmpL1 : tmpL2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

List Merge2( List L1, List L2 )
{
    List a,b,c,L;
    L =(List)malloc(sizeof(struct Node));
    a = L1->Next;
    b = L2->Next;
    c = L;
    
    while(a && b)
    {
        if(a->Data<=b->Data)
        {
            c->Next = a;
            a = a->Next;
            c = c->Next;
        }
        else
        {
            c->Next = b;
            b = b->Next;
            c = c->Next;
        }
    }
    
    c->Next = a ? a : b;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}