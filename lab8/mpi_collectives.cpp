#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int root = 0;
    int value;

    // ---------- BCAST ----------
    if (rank == root) {
        value = 42;  // root'un gönderdiği değer
    }

    MPI_Bcast(&value, 1, MPI_INT, root, MPI_COMM_WORLD);
    cout << "[Rank " << rank << "] After Bcast, value = " << value << endl;

    // ---------- SCATTER ----------
    vector<int> sendData(size);
    vector<int> recvData(1);

    if (rank == root) {
        for (int i = 0; i < size; i++)
            sendData[i] = i * 10;
    }

    MPI_Scatter(sendData.data(), 1, MPI_INT,
                recvData.data(), 1, MPI_INT,
                root, MPI_COMM_WORLD);

    cout << "[Rank " << rank << "] Received from Scatter: " << recvData[0] << endl;

    // ---------- GATHER ----------
    int localVal = rank + 100;
    vector<int> gathered;

    if (rank == root) {
        gathered.resize(size);
    }

    MPI_Gather(&localVal, 1, MPI_INT,
               gathered.data(), 1, MPI_INT,
               root, MPI_COMM_WORLD);

    if (rank == root) {
        cout << "[Rank 0] Gathered values: ";
        for (int x : gathered) cout << x << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
