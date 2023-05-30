Queue CreateQueue(int MaxElements)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    if(!Q)
        FatalError("Out of space!!!");
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(!Q->Array)
        FatalError("Out of space!!!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

//staticʹ�øú���ֻ�ڵ�ǰԴ�ļ�ʹ�ã���ǿ��װ��
//�˺���ֻ��ʵ�������������ܵĸ��������ⲿ�ļ�����û�����ã������к�������
static int Succ(int Value, Queue Q)  //Successor ���
{
    if(++ Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
        Error("Full Queue");
    else{
        Q->Size ++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue");
    Q->Front = Succ(Q->Front, Q);
}

ElementType Front(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue");
    return Q->Array[Q->Front];
}

ElementType FrontAndDequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue");
    ElementType temp = Q->Array[Q->Front];
    Q->Front = Succ(Q->Front, Q)
    return temp;
}

void DisposeQueue(Queue Q)
{
    if(Q)
    {
        free(Q->Array);
        free(Q);
    }
}

