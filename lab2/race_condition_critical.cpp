#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;

    #pragma omp parallel for
    for (int i = 0; i < 100000; i++) {
        #pragma omp critical
        {
            sum += 1;
        }
    }

    cout << "Final sum (critical) = " << sum << endl;
    return 0;
}