#include <iostream>


/*
* 选择排序
* 稳定, 时间复杂度O(n^2), 空间复杂度：O(1)
* 
*/
void selectSort(int *arr, int length) {

}

void printarr(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << "  " << std::endl;
    }
}


int main() {
    int arr[] = { 3, 2, 6, 8, 5, 1, 9, 7 };
    int length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原数组\n";
    printarr(arr, length);


}