#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i -1; i++) {
            if (arr[j] > arr[j + 1]) { // number of comp
                int temp = arr[j];
                arr[j] = arr[j + 1]; // number of swaps
                arr[j + 1] = temp;
            }
        }
    }
}

void selectSort(int* arr, int n) {
    int currMinIdx;
    for (int j = 0; j < n - 1; ++j) {
        currMinIdx = j;
        for (int k = j + 1; k < n; ++k) {
            if (arr[k] < arr[currMinIdx]) {
                currMinIdx = k;
            }
        }
        int temp = arr[j];
        arr[j] = arr[currMinIdx];
        arr[currMinIdx] = temp;
    }
}

void insertionSort(int* arr, int n) {
    for (int j = 1; j < n; ++j) {
        int temp = arr[j];
        int k = j;
        while (k > 0 && arr[k - 1] >= temp){
            arr[k] = arr[k-1];
            --k;
        }
    }
}

void quickSort(int* arr, int lo, int hi) {
    if (lo < hi) {
        int partitionIdx = partition(arr, lo, hi);
        quickSort(arr, lo, partitionIdx - 1);
        quickSort(arr, partitionIdx + 1, hi);
    }
}

int partition(int* arr, int lo, int hi) {
    int pivot = arr[hi];
    int small = lo - 1;
    for (int j = lo; j < hi; ++j) {  
        if (arr[j] < pivot) {
            ++small;
            int temp = arr[j];
            arr[j] = arr[small];
            arr[small] = temp;
        }    
    }
    int temp = arr[small + 1];
    arr[small + 1] = arr[hi];
    arr[hi] = temp;

    return small + 1;
}