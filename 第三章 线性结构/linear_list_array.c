#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//线性表可存储的大小
#define MAXSIZE 100
//定义错误信息
#define ERROR -1

typedef int ElementType;
typedef int Position; //这里的位置就是数组的整型下标,从0开始
typedef struct LNode *PtrToNode;

struct LNode {
  ElementType Data[MAXSIZE];
  Position Last;
};

typedef PtrToNode List;

//初始化
List MakeEmpty() {
  List L;
  L = (List)malloc(sizeof(struct LNode));
  L->Last = -1;
  return L;
}

//查找
Position Find(List L, ElementType X) {
  Position i = 0;
  while (i <= L->Last &&
         L->Data[i] != X) //如果i还在表的范围内且还没有找到待查找数X,则将下标加1
    i++;
  if (i > L->Last)
    return ERROR;
  else
    return i;
}

//插入
bool Insert(List L, ElementType X, int i) {
  /* 在L的指定位序i前插入一个新元素X;位序i元素的数组下标是i-1 */
  Position j;

  if (L->Last == MAXSIZE - 1) {
    printf("表已满");
    return false;
  }
  if (i < 1 || i > L->Last + 2) {
    /* 检查插入位序的合法性:是否在1~n+1,n为当前元素个数,即Last+1 */
    printf("位序不合法");
    return false;
  }

  for (j = L->Last; j >= i - 1; j--)
    L->Data[j + 1] = L->Data[j];
  L->Data[i - 1] = X; /* 新元素插入第i个位序,数组下标为i-1 */
  L->Last++;          /* Last仍指向最后元素 */
  return true;
}

/* 删除 */
bool Delete(List L, int i) {
  /* 从L中删除指定位序i的元素,该元素数组下标为i-1 */
  Position j;

  if (i < 1 || i > L->Last + 1) {
    printf("位序%d不存在元素", i);
    return false;
  }

  for (j = i; j < L->Last; j++)
    L->Data[j - 1] = L->Data[j]; /* 将位序i+1及以后的元素顺序向前移动 */
  L->Last--;
  return true;
}
int main() { return 0; }
