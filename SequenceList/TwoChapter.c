#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIST_INIT_SIZE 100 //为线性表初始存储空间的大小。
#define LISIINCREMENT 10   //线性表存储空间的分配增量。
typedef struct
{
    int *elem;    //存储空间的基地址
    int length;   //当前线性表的长度
    int listsize; //当前分配的存储容量
} SqList;

/**********************************************
*Function name:     IfList
*Description:   判断顺序表是否存在，若存在是为空表还是非空表
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
**********************************************/
int IfExistList(SqList L)
{
    if (L.length >= 0)
    {
        if (L.length == 0)
        {
            return 0; //顺序表为空
        }
        else
        {
            return 1; //顺序表不为空
        }
    }
    else
    {
        return -1; //顺序表不存在
    }
}

/**********************************************
*Function name:  InitList_Sq
*Description:   初始化一个空线性表L
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
**********************************************/
SqList InitList_Sq(SqList L)
{
    if (L.elem != NULL) //释放L.elem本身所带过来的内存
    {
        free(L.elem);
        L.elem = NULL;
    }
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int)); //分配内存
    if (!L.elem)
    {
        printf("OVERFLOW");
        exit(0);
    }                            //判断内存分配是否失败
    L.length = 0;                //设置空表长度赋值为0
    L.listsize = LIST_INIT_SIZE; //设置初始存储容量
    printf("OK\n");
    return L;
}

