/* https://zhuanlan.zhihu.com/p/93129029
*  https://developer.51cto.com/art/201403/430986.htm
* 算法思想：将小于基准点的元素放到基准点的左边，将大于基准点的元素放到基准点右边，经过一趟排序后的序列分为两部分，
* 基准点左边的所有元素都比右边的所有元素小，然后再按此方法对这两部分分别进行快速排序，整个排序过程可以递归的进行，
* 让所有的数据元素变成有序的。
 */

void quick_sort(int arr[], int ibegin, int iend) //数组元素插入法，
{
    int i = ibegin; //数组的开始下标可以从0开始
    int j = iend; //数组的结尾下标length - 1。
    int pivot = arr[ibegin]; //保存基准pivot,这时数组arr[ibegin]为一个空位。
    while (i < j){ //i是增加的j是减小的所以当i==j是就会退出循环。
        while (i < j && arr[j] > pivot){ //选择了第一个做为基准点那么从后面j开始向前开始
            j--; //比基准值小的话就继续向前走比较
        }
        arr[i] = arr[j]; //找到了小于基准值就把这个值放到前面ibegin的位置上，把j位置空出来
         while (i < j && arr[i] < pivot){ //此时j是空位那么开始从前面i开始向后比较
            i++; //如果此时i位置元素比基准值小的话那么继续向后比较
        }
        arr[j] = arr[i]; //找到了比基准值大的数了就把它放到空位j的位置
    }
    arr[i] = pivot; //此时i==j,找到了基准值该在的位置
    quick_sort(arr, ibegin, i - 1); //以i为界限对前部分进行快排
    quick_sort(arr, i + 1, iend); //对后部分进行快排
}
//改写思想：先找右边再找左边，如果找到右边的小左边大的话就交换这两个位置的元素直到i=j之后交换基准值和i位置元素
//总结：
/** ①先从队尾开始向前扫描且当low < high时,如果a[high] > tmp,则high–,但如果a[high] < tmp,
 * 则将high的值赋值给low,即arr[low] = a[high],同时要转换数组扫描的方式,即需要从队首开始向队尾进行扫描了
 *  ②同理,当从队首开始向队尾进行扫描时,如果a[low] < tmp,则low++,但如果a[low] > tmp了,
 * 则就需要将low位置的值赋值给high位置,即arr[low] = arr[high],同时将数组扫描方式换为由队尾向队首进行扫描.
 *  ③不断重复①和②,知道low>=high时(其实是low=high),low或high的位置就是该基准数据在数组中的正确索引位置.
 */
void quick_sort(int arr[], int ibegin, int iend) //数组元素交换法
{
    int i = ibegin;
    int j = iend;
    int pivot = arr[ibegin];
    while (i != j){ //i==j的时候就退出
        while (i < j && arr[j] > pivot){
            j--;
        }
        while (i < j && arr[i] < pivot){
            i++;
        }
        if (i < j){
            swap(&arr[i], &arr[j]);
    }
    arr[ibegin] = arr[i];
    arr[i] = pivot;
    quick_sort(arr, ibegin, i -1);
    quick_sort(arr, i + 1, iend);

}
 