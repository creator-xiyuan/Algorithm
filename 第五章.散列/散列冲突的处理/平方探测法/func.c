static Hash(ElementType Key, HashTable H)
{

}
static int NextPrime(int TableSie)
{

}
HashTable Initialize(int TableSize)
{
    HashTable H;
    int i;

    if(TableSize < MinTableSize)
    {
        Error("Table size is too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if(!H)
        FatalError("Out of space!!!");
    H->TableSize = NextPrime(TableSize);

    H->TheCells = mallco(sizeof(Cell) * H->TableSize);
    if(!H->TheCells)
        FatalError("Out of space!!!");
    
    for(i - 0; i < H->TableSize; i ++ )
        H->TheCells[i].Info = Empty;
}

Position Find(ElementType Key, HashTable H)
{
    Position CurrentPos = Hash(Key, H->TableSize);
    int CollisionNum = 0;

    while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        //Æ½·½Ì½²â·¨  H(i) = H(i - 1) + 2 * i - 1
        CurrentPos += 2 * ++CollisionNum - 1;
        if(CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos = Find(Key, H);
    if(H->TheCells[Pos].Info != Legitimate)
    {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}
