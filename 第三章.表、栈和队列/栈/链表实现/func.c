Stack CreateStack()
{
    Stack S = malloc(sizeof(struct Node));
    if(!S)
        FatalError("Out of space!!!");
    //为什么不直接S->Next = NULL？
	//因为这样更规范 
    MakeEmpty(S);
    return S;
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;
    if(IsEmpty(S))
        Error("Empty Stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void MakeEmpty(Stack S)
{
    if(!S)
        Error("Must use CreateSnake first");
    while(!IsEmpty(S))
        Pop(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell = malloc(sizeof(struct Node));
    if(!TmpCell)
        FatalError("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0;
}

void DisposeStack(Stack S)
{
    if(!S)
        Error("Empty Stack");
    else
    {
        PtrToNode TmpCell = S;
        while(S)
        {
            TmpCell = S->Next;
            free(S);
            S = TmpCell;
        }
    }
}
