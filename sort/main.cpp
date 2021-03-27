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


/// ���¾�Ϊ��������

/*
* ѡ������
* ���� len-1 ��, ÿ��ѡ�����С��Ԫ�طŵ�ǰ��
* ʱ�临�Ӷ�O(n^2), �ռ临�Ӷȣ�O(1), �ȶ�
*/
void selectSort(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        // Ѱ����СԪ��
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // ������ǰԪ������СԪ��
        swap(arr[i], arr[min]);
    }
}

/*
* ð������
* �����Ƚ�, С����ǰ, ����ں�
* ʱ�临�Ӷȣ�O(n^2), �ռ临�Ӷȣ�O(1), �ȶ�����
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

    std::cout << "ԭ����\n";
    printarr(arr, len);

    std::cout << "ѡ������\n";
    selectSort(arr, len);
    printarr(arr, len);

    std::cout << "ð������\n";
    bubbleSort(arr, len);
    printarr(arr, len);

}