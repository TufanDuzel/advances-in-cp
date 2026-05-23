#include <iostream>
#include <mpi.h>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    char hostname[256];
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    gethostname(hostname, 256);

    int local_variable = 100 + rank;

    cout << "Rank " << rank
         << " running on machine: " << hostname
         << " | Address of variable: " << &local_variable
         << endl;

    MPI_Finalize();
    return 0;
}
