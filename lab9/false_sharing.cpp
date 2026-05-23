#include <iostream>
#include <omp.h>
using namespace std;

struct Data {
    int a;
    int b;
};

int main() {
    Data data;

    double start = omp_get_wtime();

    #pragma omp parallel sections
    {
        #pragma omp section
        for (int i = 0; i < 100000000; i++)
            data.a++;

        #pragma omp section
        for (int i = 0; i < 100000000; i++)
            data.b++;
    }

    double end = omp_get_wtime();
    cout << "Execution time: " << end - start << endl;

    return 0;
}
