//顺序队列与循环队列
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8
typedef int datatype;

typedef struct
{
    datatype data[MAXSIZE];
    int rear,front;
}SeQueue;
void Init_SeQueue(SeQueue **q)
{
    *q=(SeQueue*)malloc(sizeof(SeQueue));
    (*q)->front=0;
    (*q)->rear=0;
    (*q)->data[0]=-1;
}
void In_SeQueue(SeQueue *q,datatype x)
{
    if((q->rear+1)%MAXSIZE==q->front)
        printf("Queue id full!\n");
    else
    {
        q->rear=(q->rear+1)%MAXSIZE;
        q->data[q->rear]=x;
    }
}
void Out_SeQueue(SeQueue *q,datatype *x)
{
    if(q->front==q->rear)
        printf("Queue id Empty!\n");
    else
    {
        q->front=(q->front+1)%MAXSIZE;
        *x=q->data[q->front];
    }
}
int Empty_SeQueue(SeQueue *q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
void Print_SeQueue(SeQueue *q)
{
    if(!Empty_SeQueue(q))
    {
        while(q->front!=q->rear)
        {
            printf("%d\t",q->data[q->front]);
            q->front=(q->front+1)%MAXSIZE;
        }
        printf("\n");
    }
}
int main()
{
    SeQueue *q;
    int i=0;
    int *x=&i;
    Init_SeQueue(&q);
    for(i=0;i<7;i++)
        In_SeQueue(q,i);
    for(i=0;i<3;i++)
        Out_SeQueue(q,x);
    Print_SeQueue(q);
    return 0;
}
