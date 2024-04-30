#define MAXSIZE 100

typedef int ElementType;
typedef int Position; //这里的位置就是数组的整型下标,从0开始
typedef struct LNode *PtrToNode;

struct LNode {
  ElementType Data[MAXSIZE];
  Position Last;
};

typedef PtrToNode List;

int main() {}
