#include <stdio.h>
#include "LinearList.c"
void main(void)
{
    int k = 0;
    Linklist L;
    L = CreateList(L, 6);  //创建链表并随即赋值6个值
    OutLIinkList(L);       //输出链表L
    printf("%d\n", GetElem(L, 5, k)); //找出链表的第5个值并输出。
    ListInsert(L,1,99); //在头结点的单链表L中的第1个位置之前插入元素99
    OutLIinkList(L); //输出L
    printf("delete number=%d\n",ListDelete(L,9,k));//删除之前插入的的元素99并输出
    OutLIinkList(L);//输出删除元素的后的链表。
}