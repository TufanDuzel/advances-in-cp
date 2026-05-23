#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<int> arr(N);

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i * 2;
        cout << "Thread " << omp_get_thread_num() 
             << " set arr[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}
