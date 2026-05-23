#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
using namespace std;

// Simple workload to highlight scheduling differences
inline void do_work(int &x) {
    // Artificial workload
    int t = 0;
    for (int k = 0; k < 1000; ++k) t += (x * k) % 97;
    x = t;
}

int main() {
    const int N = 100000;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) {
        int v = rand();
        a[i] = b[i] = c[i] = v;
    }

    double t0 = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; ++i) do_work(a[i]);
    double t1 = omp_get_wtime();
    cout << "static:  " << (t1 - t0) << " s\n";

    t0 = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; ++i) do_work(b[i]);
    t1 = omp_get_wtime();
    cout << "dynamic: " << (t1 - t0) << " s\n";

    t0 = omp_get_wtime();
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; ++i) do_work(c[i]);
    t1 = omp_get_wtime();
    cout << "guided:  " << (t1 - t0) << " s\n";

    return 0;
}
