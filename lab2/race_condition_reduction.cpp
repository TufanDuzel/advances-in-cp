#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100000; i++) {
        sum += 1;
    }

    cout << "Final sum (reduction) = " << sum << endl;
    return 0;
}