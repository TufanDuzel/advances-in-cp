#include <iostream>
#include <cstring>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    char message[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank != 0) {
        sprintf(message, "Hello from process %d", rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    } else {
        for (int src = 1; src < size; src++) {
            MPI_Recv(message, 100, MPI_CHAR, src, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            cout << message << endl;
        }
    }

    MPI_Finalize();
    return 0;
}
