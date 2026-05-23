#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int N = 10000000;   // 10 million
    vector<int> data;

    // Root generates data
    if (rank == 0) {
        data.resize(N);
        for (int i = 0; i < N; i++)
            data[i] = i;  // 0,1,2,3...
    }

    int local_n = N / size;
    vector<int> local(local_n);

    // Scatter data
    MPI_Scatter(
        data.data(), local_n, MPI_INT,
        local.data(), local_n, MPI_INT,
        0, MPI_COMM_WORLD
    );

    // Value to search:
    int target = 9999993; // test
    int local_result = -1;

    // Local search
    for (int i = 0; i < local_n; i++) {
        if (local[i] == target) {
            local_result = i + rank * local_n;  // global index
            break;
        }
    }

    // Gather results
    vector<int> results;
    if (rank == 0)
        results.resize(size);

    MPI_Gather(&local_result, 1, MPI_INT,
               results.data(), 1, MPI_INT,
               0, MPI_COMM_WORLD);

    // Root checks global existence
    if (rank == 0) {
        bool found = false;
        int index = -1;

        for (int r : results) {
            if (r != -1) {
                found = true;
                index = r;
                break;
            }
        }

        if (found)
            cout << "Value FOUND at global index: " << index << endl;
        else
            cout << "Value NOT FOUND" << endl;
    }

    MPI_Finalize();
    return 0;
}
