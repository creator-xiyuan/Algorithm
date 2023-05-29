#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//���к�����ͷ�ڵ�
List MakeEmpty(List L);  //�����ձ���������ͷ�ڵ�
int IsEmpty(List L);  //���Ƿ�Ϊ��
int IsLast(Position P, List L);  //�ж�P�Ƿ�������ĩβ
Position Find(ElementType X, List L);  //�ҵ�Ԫ��X�ڱ��е�λ��
void Delete(ElementType X, List L);  //ɾ��Ԫ��X
Position FindPrevious(ElementType X, List L); //�ҵ�Ԫ��X��ǰ��Ԫ
void Insert(ElementType X, List L, Position P);  //��λ��P�����Ԫ��
void DeleteList(List L);  //ɾ����
Position Header(List L);  //���ر�ͷ�ڵ�
Position First(List L);  //���ص�һ��Ԫ��
Position Advance(Position P);  //��Pָ����һ�����
ElementType Retrieve(Position P);  //����λ��P��ֵ

#endif

struct Node
{
    ElementType Element;
    Position Next;
};
