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


/* 
* ��������, �ݹ��㷨
* ÿ����һ����Ϊ��׼, ��С�����ķ������, �ȴ��ڵ������ķ����ұ�; �ݹ�ضԻ�׼����ִ����ͬ����.
* ʱ�临�Ӷȣ�O(nlogn), �ռ临�Ӷȣ�O(logn), ���ȶ�����
*/
void quickSort(int* arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int i = l;
    int j = r;
    int pivot = arr[l]; // ��׼

    while (i < j) {
        // ���������ҵ�һ��С��pivot����
        while (i < j && pivot < arr[j]) {
            j--;
        }
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }

        // ���������ҵ�һ�����ڵ���x����
        while (i < j && pivot >= arr[i]) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = pivot;

    // �ݹ����
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

/* 
* ��������
* �����ǰ����������ģ��󲿷�������ġ������򲿷ֵ�����Ϊ�����ҵ������򲿷ֵ�λ�ò����ȥ
* ʱ�临�Ӷȣ�O(n^2), �ռ临�Ӷȣ�O(1), �ȶ�����
*/
void insertSort(int* arr, int len) {
    // i ֮ǰ��������, ֮�󲿷�����
    for (int i = 1; i < len; i++) {
        int x = arr[i]; // ����Ԫ��

        // Ѱ�Һ���λ��
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (x <= arr[j]) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }
        // ������Ԫ�ز���
        arr[j + 1] = x;
    }
}

/*
* �鲢����, ���η�, �ݹ�
* �Ȱ�����ƽ���ֳ����ݣ�Ȼ��ÿ���ٽ��еݹ��ٴηֳ����ݣ�ֱ�������ٷ֣�Ȼ��ʼ���������ĺϲ���
* ʱ�临�Ӷȣ�O(nlogn), �ռ临�Ӷȣ�O(n), �ȶ�����
*/
void merge(int* arr, int start, int mid, int end) {
    int* tmp = new int[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    // ÿ�δ���������ѡ����С��Ԫ������tmp
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            tmp[k++] = arr[j++];
        }
    }
    // ��ʣ��Ԫ������tmp
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= end) {
        tmp[k++] = arr[j++];
    }
    
    // ��Ԫ�ش���ʱ����ת��ԭ����
    for (int i = 0; i < k; i++) {
        arr[start + i] = tmp[i];
    }

    delete[]tmp;
}

void mergeSort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    // ��
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // ��
    merge(arr, start, mid, end);
}


/*
* �鲢����, �ǵݹ�
*/
void mergeSort2(int* arr, int len) {
    for (int size = 1; size < len; size += size) {
        // ����������л���
        int start = 0;
        int mid = start + size - 1;
        int end = mid + size;

        // ���кϲ����������СΪ size ��������������ϲ�
        while (end < len) {
            // �ϲ������͵ݹ�ʽ�ĺϲ�����һ��
            merge(arr, start, mid, end);
            start = end + 1;
            mid = start + size - 1;
            end = mid + size;
        }

        // ����һЩ����©������û�ϲ���ǧ�������
        // ��Ϊ����ÿ��������Ĵ�С�����պ�Ϊ size
        if (start < len && mid < len) {
            merge(arr, start, mid, len - 1);
        }
    }
}


int main() {
    int arr[] = { 10, 12, 4, 5, 3, 44, 54, 78, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "ԭ����\n";
    printarr(arr, len);

    std::cout << "ѡ������\n";
    selectSort(arr, len);
    printarr(arr, len);

    std::cout << "ð������\n";
    bubbleSort(arr, len);
    printarr(arr, len);

    std::cout << "��������\n";
    quickSort(arr, 0, len - 1);
    printarr(arr, len);

    std::cout << "��������\n";
    insertSort(arr, len);
    printarr(arr, len);

    std::cout << "�鲢����\n";
    mergeSort(arr, 0, len - 1);
    printarr(arr, len);

    std::cout << "�鲢����, �ǵݹ��㷨\n";
    mergeSort2(arr, len - 1);
    printarr(arr, len);

}