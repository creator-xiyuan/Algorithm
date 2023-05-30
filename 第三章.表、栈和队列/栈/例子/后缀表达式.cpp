#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EmptyTOS (-1)  //栈为空的时候TopOfStack的值为-1 
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
void MakeEmpty(Stack S);  //清空栈
int IsEmpty(Stack S);  
int IsFull(Stack S); 
void DisposeStack(Stack S);  //释放整个栈的内存
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
int level(char c);

int main(){
    Stack numS = CreateStack(SizeOfStack);
    Stack opS = CreateStack(SizeOfStack);
    
    char infix[SizeOfStack];
    printf("请输入中缀表达式：");
    fgets(infix, sizeof(infix), stdin);  //读入一行字符串 
    if(infix[strlen(infix) - 1] == '\n')  //去掉最后读入的换行 
        infix[strlen(infix) - 1] = '\0';
    
    //中缀转后缀 
    char postfix[SizeOfStack], idx = -1;
    //遍历中缀表达式 
    for(int i = 0; i < strlen(infix); i ++ )
    {
    	//数字直接输出 
        if(infix[i] - '0' >= 0 && infix[i] - '0' <= 9)
            postfix[++ idx] = infix[i];
        else
        {
        	//')'则将'('前的运算符弹出 
            if(infix[i] == ')') 
			{
				char temp = TopAndPop(opS);
				while(temp != '(');
                {
                    postfix[++ idx] = temp;
                    temp = TopAndPop(opS);
                }
			}
			//'('直接入栈 
            else if(infix[i] == '(')
                Push(infix[i], opS);
            else
            {
            	//+、-、*、/则弹出优先级不高于它的栈顶元素 
                while(!IsEmpty(opS) && Top(opS) != '(' && level(Top(opS)) >= level(infix[i]))
                    postfix[++ idx] = TopAndPop(opS);
                //自己入栈 
                Push(infix[i], opS);
            }
        }
    }
    //输出符号栈中剩余的运算符 
    while(!IsEmpty(opS))
        postfix[++ idx] = TopAndPop(opS);
        
    printf("后缀表达式为：%s\n", postfix);


    //计算后缀表达式
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
                	//因为栈顶元素是被减数，所以需要先弹出并记录 
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
    printf("计算结果为：%d", Top(numS) - '0');

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
    //而不是S->TopOfStack = -1
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

