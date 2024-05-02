#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL /* 一般定义为表中元素不可能取到的值 */

typedef int ElementType;

typedef struct LNode *PtrToLNode;
struct LNode {
  ElementType Data;
  PtrToLNode Next;
};
typedef PtrToLNode Position; /* 这里位置指结点地址 */
typedef PtrToLNode List;

/* 求表长 */
int Length(List L) {
  Position p;
  int cnt = 0;
  p = L;
  while (p) {
    p = p->Next;
    cnt++;
  }
  return cnt;
}
/* 按序号查找 */
ElementType FindKth(List L, int K) {
  Position p;
  int cnt = 1;
  p = L;
  while (p && cnt < K) { /* 查找范围在链表内且找到了就退出了 */
    p = p->Next;
    cnt++;
  }
  if ((cnt == K) && p)
    return p->Data;
  else
    return ERROR;
}

/* 按值查找 */
Position Find(List L, ElementType X) {
  Position p = L;
  while (p && p->Data != X)
    p = p->Next;

  if (p) /* 进入了if说明在链表中找到了X */
    return p;
  else
    return ERROR;
}

/* 插入,不带头结点 */
List InsertNoHead(List L, ElementType X, int i) {
  Position tmp, pre;

  tmp = (Position)(sizeof(struct LNode)); /* 申请 填装结点 */
  tmp->Data = X;
  if (i == 1) {
    tmp->Next = L;
    L = tmp; /* 返回新表头指针 */
  } else {
    /* 查找位序为i-1的结点 */
    int cnt = 1;
    pre = L;
    while (pre && cnt < i - 1) {
      pre = pre->Next;
      cnt++;
    }
    if (pre == NULL || cnt != i - 1) {
      printf("插入位置参数错误\n");
      free(tmp);
      return ERROR;
    } else { /* 找到了待插结点的前一个结点pre */
      /* 插入新结点,并且返回表头L */
      tmp->Next = pre->Next;
      pre->Next = tmp;
      return L;
    }
  }
}
int main() { return 0; }