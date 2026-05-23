#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    double start = omp_get_wtime();

    #pragma omp parallel
    {
        for (int i = 0; i < 10000; i++) {
            #pragma omp barrier
        }
    }

    double end = omp_get_wtime();
    cout << "Barrier overhead time: " << end - start << endl;

    return 0;
}
