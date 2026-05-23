#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;

    #pragma omp parallel for
    for (int i = 0; i < 100000; i++) {
        #pragma omp atomic
        sum += 1;
    }

    cout << "Final sum (atomic) = " << sum << endl;
    return 0;
}