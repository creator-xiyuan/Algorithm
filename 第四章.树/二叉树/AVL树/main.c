#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
AvlTree Insert(ElementType X, AvlTree T);

#endif

struct AvlTree
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
}
