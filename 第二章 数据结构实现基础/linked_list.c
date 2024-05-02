#include <stdbool.h>

typedef int ElementType;

typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode List;

/* 插入结点 */
bool Insert(List L, int i) {

}

List Reverse(List L) {
    /* 将单链表L逆转 */
}

int main() { return 0; }