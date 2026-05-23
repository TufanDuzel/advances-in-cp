#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
    const int N = 50000000;
    vector<int> data(N);

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        int chunk = N / numThreads;

        int begin = id * chunk;
        int end = begin + chunk;

        for (int i = begin; i < end; i++)
            data[i] = id;
    }

    double end = omp_get_wtime();
    cout << "NUMA-style access time: " << end - start << endl;

    return 0;
}
