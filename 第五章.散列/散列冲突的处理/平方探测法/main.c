#ifndef

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
Position Find(ElementType Key, HashTable H);  //寻找Key的位置或可插入的位置
void Insert(ElementType Key, HashTable H);

#endif

//每个单元的状态：有值、空、删除
enum KindOfEntry {Legitimate, Empty, Delete};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
}
