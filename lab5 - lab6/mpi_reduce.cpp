#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int value, sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process sets its own value
    value = rank + 1;

    // Reduce all values to the root process (0)
    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root prints the result
    if (rank == 0) {
        cout << "Sum of values 1 + 2 + ... + " << size << " = " << sum << endl;
    }

    MPI_Finalize();
    return 0;
}
