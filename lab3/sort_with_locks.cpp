#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<int> arr = {9, 3, 7, 1, 5, 2, 8, 4, 6, 0};
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for shared(arr)
    for (int i = 0; i < N - 1; i++) {
        omp_set_lock(&lock);
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
    cout << "Sorted with locks: ";
    for (int x : arr) cout << x << ' ';
    cout << endl;
    return 0;
}
