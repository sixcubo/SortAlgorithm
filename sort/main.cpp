#include <iostream>


void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void printarr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}


/// 以下均为升序排序

/*
* 选择排序
* 遍历 len-1 次, 每次选择出最小的元素放到前面
* 时间复杂度O(n^2), 空间复杂度：O(1), 稳定
*/
void selectSort(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        // 寻找最小元素
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // 交换当前元素与最小元素
        swap(arr[i], arr[min]);
    }
}

/*
* 冒泡排序
* 两两比较, 小的在前, 大的在后
* 时间复杂度：O(n^2), 空间复杂度：O(1), 稳定排序
*/
void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}


/*
* 快速排序, 递归算法
* 每次以一个数为基准, 将小于它的放在左边, 比大于等于它的放在右边; 递归地对基准两边执行相同操作.
* 时间复杂度：O(nlogn), 空间复杂度：O(logn), 非稳定排序
*/
void quickSort(int* arr, int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        int pivot = arr[l]; // 基准

        while (i < j) {
            // 从右向左找第一个小于pivot的数
            while (i < j && pivot < arr[j]) {
                j--;
            }
            if (i < j) {
                arr[i] = arr[j];
                i++;
            }

            // 从左向右找第一个大于等于x的数
            while (i < j && pivot >= arr[i]) {
                i++;
            }
            if (i < j) {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = pivot;

        // 递归调用
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
}

/*
* 插入排序
* 数组的前部分是有序的，后部分是无序的。对无序部分的数，为他们找到在有序部分的位置插入进去
* 时间复杂度：O(n^2), 空间复杂度：O(1), 稳定排序
*/
void insertSort(int* arr, int len) {
    // i 之前部分有序, 之后部分无序
    for (int i = 1; i < len; i++) {
        int x = arr[i]; // 待排元素

        // 寻找合适位置
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (x <= arr[j]) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }
        // 将待排元素插入
        arr[j + 1] = x;
    }
}


int main() {
    int arr[] = { 10, 12, 4, 5, 3, 44, 54, 78, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原数组\n";
    printarr(arr, len);

    std::cout << "选择排序\n";
    selectSort(arr, len);
    printarr(arr, len);

    std::cout << "冒泡排序\n";
    bubbleSort(arr, len);
    printarr(arr, len);

    std::cout << "快速排序\n";
    quickSort(arr, 0, len - 1);
    printarr(arr, len);

    std::cout << "插入排序\n";
    insertSort(arr, len);
    printarr(arr, len);

}