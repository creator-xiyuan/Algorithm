Stack CreateStack(int MaxElements)
{
    Stack S;
    if(MaxElements < MinStackSize)
        Error("Stack size is too small");
    S = malloc(sizeof(ElementType) * MaxElements);
    if(!S)
        FatalError("Out of space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);
    //¶ø²»ÊÇS->TopOfStack = -1
    return S;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

void DisposeStack(Stack S)
{
    if(S)
    {
        free(S->Array);
        free(S);
    }
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full Stack");
    else
        S->Array[++ S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty Stack");
    else    
        S->TopOfStack --;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack --];
    Error("Empty Stack");
    return 0;
}

