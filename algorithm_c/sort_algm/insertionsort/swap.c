//实现两个数组中元素的交换。
#include <stdio.h>
void swap(int arr[], int a, int b)
{
    if (a != b)
    {
        arr[a] = arr[a] + arr[b];
        arr[b] = arr[a] - arr[b];
        arr[a] = arr[a] - arr[b];
    }
}

void swap(int arr[], int a, int b)
{
    if (a != b)
    {
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }
}

void swap(int *a, int *b) //交换函数
{
    assert(a != NULL && b != NULL); //断言，不满足条件结束程序
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}