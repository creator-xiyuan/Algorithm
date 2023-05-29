#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial MakeEmpty();  //初始化
void CreatePolynomial(Polynomial P);  //创建多项式链表(头插法)
void PrintPolynomial(Polynomial P);  //打印多项式
Polynomial AddPolynomial(Polynomial P1, Polynomial P2);  //将两个多项式相加
Polynomial MultiplePolynomial(Polynomial P1, Polynomial P2); //多项式相乘

int main(){
    Polynomial P1 = MakeEmpty();
    CreatePolynomial(P1);
    Polynomial P2 = MakeEmpty();
    CreatePolynomial(P2);
    
    Polynomial PAdd = AddPolynomial(P1, P2);
    PrintPolynomial(PAdd);

    return 0;
}

Polynomial MakeEmpty()
{
    Polynomial P = (Polynomial)malloc(sizeof(struct Node));
    P->Next = NULL;
    return P;
}

void CreatePolynomial(Polynomial P)
{
    printf("请输入降序多项式（以0 0为结束标志）：\n");
    int coe, exp;
    while(scanf("%d%d", &coe, &exp), coe != 0 || exp != 0)
    {
        PtrToNode TmpCell = (Polynomial)malloc(sizeof(struct Node));
        TmpCell->Coefficient = coe;
        TmpCell->Exponent = exp;
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }
}

void PrintPolynomial(Polynomial P)
{
    PtrToNode TmpCell = P->Next;
    while(TmpCell)
    {
        if(!TmpCell->Exponent)
            printf("%d", TmpCell->Coefficient);
        else 
            printf("%dx^%d", TmpCell->Coefficient, TmpCell->Exponent);

        if(TmpCell->Next && TmpCell->Next->Coefficient > 0)
            printf("+");
        TmpCell = TmpCell->Next;
    }
}

Polynomial AddPolynomial(Polynomial P1, Polynomial P2)
{
    Polynomial PAdd = MakeEmpty();
    Polynomial TmpCell = PAdd, TmpCell1 = P1->Next, TmpCell2 = P2->Next;
    while(TmpCell1 && TmpCell2)
    {
        Polynomial Add = (Polynomial)malloc(sizeof(struct Node));
        if(TmpCell1->Exponent < TmpCell2->Exponent)
        {
            Add->Coefficient = TmpCell1->Coefficient;
            Add->Exponent = TmpCell1->Exponent;
            TmpCell1 = TmpCell1->Next;
        }
        else if(TmpCell1->Exponent > TmpCell2->Exponent)
        {
            Add->Coefficient = TmpCell2->Coefficient;
            Add->Exponent = TmpCell2->Exponent;
            TmpCell2 = TmpCell2->Next;
        }
        else
        {
            Add->Coefficient = TmpCell1->Coefficient + TmpCell2->Coefficient;
            Add->Exponent = TmpCell1->Exponent;
            TmpCell1 = TmpCell1->Next;
            TmpCell2 = TmpCell2->Next;
        }
        Add->Next = TmpCell->Next;
        TmpCell->Next = Add;
    }
    while(TmpCell1)
    {
        Polynomial Add = (Polynomial)malloc(sizeof(struct Node));
        Add->Coefficient = TmpCell1->Coefficient;
        Add->Exponent = TmpCell1->Exponent;
        TmpCell1 = TmpCell1->Next;
        Add->Next = TmpCell->Next;
        TmpCell->Next = Add;
    }
    while(TmpCell2)
    {
        Polynomial Add = (Polynomial)malloc(sizeof(struct Node));
        Add->Coefficient = TmpCell2->Coefficient;
        Add->Exponent = TmpCell2->Exponent;
        TmpCell2 = TmpCell2->Next;
        Add->Next = TmpCell->Next;
        TmpCell->Next = Add;
    }
    return PAdd;
}

Polynomial MultiplePolynomial(Polynomial P1, Polynomial P2)
{
    
}




