#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 4; // örnek olarak 4x4 matris
               // PDF büyük istiyorsa N=1000 yapabilirsin

    vector<int> A, B(N * N), localA, localC;

    int rowsPerProcess = N / size;

    if (rank == 0) {
        A.resize(N * N);
        for (int i = 0; i < N * N; i++) A[i] = i + 1;  // A matrisi

        for (int i = 0; i < N * N; i++) B[i] = i + 1;  // B matrisi
    }

    localA.resize(rowsPerProcess * N);
    localC.resize(rowsPerProcess * N);

    MPI_Scatter(
        A.data(), rowsPerProcess * N, MPI_INT,
        localA.data(), rowsPerProcess * N, MPI_INT,
        0, MPI_COMM_WORLD
    );

    MPI_Bcast(B.data(), N * N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < rowsPerProcess; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += localA[i * N + k] * B[k * N + j];
            }
            localC[i * N + j] = sum;
        }
    }

    vector<int> C;
    if (rank == 0) C.resize(N * N);

    MPI_Gather(
        localC.data(), rowsPerProcess * N, MPI_INT,
        C.data(), rowsPerProcess * N, MPI_INT,
        0, MPI_COMM_WORLD
    );

    if (rank == 0) {
        cout << "Final result (C matrix):" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << C[i * N + j] << " ";
            cout << endl;
        }
    }

    MPI_Finalize();
    return 0;
}
