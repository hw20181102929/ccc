#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    //Print(L1);
    //Print(L2);
    return 0;
}
List Read()
{
    List head,ptr,p;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->Next=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ptr=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&ptr->Data);
        ptr->Next=p->Next;
        p->Next=ptr;
        if(i==0)
        {
            head=p;
        }
        p=p->Next;
    }
    return head;
}
void Print( List L )
{
    if(L)
    {
        L=L->Next;
        while(L)
        {
            printf("%d ",L->Data );
            L=L->Next;
        }
        printf("\n");
    }
    else
    {
        printf("NULL");
    }
}
List Merge( List L1, List L2 )
{
    L1=L1->Next;
    L2=L2->Next;
    List head,ptr,p;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Next=NULL;
    int i=0;
    while(L1&&L2)
    {
        if(L1->Data<L2->Data)
        {
            p=L1->Next;
            L1->Next=NULL;
            L1->Next=ptr->Next;
            ptr->Next=L1;
            if(i==0)
            {
                head->Next=ptr->Next;
                i++;
            }
            ptr=ptr->Next;
            L1=p;
        }
        else
        {
            p=L2->Next;
            L2->Next=NULL;
            L2->Next=ptr->Next;
            ptr->Next=L2;
            if(i==0)
            {
                head->Next=ptr->Next;
                i++;
            }
            ptr=ptr->Next;
            L2=p;
        }
    }
    while(L1)
    {
        p=L1->Next;
        L1->Next=NULL;
        L1->Next=ptr->Next;
        ptr->Next=L1;
        if(i==0)
        {
            head->Next=ptr->Next;
            i++;
        }
        ptr=ptr->Next;
        L1=p;
    }
    while(L2)
    {
        p=L2->Next;
        L2->Next=NULL;
        L2->Next=ptr->Next;
        ptr->Next=L2;
        if(i==0)
        {
            head->Next=ptr->Next;
            i++;
        }
        ptr=ptr->Next;
        L2=p;
        printf("*");
    }
    return head;
}
