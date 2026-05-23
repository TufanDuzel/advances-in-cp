#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    bool ready = false;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for (volatile int i = 0; i < 100000000; i++);
            ready = true;
            cout << "Writer set ready = true\n";
        }

        #pragma omp section
        {
            while (!ready);
            cout << "Reader detected change\n";
        }
    }

    return 0;
}
