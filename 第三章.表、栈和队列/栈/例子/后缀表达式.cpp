#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EmptyTOS (-1)  //ջΪ�յ�ʱ��TopOfStack��ֵΪ-1 
#define MinStackSize (5)
#define SizeOfStack (100)

typedef char ElementType;
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};
typedef StackRecord *Stack;

Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);  //���ջ
int IsEmpty(Stack S);  
int IsFull(Stack S); 
void DisposeStack(Stack S);  //�ͷ�����ջ���ڴ�
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
int level(char c);

int main(){
    Stack numS = CreateStack(SizeOfStack);
    Stack opS = CreateStack(SizeOfStack);
    
    char infix[SizeOfStack];
    printf("��������׺���ʽ��");
    fgets(infix, sizeof(infix), stdin);  //����һ���ַ��� 
    if(infix[strlen(infix) - 1] == '\n')  //ȥ��������Ļ��� 
        infix[strlen(infix) - 1] = '\0';
    
    //��׺ת��׺ 
    char postfix[SizeOfStack], idx = -1;
    //������׺���ʽ 
    for(int i = 0; i < strlen(infix); i ++ )
    {
    	//����ֱ����� 
        if(infix[i] - '0' >= 0 && infix[i] - '0' <= 9)
            postfix[++ idx] = infix[i];
        else
        {
        	//')'��'('ǰ����������� 
            if(infix[i] == ')') 
			{
				char temp = TopAndPop(opS);
				while(temp != '(');
                {
                    postfix[++ idx] = temp;
                    temp = TopAndPop(opS);
                }
			}
			//'('ֱ����ջ 
            else if(infix[i] == '(')
                Push(infix[i], opS);
            else
            {
            	//+��-��*��/�򵯳����ȼ�����������ջ��Ԫ�� 
                while(!IsEmpty(opS) && Top(opS) != '(' && level(Top(opS)) >= level(infix[i]))
                    postfix[++ idx] = TopAndPop(opS);
                //�Լ���ջ 
                Push(infix[i], opS);
            }
        }
    }
    //�������ջ��ʣ�������� 
    while(!IsEmpty(opS))
        postfix[++ idx] = TopAndPop(opS);
        
    printf("��׺���ʽΪ��%s\n", postfix);


    //�����׺���ʽ
	for(int i = 0; i < strlen(postfix); i ++)
    {
        if(postfix[i] - '0' >= 0 && postfix[i] - '0' <= 9)
            Push(postfix[i], numS);
        else
        {
            switch(postfix[i])
            {
                case '+':
                {
                	Push((TopAndPop(numS) - '0') + (TopAndPop(numS) - '0') + '0', numS);
                    break;
				}
                case '*':
                {
                	Push((TopAndPop(numS) - '0') * (TopAndPop(numS) - '0') + '0', numS);
                    break;
				}   
                case '-':
                {
                	//��Ϊջ��Ԫ���Ǳ�������������Ҫ�ȵ�������¼ 
                	int temp = TopAndPop(numS) - '0';
                    Push((TopAndPop(numS) - '0') - temp + '0', numS);
                    break;
				}
                case '/':
                {
                	int temp = TopAndPop(numS) - '0';
                    Push((TopAndPop(numS) - '0') / temp + '0', numS);
                    break;	
				}
            }
        }
    }
    printf("������Ϊ��%d", Top(numS) - '0');

    return 0;
}

Stack CreateStack(int MaxElements)
{
    Stack S;
    if(MaxElements < MinStackSize)
        printf("Stack size is too small");
    S = (Stack)malloc(sizeof(struct StackRecord));
    if(!S)
        printf("Out of space!!!");
    S->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
    if(!S->Array)
    	printf("Out of space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);
    //������S->TopOfStack = -1
    return S;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

void DisposeStack(Stack S)
{
    if(S)
    {
        free(S->Array);
        free(S);
    }
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        printf("Full Stack");
    else
        S->Array[++ S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    printf("Empty Stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        printf("Empty Stack");
    else    
        S->TopOfStack --;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack --];
    printf("Empty Stack");
    return 0;
}

int level(char c)
{
    if(c == '(' || c == ')')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 1;
}

