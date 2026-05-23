#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    const long long N = 100000000; // 1e8
    double start = omp_get_wtime();
    volatile long long sum = 0; // volatile to avoid over-optimization

    #pragma omp parallel for schedule(dynamic,1)
    for (long long i = 0; i < N; ++i) {
        sum += 1;
    }

    double end = omp_get_wtime();
    cout << "Sum=" << sum << " | Time(s)=" << (end - start) << endl;
    return 0;
}