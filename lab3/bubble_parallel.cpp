#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 8;
    int arr[N] = {9, 3, 7, 1, 5, 2, 8, 4};
    bool swapped = true;

    while (swapped) {
        swapped = false;
        #pragma omp parallel for shared(arr)
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
