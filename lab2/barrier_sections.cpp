#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        if (id == 0)
            cout << "Thread " << id << " is loading data..." << endl;

        // #pragma omp barrier  // Wait for all threads

        #pragma omp sections
        {
            #pragma omp section
            cout << "Thread " << id << " is processing part A\n";

            #pragma omp section
            cout << "Thread " << id << " is processing part B\n";

            // Third section added
            #pragma omp section
            cout << "Thread " << id << " is processing part C\n";
        }

        #pragma omp barrier
        if (id == 0)
            cout << "All work completed!" << endl;
    }
}