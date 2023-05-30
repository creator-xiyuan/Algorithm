#ifndef _Queue_h

struct QueueRecord;
typedef QueueRecord *Queue;

Queue CreateQueue(int MaxElements);
int IsEmpty(Queue Q);
void MakeEmpty(Queue Q);
int IsFull(Queue Q);
void Enqueue(ElementType X, Queue Q);
void Dequeue(Queue Q);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void DisposeQueue(Queue Q);

#endif

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
}


