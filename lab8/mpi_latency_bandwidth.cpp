#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // mesaj boyutları (byte cinsinden)
    vector<int> sizes = {1, 10, 100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<char> buffer(size);

        MPI_Barrier(MPI_COMM_WORLD);
        double start = MPI_Wtime();

        if (rank == 0) {
            MPI_Send(buffer.data(), size, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
            MPI_Recv(buffer.data(), size, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else if (rank == 1) {
            MPI_Recv(buffer.data(), size, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(buffer.data(), size, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        }

        double end = MPI_Wtime();

        if (rank == 0) {
            double roundTrip = end - start;
            double latency = roundTrip / 2.0;

            double bandwidthMBps = (size / latency) / (1024.0 * 1024.0);

            cout << "Message size: " << size
                 << " bytes | Latency: " << latency * 1e6 << " us"
                 << " | Bandwidth: " << bandwidthMBps << " MB/s"
                 << endl;
        }
    }

    MPI_Finalize();
    return 0;
}