/**********************************************
*Function name: ClearList
*Description:   在线性表L存在的清空下，清空L
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
**********************************************/
SqList ClearList(SqList L)
{
    if (IfExistList(L) == 1)
    {
        L = InitList_Sq(L);
        printf("The order list has been cleared\n");
        return L;
    }
    else if (IfExistList(L) == 0)
    {
        printf("empty table\n");
        return L;
    }
    else
    {
        printf("Order list does not exist, please confirm input\n");
        return L;
    }
}
/**********************************************
*Function name:     ListOutput
*Description:   输出线性表L
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
**********************************************/
void ListOutput(SqList L)
{
    if (IfExistList(L) == 1) //判断表是否存在
    {
        for (int i = 0; i < L.length; i++)
        {
            printf("%d\n", L.elem[i]);
        }
    }
    else if (IfExistList(L) == 0)
    {
        printf("The sequence table is empty\n");
    }
    else
    {
        printf("The order table does not exist\n");
    }
}
/**********************************************
*Function name: GetElem
*Description:   输出线性表L中第i个元素，并赋值给e返回
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
**********************************************/
int GetElem(SqList L, int i, int e)
{
    if (IfExistList(L) == 1) //判断表是否存在
    {
        e = L.elem[i - 1];
        return e;
    }
    else if (IfExistList(L) == 0)
    {
        printf("empty table\n");
        return 0;
    }
    else
    {
        printf("Order list does not exist, please confirm input\n");
        return 0;
    }
}
/*************************************************
*Function name:ListInsert_Sq
*Description: 在顺序表L中的第i个位置之前插入新的元素e
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***************************************************/
SqList ListInsert_Sq(SqList L, int i, int e)
{
    if (i < 1 || i > (L.length + 1))
    {
        printf("ERROR\n");
        return L;
    }                           //判断插入位置是否合法
    if (L.length >= L.listsize) //当存储空间已满时，增加分配
    {
        int *newbase = (int *)realloc(L.elem, (L.listsize + LISIINCREMENT) * sizeof(int));
        if (!newbase)
        {
            printf("OVERFLOW");
            exit(0);
        }
        L.elem = newbase;            //设置新的基地址
        L.listsize += LISIINCREMENT; //增加存储容量
    }
    int *q = NULL;
    q = &(L.elem[i - 1]); //要插入的位置
    for (int *p = &(L.elem[L.length - 1]); p >= q; p--)
    {
        *(p + 1) = *p;
    }           //插入位置及其以后的元素依次后移
    *q = e;     //插入新值e
    L.length++; //表长加+1;
    printf("OK\n");
    return L;
}
/*************************************************
*Function name:ListDelete_Sq
*Description: 将顺序表L中的第i个位置删除并赋值给元素e
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***************************************************/
SqList ListDelete_Sq(SqList L, int i, int e)
{
    if (i < 1 || i > L.length)
    {
        printf("ERROR\n");
        return L;
    }                          //判断删除位置是否合法
    int *p = &(L.elem[i - 1]); //待将删除的位置
    e = *p;                    //将被删除的位置赋给e
    printf("delete number=%d\n", e);
    int *q = L.elem + L.length - 1; //线性表尾的位置
    for (++p; p <= q; ++p)
        *(p - 1) = *p; //删除位置以后的元素依次前移
    L.length--;
    return L;
}
/*************************************************
*Function name:compare
*Description: 比较两个整数是否相等
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***************************************************/
int compare(int i, int j)
{
    int n;
    n = (i == j ?: 1, 0);
    return n;
}
/*************************************************
*Function name:LocateElem_Sq
*Description: 在顺序表L中查找第1个与e值相等的数，并返回下标。若无则返回0
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***************************************************/
int LocateElem_Sq(SqList L, int e, int (*compare)(int i, int j))
{
    int k = 1;       //标志位，表示已找到的那个数在顺序表中的位置
    int *p = L.elem; //从第一个开始寻找
    while (k <= L.length && !compare(*p++, e))
    {
        k++;
    }
    if (k <= L.length)
    {
        return k;
    }
    else
    {
        return 0;
    }
}
/*************************************************
*Function name:MergeList
*Description: 合并顺序表a,表b得到新的顺序表c,并按照原有顺序排列
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***************************************************/
SqList MergeList(SqList a, SqList b, SqList c)
{
    InitList_Sq(c);                          //初始化顺序表C
    int i = 1, j = 1, k = 0;                 //i,j指向顺序表a,b的第一个元素，k用作顺序表c
    int la_length = a.length;                //顺序表a的长度
    int lb_length = b.length;                //顺序表b的长度
    while (i <= la_length && j <= lb_length) //a,b两个顺序表均不能为空
    {
        int ai = GetElem(a, i, ai);
        int bi = GetElem(b, j, bi); //获得a,b两个表的第i个元素并分别赋给ai和bi
        if (ai <= bi)               //按递增的方式将数据插入c表中
        {
            c = ListInsert_Sq(c, ++k, ai);
            i++;
        }
        else
        {
            c = ListInsert_Sq(c, ++k, bi);
            j++;
        }
    }
    while (i <= a.length) //若表a当中还有剩余数据，则将数据全部插入c表中
    {
        int ai = GetElem(a, i++, ai);
        c = ListInsert_Sq(c, ++k, ai);
    }
    while (j <= b.length) //若表b当中还有剩余数据，则将数据全部插入c表中
    {
        int bi = GetElem(b, j++, bi);
        c = ListInsert_Sq(c, ++k, bi);
    }
    ListOutput(c); //输出c表
    return c;
}
/**********************************************************************
*Function name:PriorElem
*Description: 当cur_e是数据元素且不是第一个节点，则用pri_e返回它的前驱节点
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***********************************************************************/
int PriorElem(SqList L, int cur_e, int pri_e)
{
    int i = 1;
    if (IfExistList(L) == 1) //判断顺序表是否存在
    {
        if (cur_e == L.elem[0]) //判断是否为第一个节点
        {
            printf("This element is the first node in the sequence table and has no precursor nodes\n");
            return 0;
        }
        while (cur_e == L.elem[i++])
        {
            pri_e = L.elem[i - 2];
            return pri_e; //返回cur_e的前驱节点
        }
    }
    else if (IfExistList == 0)
    {
        printf("empty table\n");
        return 0;
    }
    else
    {
        printf("Order list does not exist, please confirm input\n");
        return 0;
    }
}
/**********************************************************************
*Function name:PriorElem
*Description: 当cur_e是数据元素且不是最后一个节点，则用next_e返回它的后继节点
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***********************************************************************/
int NextElem(SqList L, int cur_e, int next_e)
{
    int i = 0;
    if (IfExistList(L) == 1) //判断顺序表是否存在
    {
        if (cur_e == L.elem[L.length - 1]) //判断是否为最后一个节点
        {
            printf("This element is the last node in the sequence table and has no successors\n");
            return 0;
        }
        while (cur_e == L.elem[i++])
        {
            next_e = L.elem[i];
            return next_e; //返回cur_e的后继节点
        }
    }
    else if (IfExistList == 0)
    {
        printf("empty table\n");
        return 0;
    }
    else
    {
        printf("Order list does not exist, please confirm input\n");
        return 0;
    }
}
/**********************************************************************
*Function name:RandomList
*Description: 将空的顺序表L随机赋值10个数
*Version：      1.0
*Author：       Robert
*Create Time:   2022-2-7
***********************************************************************/
SqList RandomList(SqList L)
{
    srand((unsigned)time(NULL));
    if (IfExistList(L) == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            L.elem[i] = rand() % 51 + 13;
            L.length++;
        }
        return L;
    }
    else if (IfExistList(L) == 1)
    {
        printf("Table existing data\n");
        return L;
    }
    else
    {
        printf("Table does not exist\n");
        exit(0);
    }
}
SqList LisDelete(SqList L,int i,int e)
{
  if(i<1||i>L.length)   //判断需要删除的元素位置是否在范围内。
  {
      printf("The input is invalid. Try again");
      return L;
  }
  int *p=&L.elem[i-1]; //p为待删除元素的位置
  e=*p; //将待删除的元素赋值给e并输出
  printf("delete number=%d\n",e);
  int *q=L.elem+L.length-1;//表尾元素的位置
  for ( p++; p <=q;p++)//被删除元素以后的位置依次后移。
  {
      *(p-1)=*p;    
  }
  L.length--;
  return L;
}