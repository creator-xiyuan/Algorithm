PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    if(MaxElements < MinPQSize)
        Error("Priority queue size is too small");
    
    H = malloc(sizeof(struct HeapStruct));
    if(!H)
        FatalError("Out of space!!!");
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if(!H->Elements)
        FatalError("Out of space!!!");
    H->Capacity = MaxElements;
    H->Size = 0;
    //MinData需要保证小于等于堆中的任何值，用以中止Insert函数中插入新的最小值时的for循环
    H->Elements[0] = MinData;

    return H;
}

int Isfull(PriorityQueue H)
{
    return H->Size < H->Capacity;
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if(IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }

    //将元素下移，比交换操作更加高效！
    for(i = ++ H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    if(IsEmpty(H))
    {
        Error("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size --];

    for(i = 1; i * 2 <= H->Size; i = Child)
    [
        Child = i * 2;
        //选出左孩子和可能存在的右孩子中的最小值
        if(Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child ++;
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    ]
    H->Elements[i] = LastElement;
    return MinElement;
}
