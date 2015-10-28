#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <omp.h>


int main(int argc, char **argv)
{

std::string s("");
#pragma omp parallel
{
    #pragma omp master
    {
        #pragma omp task
        s ="I think race cars are fun";
        #pragma omp task
        s ="I think car race are fun";
    }
}
std::cout<<s<<'\n';
}
