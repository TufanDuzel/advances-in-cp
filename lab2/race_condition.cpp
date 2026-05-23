#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;

    // Intentional race condition version
    #pragma omp parallel for
    for (int i = 0; i < 100000; i++) {
        sum += 1;
    }

    cout << "Final sum (race) = " << sum << endl;
    return 0;
}