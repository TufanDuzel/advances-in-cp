#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int x = 5;

    // Change the clause here to: private(x), shared(x), firstprivate(x)
    #pragma omp parallel private(x)
    {
        x = omp_get_thread_num();
        cout << "Thread " << omp_get_thread_num()
             << " has x = " << x << endl;
    }

    cout << "After parallel region, x = " << x << endl;
    return 0;
}