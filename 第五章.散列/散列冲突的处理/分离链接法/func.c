static Hash(ElementType Key, int TableSize){

}
static int NextPrime(int TableSize)
{

}
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if(TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if(!H)
        FatalError("Out of space!!!");
    H->TableSize = NextPrime(TableSize);  //下一个素数

    H->TheLists = malloc(sizeof(struct List) * H->TableSize);
    if(!H)
        FatalError("Out of space!!!");

    for(i = 0; i < TableSize; i ++ )
    //可以用H->TheLists[i] = MakeEmpty();代替
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(!H->TheLists[i])
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while(P && P->Element != Key)
        P = P->Next;
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    //不存在关键字Key则插入，存在则不做处理
    if(!Pos)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if(!NewCell)
            FatalError("Out of space!!!");
            else
            {
                L = H->TheLists[Hash(Key, H->TableSize)];
                //可使用单链表中的Insert函数
                NewCell->Next = L->Next;
                NewCell->Element = Key;
                L->Next = NewCell;
            }
    }
}

