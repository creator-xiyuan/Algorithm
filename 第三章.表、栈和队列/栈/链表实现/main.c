#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef struct PtrToNode Stack;

Stack CreateStack();
int IsEmpty(Snake S);  
void Pop(Stack S);
void MakeEmpty(Stack S);  //���ջ
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void DisposeStack(Stack S);  //�ͷ�����ջ���ڴ�

#endif

struct Node
{
    ElementType Element;
    PtrToNode Next;
};
