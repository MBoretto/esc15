/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

This is the sequenctial version of the program.  It uses
the OpenMP timer.

History: Written by Tim Mattson, 11/99.

*/
#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <mpi.h>
static long num_steps = 100000000;
double step;
int main (int argc, char **argv)
{
   int i;
   double x, pi, sum = 0.0;
   double start_time, run_time = 0;

   int size, rank;
   
   MPI_Init (&argc, &argv); 
   MPI_Comm_rank (MPI_COMM_WORLD, &rank); 
   MPI_Comm_size (MPI_COMM_WORLD, &size);

   step = 1.0/(double) num_steps;

   start_time = omp_get_wtime();

   #pragma omp parallel for reduction(+:sum)
   for (i = rank; i<= num_steps; i+=size){
      x = (i+0.5)*step;
      sum = sum + 4.0/(1.0+x*x);
   }
   sum *= step;

   MPI_Reduce(&sum, &pi, 1 ,MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

   if(rank == 0){
      run_time = omp_get_wtime() - start_time;
      printf("\n pi with %ld steps is %lf in %lf seconds\n",
                          num_steps,pi,run_time);
   } 

   MPI_Finalize(); 
}	  
