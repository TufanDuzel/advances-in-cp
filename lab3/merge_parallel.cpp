#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = 0; i < k; i++) arr[left + i] = temp[i];
}

void parallelMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        #pragma omp task shared(arr)
        parallelMergeSort(arr, left, mid);
        #pragma omp task shared(arr)
        parallelMergeSort(arr, mid + 1, right);
        #pragma omp taskwait
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {9, 4, 7, 3, 2, 8, 1, 5};
    #pragma omp parallel
    {
        #pragma omp single
        parallelMergeSort(arr, 0, (int)arr.size() - 1);
    }
    cout << "Sorted array: ";
    for (int v : arr) cout << v << " ";
    cout << endl;
    return 0;
}
