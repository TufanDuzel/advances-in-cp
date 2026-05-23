#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // Enable nested parallelism (may require setting OMP_NESTED=TRUE on some runtimes)
    omp_set_nested(0);

    #pragma omp parallel num_threads(2)
    {
        int outer_id = omp_get_thread_num();
        cout << "Outer thread: " << outer_id << endl;

        #pragma omp parallel num_threads(2) firstprivate(outer_id)
        {
            int inner_id = omp_get_thread_num();
            // Some compilers support omp_get_ancestor_thread_num; we keep it simple and print captured outer_id
            cout << "  Inner thread: " << inner_id << " (inside outer " << outer_id << ")\n";
        }
    }
    return 0;
}