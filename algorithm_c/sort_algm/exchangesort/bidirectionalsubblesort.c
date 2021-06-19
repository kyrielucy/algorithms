
//优化3——鸡尾酒排序（Cocktail Sort）（又名：双向冒泡排序 (Bidirectional Bubble Sort)、波浪排序 (Ripple Sort)
//摇曳排序 (Shuffle Sort)、飞梭排序 (Shuttle Sort) 和欢乐时光排序 (Happy Hour Sort)）
void cocktail_sort(int arr[], const int ilen)
{
    int left = 0;  //左边开始排序
    int right = ilen - 1;  //右边开始排序
    while (left < right){
        for (int i = left; i < right; i++){  //找到序列中元素数据最大的那个放到最右边
            if (arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i + 1]);
            }
        }
        right--;
        for (int j = right; j > left; j--){  //找到序列中元素数据最小的那个放到最左边
            if (arr[j - 1] >arr[j]){
                swap(&arr[j - 1], arr[j]);
            }
        }
        left++;
    }
}
