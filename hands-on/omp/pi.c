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
#include <iostream>

static long num_steps = 100000000;
double step;
int main (int argc, char *argv[])
{
      std::string s(argv[1]);
      int const build_n_threads = atoi(s.c_str());

	  double pi, sum = 0.0;
	  double start_time, run_time;
      int shared_n_threads = 1;

      double part_sum[build_n_threads];

	  step = 1.0/(double) num_steps;

      omp_set_num_threads(build_n_threads);
	  start_time = omp_get_wtime();
      #pragma omp parallel
      {
          int ID = omp_get_thread_num();
          //std::cout<<"ID "<<ID<<'\n';
          int n_threads = omp_get_num_threads();
          if(ID == 0) shared_n_threads = n_threads;

	      double x = 0.0;
          part_sum[ID] = 0;
	      //for (i=1;i<= num_steps; i++){
	      for (int i=ID; i <= num_steps; i += n_threads){
	          x = (i-0.5)*step;
              part_sum[ID] += 4.0/(1.0+x*x);
	      }
      }
	  run_time = omp_get_wtime() - start_time;

      for (int i = 0; i < shared_n_threads; ++i)  pi += part_sum[i]*step;

	  printf("\n threads %d pi with %ld steps is %lf in %lf seconds\n",shared_n_threads, num_steps,pi,run_time);
}	  

