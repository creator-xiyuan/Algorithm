#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);  //清空栈
int IsEmpty(Stack S);  
int IsFull(Stack S); 
void DisposeStack(Stack S);  //释放整个栈的内存
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

