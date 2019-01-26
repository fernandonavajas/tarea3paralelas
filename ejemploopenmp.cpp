#include <omp.h>
#include <iostream>
 using namespace std;
int main (){
double iniciador= omp_get_wtime(),total=0;
double finalizador=0;
int nthreads;
int thread;
 
//omp_set_num_threads(1);
#pragma omp parallel private(nthreads, thread)
  {
	 
	  thread = omp_get_thread_num();// el numero del procesador
	 
	  nthreads = omp_get_num_threads();// la cantidad de procesadores
	  if(thread==1){
		std::cout<<"Proce N°"<< thread <<" de "<<nthreads<<".";
	  }
	}
  finalizador=omp_get_wtime();
  total=finalizador-iniciador;
  cout<<"Tiempo que se demoro: "<<total<<" segundos"<<endl;
 
}
