List MakeEmpty(List L)
{
    L->Next = NULL;
    return L;
}
/*
List MakeEmpty()
{
    List L = malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}
*/

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L){
    Position P = L->Next;
    while(!P && P->Elemet != X)
        P = P->Next;
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L))  //如果元素X不存在，则P在表尾
    {
        TmpCell = P->Next;
        P->Next = P->Next->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P;
    while(!P->Next && P->Next->Element != X)
        P = P->Next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    //在C语言中，从void*到其他指针类型的隐式转换是允许的
    Position TmpCell = malloc(sizeof(struct Node));
    //错误处理
    if(TmpCell == NULL)
        FatalError("Out of space!!!");  //自定义函数
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position TmpCell;
    while(!L)
    {
        TmpCell = L;
        L = L->Next;
        free(TmpCell);
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P ? P->Next : NULL;
}

ElementType Retrieve(Position P)
{
    return P ? P->Element : 0;
}
