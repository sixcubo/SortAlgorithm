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


int main() {
    int arr[] = { 3, 2, 6, 8, 5, 1, 9, 7 };
    int len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原数组\n";
    printarr(arr, len);

    std::cout << "选择排序\n";
    selectSort(arr, len);
    printarr(arr, len);

    std::cout << "冒泡排序\n";
    bubbleSort(arr, len);
    printarr(arr, len);

}