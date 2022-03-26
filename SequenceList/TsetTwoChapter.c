#include <stdio.h>
#include "TwoChapter.c"
void main(void)
{
    int k;
    int i, j;
    SqList L, M, N;
    L.elem = NULL, M.elem = NULL, N.elem = NULL;
    L = InitList_Sq(L);      //初始化
    L = RandomList(L);       //随机赋值
    ListOutput(L);           //输出
    L = ClearList(L);        //清空
    if (IfExistList(L) == 1) //判断状态
    {
        printf("There is data in the table\n");
    }
    else if (IfExistList(L) == 0)
    {
        printf("Empty table\n");
    }
    else
    {
        printf("Table does not exist\n");
    }



    L = RandomList(L);
    ListOutput(L);
    printf("third number=%d\n", GetElem(L, 3, k)); //取顺序表的第三个数，并输出。
    L = ListInsert_Sq(L, 3, 6);                    //将数字6插入顺序表的第三个位置并输出。
    ListOutput(L);
    L = ListDelete_Sq(L, 3, k); //将之前新插入的数字6删掉并输出。
    ListOutput(L);



    L = InitList_Sq(L); //重新初始化并提前给好值，测试函数能否正常找到
    L.elem[0] = 30;
    L.length++;
    L.elem[1]=110;
    L.length++;
    ListOutput(L);
    i = LocateElem_Sq(L, 10, compare);
    if (i == 0)
    {
        printf("not exits number\n");
    }
    else
    {
        printf("%d\n", i);
    }


    printf("%d\n", PriorElem(L, 110, k));//当110不是第一个节点时，返回它的前驱节点。
    M = InitList_Sq(M);
    M = RandomList(M); //初始化M并随机赋值
    printf("M:\n");
    ListOutput(M);
    N=MergeList(L, M, N);//合并L,M赋值给C
    printf("%d\n", NextElem(L, 30, k)); //当30不是最后一个节点时，返回它的后继节点。

    N=LisDelete(N,1,k);//删除L表的第一个元素并输出
    ListOutput(N);
}