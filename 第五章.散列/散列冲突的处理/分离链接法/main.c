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
    //TheLists����һ��ָ��ָ��ListNode�ṹ��ָ���ָ��
    //�����ʹ����Щtypedef��������ܻ��൱����
    List *TheLists;
}
