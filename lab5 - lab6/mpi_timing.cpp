#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    double start, end;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Synchronize all processes
    MPI_Barrier(MPI_COMM_WORLD);
    start = MPI_Wtime();

    // Simulated workload: higher rank = more work
    for (long i = 0; i < 1000000 * (rank + 1); i++);

    end = MPI_Wtime();

    cout << "Process " << rank << " took " << end - start << " seconds" << endl;

    if (rank == 0) {
        cout << "Total processes: " << size << endl;
    }

    MPI_Finalize();
    return 0;
}
