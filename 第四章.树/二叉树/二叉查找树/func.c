SearchTree MakeEmpty(SearchTree T)
{
    if(T)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if(!T)
        return NULL;
    if(X < T->Element)
        return Find(T->Left);
    if(X > T->Element)
        return Find(T->Right);
    else 
        return T;
}

Position FindMin(SearchTree T)  //递归实现
{
    if(!T)
        return NULL;
    if(!T->Left)
        return T;
    else 
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)  //非递归实现
{
    if(T)
        while(T->Right)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(!T)
    {
        T = malloc(sizeof(struct TreeNode));
        if(!T)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else
    {
        if(X < T->Element)
            T->Left = Insert(X, T->Left);
        else if(X > T->Element)
            T->Right = Insert(X, T->Right);
    }
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    SearchTree TmpT = T;
    Position TmpCell;
    Position T = Find(X, T);  //T是待删除结点
    if(!T)
        Error("Element not found");
    else
    {
        if(T->Letf && T->Right)
        {
            TmpCell = FindMin(T->Right);  //用右子树的最小值代替删除节点
            T->Element = TmpCell->Element;
            T->Right = Delete(T->Element, T->Right);
        }
        else
        {
            TmpCell = T;
            if(!T->Left)
                T = T->Right;
            else if(!T->Right)
                T = T->Left;
            free(TmpCell);
        }
    }
    return TmpT;
}

