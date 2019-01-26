#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "menu.h"
#include "Matriz.h"
#include <omp.h>
using namespace std;
int main(int argc, char** argv) {
	
	double iniciador= omp_get_wtime(),total=0;
	double finalizador=0;
	int nthreads;
	int thread;
	nthreads = omp_get_num_threads();
	cout<<"Numero de procesadores: "<<nthreads<<endl;
	
    if (argc > 4) {
        string archivo_entrada(obtener_entrada(argv, argc));
        string archivo_salida(obtener_salida(argv, argc));

        if (!archivo_entrada.empty() && !archivo_salida.empty()) {

            std::ifstream entrada(archivo_entrada);
            std::ofstream salida(archivo_salida);
            std::string linea;
            //aqui se puede paralelizar
            while (std::getline(entrada, linea)) { //toma linea por linea
                Matriz matriz(linea);
                if (matriz.esMagico()) {
                    std::string str = matriz.toString();
                    salida.write(str.c_str(), str.size());
                }

                linea.clear();
            }

            entrada.close();
            salida.close();

            return EXIT_SUCCESS;
        } else {
            std::cerr << std::endl << "Error al determinar las rutas de los archivos de entrada " << archivo_entrada << " y salida " << archivo_salida << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        std::cerr << std::endl << "Argumentos insuficientes" << std::endl;
        std::cerr << std::endl << argv[0] << " -f /ruta/archivo/entrada.txt -o /ruta/archivo/salida.txt" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  finalizador=omp_get_wtime();
  total=finalizador-iniciador;
  cout<<"Tiempo que se demoro: "<<total<<" segundos"<<endl;
}

