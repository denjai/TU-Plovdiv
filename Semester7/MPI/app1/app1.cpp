// app1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mpi.h"
#define MASTER 50
#define WORKER 60

int main (int argc,char **argv)
{
  int matrix[3][3];
  int vector[3];
  int result[3];
  MPI_Request req;
  MPI_Status status;
  int i, j, nproc, myrank, res;
  
  res = MPI_Init(&argc,&argv);
  res = MPI_Comm_size(MPI_COMM_WORLD,&nproc);
  res = MPI_Comm_rank(MPI_COMM_WORLD,&myrank);

  if (res != MPI_SUCCESS)
      printf ("error initializing MPI and obtaining task ID information\n");
  else
      printf ("task ID = %d\n", myrank);

  if (nproc!=3)
    return 0;

  if (myrank == 0)
  //Master: init matrix and vector; send rows to workers; calc first row and print a result
  {
    for (i=0;i<3;i++)
    {
      vector[i] = i*i;
      for (j=0;j<3;j++)
        matrix[i][j] = i+j;
    }

    for (i=1;i<3;i++)
    { 
       MPI_Send(&matrix[i][0], 3, MPI_INT, i, MASTER, MPI_COMM_WORLD);    
       MPI_Send(&vector, 3, MPI_INT, i, MASTER, MPI_COMM_WORLD);    
    }

    result[0] = matrix[0][0]*vector[0] + matrix[0][1]*vector[1] + matrix[0][2]*vector[2];  

    for (i=1;i<3;i++)
      MPI_Recv(&result[i], 1, MPI_INT, i, WORKER, MPI_COMM_WORLD, &status);

    for (i=0;i<3;i++)
      printf("Result %i = %i \n", i, result[i]);
  }
  
  if (myrank>0)
  //Worker: recive rows from master, calc element from result and send him to master
  {
    MPI_Recv(&matrix[myrank][0], 3, MPI_INT, 0, MASTER, MPI_COMM_WORLD, &status);       
   MPI_Recv(&vector, 3, MPI_INT, 0, MASTER, MPI_COMM_WORLD, &status);
    
   result[myrank] = matrix[myrank][0]*vector[0] + matrix[myrank][1]*vector[1] + matrix[myrank][2]*vector[2];

   MPI_Send(&result[myrank], 1, MPI_INT, 0, WORKER, MPI_COMM_WORLD);
  }

  MPI_Finalize();
}
