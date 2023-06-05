#ifndef

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
int Isfull(PriorityQueue H);
int IsEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);

#endif

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};
