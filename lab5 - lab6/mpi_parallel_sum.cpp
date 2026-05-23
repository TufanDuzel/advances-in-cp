#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int start, end, local_sum = 0, total_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 100;  // Sum from 1 to 100
    int chunk = n / size;

    start = rank * chunk + 1;
    end = (rank == size - 1) ? n : start + chunk - 1;

    for (int i = start; i <= end; i++) {
        local_sum += i;
    }

    cout << "Process " << rank << " computed local sum: " << local_sum << endl;

    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Parallel computed sum: " << total_sum << endl;
    }

    MPI_Finalize();
    return 0;
}
