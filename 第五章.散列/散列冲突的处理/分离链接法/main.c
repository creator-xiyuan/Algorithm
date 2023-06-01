#ifndef

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);

#endif

#define MinTableSize (5)

struct ListNode
{
    ElementType Element;
    Position Next;
}

typedef Position List;

struct HashTbl
{
    int TableSize;
    //TheLists域是一个指向指向ListNode结构的指针的指针
    //如果不使用这些typedef，程序可能会相当混乱
    List *TheLists;
}
