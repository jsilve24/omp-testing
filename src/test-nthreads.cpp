// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// test number of cores

#include <fido.h>
#include <iostream>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void get_threads(int nthreads) {
    omp_set_num_threads(nthreads); 

    #pragma omp parallel for 
    for(int i = 0; i < 5; i++){
        int tid = omp_get_thread_num();
        std::cout<<tid<<"\t tid"<<std::endl;
        int nThreads = omp_get_num_threads();
        std::cout<<nThreads<<"\t nThreads"<<std::endl;
    }
}
