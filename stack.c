#include<stdio.h>
#include<stdlib.h>
#define MS 6
typedef struct stack
{
    int top;
    int arr[MS];
    int size;
} stack;
void init(stack*s)
{
    s->size=0;
    s->top=-1;
}
void push(stack*s,int x)
{
    if(s->top==MS-1)
    {
        printf("Not Possible\n");
        return;
    }
    s->size++;
    s->arr[++s->top]=x;
}
void display(stack*s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d\n",s->arr[i]);
    }
    printf("\n");
}
void pop(stack*s)
{
    if(s->top==-1)
    {
        printf("Underflow condition\n");
        return;
    }
    --s->top;
}
int getsize(stack*s)
{
    int size=s->top+1;
    return size;
}
int getpeek(stack*s)
{
    return s->arr[s->top];
}
int main()
{
    stack s;
    init(&s);
    push(&s,10);
    push(&s,30);
    push(&s,50);
    push(&s,70);
    push(&s,90);
    push(&s,20);
    display(&s);
    printf("Size-->%d\n",getsize(&s));
    printf("Top--->%d\n",getpeek(&s));
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    display(&s);
    
    printf("Size-->%d\n",getsize(&s));
    printf("Top--->%d\n",getpeek(&s));
     
}