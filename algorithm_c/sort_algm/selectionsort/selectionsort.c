/*https://www.cnblogs.com/skywang12345/p/3597641.html#a41
 *
 *选择排序原理:从头到尾扫描序列，找到最小（大）的元素，和未排序列的第一个元素交换，接下来继续从剩下的未排序列中找到
 *最小（大）的元素，并且和未排序的第一个交换，直到所有序列有序
*/
#include <stdio.h>
void selection_sort(int arr[], int ilen)
{
    if (arr == NULL && ilen < 2)
    {
        return;
    }
    int i; //从头开始扫描序列
    int j; //未排序列的下标，用于比较
    int minIndex; //保存最小元素的位置
    for (i = 0; i < ilen - 1; i++){ //要注意一点，当要排序 N 个数，已经经过 N-1 次遍历后，已经是有序数列
        minIndex = i;
        for (j = i + 1; j < ilen; j++){ //寻找第i小的元素
            if (arr[j] < arr[minIndex]){
                minIndex = j; //把新的最小位置j给minIdex保存起来
            }
        }
        swap(arr, i, minIndex); //未排序列查找到的最小位置的数和序列第一个元素交换。
    }
}