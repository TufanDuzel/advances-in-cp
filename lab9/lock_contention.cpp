#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int shared = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        for (int i = 0; i < 1000000; i++) {
            omp_set_lock(&lock);
            shared++;
            omp_unset_lock(&lock);
        }
    }

    double end = omp_get_wtime();

    cout << "Final value: " << shared << endl;
    cout << "Time: " << end - start << endl;

    omp_destroy_lock(&lock);
    return 0;
}
