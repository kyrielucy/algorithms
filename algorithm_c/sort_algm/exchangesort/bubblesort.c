// https://blog.csdn.net/zcl_love_wx/article/details/83576962
//冒泡排序：从左向右，相邻依次进行比较，就会找到序列中最大或者最小的一个，这个数就会从序列的最右边冒出来
//以从小到大的顺序排列为例，第一轮排序后，最大的 那个数就会浮到最右边；第二轮比较后，第二大的数就会从浮到第二大的位置，就这样
//就这样一轮一轮下来，实现从小到大排列。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#define ture 1
//#define false 0

void bubble_sort(int arr[], const int ilen)
{
    assert(arr != NULL && ilen > 0); //断言
    for (int i = 0; i < ilen - 1; i++)
    { //外循环，ilen-1趟遍历循环
        for (int j = 0; j < ilen - 1 - i; j++)
        { //进行ilen-1-i次比较。因为每次都会找到一个最大的值。所以每趟都会少一次。
            if (arr[j] > arr[j + 1])
            {   //从小到大的排序
                //if (arr[j] < arr[j + 1]){  //从大到小的排序
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
//1减少外循环的优化。也就是如果这次循环没有发生交换那么说明已经排好序了。
void bubble_sort(int arr[], const int ilen)
{
    assert(arr != NULL && ilen > 0); //断言，程序健壮性。
    for (int i = 0; i < ilen - 1; i++)
    {
        bool flag = false; //flag == false表示没有发生交换，反之发生了交换。
        for (int j = 0; j < ilen - 1 - i; j++) 
        {
            if (arr[i] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        }
        if (flag)
        { //如果flag没有变化则表示没有发生交换，就退出循环。
            break;
        }
    }
}

//2减少内循环的次数。
//如果我们把第一次出现这一趟比较没有发生交换数据的位置下标找到，然后把这个值作为内存循环的上限，这样内循环就可以减少了
//原因是如果这一趟没发生交换那么后续的每一趟都不会再进行交换了，比如我们第一趟过后如果是从小到大的排序那么确定的是
//最后一个数是序列中最大的那么下一次就只需要比较到第二大的位置即可。
void bubble_sort(int arr[], const int ilen)
{
    assert(arr != NULL && ilen > 0);
    for (int i = 0; i < ilen - 1; i++)
    {
        bool flag = true;  
        int lastcompareposition = 0;  //第i趟没有发生交换的位置，这次没发生交换说明是有序的，那下一趟也就不会发生交换
        int comparelen = ilen - 1;  //内循环的上限，减少了每一趟没必要的比较。
        for (int j = 0; j < comparelen; j++)
        {
            if (arr[j] > arr[j + 1])  //从小到大的冒泡排序
            {
                swap(&arr[j], &arr[j + 1]);  //交换两个元素。
                flag = false;  //发生了交换则改变标志方便后面做判断是否排序完成。
                lastcompareposition = j;  //把最后一次交换的位置记录下来。
            }
        }
        comparelen = lastcompareposition;  //传递最后一次交换位置作为下一趟比较的上限
        if (flag)  //如果发生了交换，也就是flag的值发生变化那么退出循环。
        {
            break;
        }
    }
}
