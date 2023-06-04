#ifndef

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
Position Find(ElementType Key, HashTable H);  //Ѱ��Key��λ�û�ɲ����λ��
void Insert(ElementType Key, HashTable H);

#endif

//ÿ����Ԫ��״̬����ֵ���ա�ɾ��
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
