#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        value = 100;
        cout << "Process 0 broadcasting value: " << value << endl;
    }

    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    cout << "Process " << rank << " received value: " << value << endl;

    MPI_Finalize();
    return 0;
}
