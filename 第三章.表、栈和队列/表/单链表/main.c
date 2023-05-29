#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//表中含虚拟头节点
List MakeEmpty(List L);  //创建空表并返回虚拟头节点
int IsEmpty(List L);  //表是否为空
int IsLast(Position P, List L);  //判断P是否在链表末尾
Position Find(ElementType X, List L);  //找到元素X在表中的位置
void Delete(ElementType X, List L);  //删除元素X
Position FindPrevious(ElementType X, List L); //找到元素X的前驱元
void Insert(ElementType X, List L, Position P);  //在位置P后插入元素
void DeleteList(List L);  //删除表
Position Header(List L);  //返回表头节点
Position First(List L);  //返回第一个元素
Position Advance(Position P);  //将P指向下一个结点
ElementType Retrieve(Position P);  //返回位置P的值

#endif

struct Node
{
    ElementType Element;
    Position Next;
};
