#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LNode //线性单链表的存储结构
{
    int data;
    struct LNode *next;
} LNode, *Linklist;
  
/*********************************************************
*Function name:     CreateList
*Description: 逆位序输入n个元素值，建立带表头结点的单链线性表L
*Version：      1.0
*Author：       Robert
*Create Time:   2022-3-6
**********************************************************/
Linklist CreateList(Linklist L, int n)
{
    srand((unsigned)time(NULL));
    L = (Linklist)malloc(sizeof(LNode));
    if (!L)
    {
        printf("OVERFLOW");
        exit(0);
    }
    L->data = n;    //表头数据域存在有多少个元素
    L->next = NULL; //建立一个带头结点的单链表
    for (int i = n; i > 0; i--)
    {
        Linklist p = (Linklist)malloc(sizeof(LNode)); //生成新的结点
        if (!p)
        {
            printf("OVERFLOW");
            exit(0);
        }
        //printf("pelase enter the %d number:",i);
        //scanf("%d", &p->data); //输入数据域内所存储的值

        p->data = rand() % 51 + 13;
        p->next = L->next; //第一次此时P->next==NULL，后面p->next均指向前一个结点。
        L->next = p;       //将头结点指向新生成的结点。
    }
    return L;
}
/*********************************************************
*Function name:     OutLIinkList
*Description: 输出单链线性表L
*Version：      1.0
*Author：       Robert
*Create Time:   2022-3-6
**********************************************************/
void OutLIinkList(Linklist L)
{
    Linklist p = L->next;
    while (p->next)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}
/*********************************************************
*Function name:     GetElem
*Description:  当i个元素存在与链表内时，找到赋值给k并返回。
*Version：      1.0
*Author：       Robert
*Create Time:   2022-3-6
**********************************************************/
int GetElem(Linklist L, int i, int k)
{
    Linklist p = L->next; //初始化p并指向第一个结点
    int j = 1;            //计数器
    while (p && j < i)    //顺指针向后寻找，直到p为空或p指向第i个元素
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) //当i不存在的情况
    {
        printf("no exits\n");
        return 0;
    }
    k = p->data; //取出第i个元素并赋值给k
    printf("Had been found\n");
    return k;
}
/*********************************************************
*Function name: ListInsert
*Description:  在头结点的单链表L中的第i个位置之前插入元素k
*Version：      1.0
*Author：       Robert
*Create Time:   2022-3-6
**********************************************************/
void ListInsert(Linklist L, int i, int k)
{
    Linklist p = L, s;
    int j = 0;
    while (p && j < i - 1) //寻找第i-1个结点。
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//插入位置不合法，i小于1或者大于表长加1
    {
        printf("ERROR\n");
    }
    s = (Linklist)malloc(sizeof(LNode));//生成新的结点。
    s->data = k;
    s->next = p->next;//插入链表中
    p->next = s;
    printf("OK\n");
}
/*********************************************************
*Function name: ListInsert
*Description:  删除在头结点的单链表中的第i个元素并用e返回.
*Version：      1.0
*Author：       Robert
*Create Time:   2022-3-6
**********************************************************/
int ListDelete(Linklist L,int i,int k)
{
    Linklist p=L;
    int j=0;
    while(p->next&&j<i-1)//找到要删除的第i个节点，并令p指向改节点的前驱节点。
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1) //判断删除位置是否合法
    {
        printf("local illegal\n");
        return -1;
    }
    Linklist q;//定义一个临时变量令其指向要待删除的节点
    q=p->next;
    p->next=q->next;//设置待删除节点的前驱节点的指针域指向待删除节点的后继节点，即绕过待删除结点。
    k=q->data;
    free(q);//释放节点
    return k;
}