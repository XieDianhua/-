typedef int ElementType;

ElementType Average(ElementType S[], int N) {
    /* 求N个集合元素S[]的平均值 */
    int i;
    ElementType Sum = 0;

    for (i = 0; i < N; i++) /* 循环N次  0~N-1 */
        Sum += S[i];

    return Sum / N;
}

/* 基于排序寻找中位数 */
ElementType FindKthLargest(ElementTypen S[], int K) {

}
/* 基于问题分解寻找中位数 */
ElementType FindKthLargest(ElementTypen S[], int K) {

}
int main() { return 0; }