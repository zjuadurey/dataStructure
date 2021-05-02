#include <iostream>

typedef struct LNode *PtrToLNode;
struct LNode
{
    int Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
typedef PtrToLNode Position;

//search

Position Find(List L, int X)
{
    Position p = L;

    if(p&&p->Data!=X)
        p = p->Next;
    
    if(p)
        return p;
    else 
        return NULL;
}

// insertion when head node exists
bool Insert(List L, int X, Position P)
{
    Position tmp ,pre;

    for ( pre=L; pre&&pre->Next!=P; pre = pre->Next);
    
    if(pre==NULL)
    {
        printf("插入位置参数错误\n");
        return false;
    }    
    else
    {
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

//delete node P
bool Delete(List L, Position P)
{
    Position pre;

    for(pre=L; pre&&pre->Next!=P;pre=pre->Next);

    if(pre==NULL||P==NULL)
    {
        printf("删除位置参数错误\n");
        return false;
    }
    else
    {
        pre->Next = P->Next;
        free(P);
        return true;
    }
}