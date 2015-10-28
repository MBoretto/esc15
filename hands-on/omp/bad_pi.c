/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main ()
{
	  double x, pi = 0.0;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;

        	 
	  start_time = omp_get_wtime();
      omp_set_num_threads(2);
      int n_threads = omp_get_num_threads();
      int steps_per_threads = num_steps/n_threads;
      double partial_sum[n_threads];

      #pragma omp parallel
      {

	      double sum = 0.0;

          int ID = omp_get_thread_num();
	      printf("ID %d \n ",ID);
          int range_min = 1 + steps_per_threads * ID;
          int range_max = steps_per_threads * (ID +1);
          if(ID == n_threads -1){
              range_max = num_steps;
          }

	      int i;
	      for (i = range_min; i <= range_max ; i++){
	      //for (i=1;i<= num_steps; i++){
	          x = (i-0.5)*step;
	          sum = sum + 4.0/(1.0+x*x);
	      }
          partial_sum[ID];
      }
      double sum_tot =0.0 ;
      for(int a = 0; a< n_threads; ++a){
         sum_tot += partial_sum[a]; 
      }

	  pi = step * sum_tot;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}	  





