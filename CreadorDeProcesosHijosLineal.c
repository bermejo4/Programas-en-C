#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>

//Programa en C que crea procesos hijos a través de fork de una forma lineal.
//Crea el mismo numero de procesos que argumentos se le pasa.
//Ejemplo: ./CreadorDeProcesosHijosLineal a b c
//El programa creará un proceso "a" del que creara un proceso "b" del cual creará un proceso "c"
//todo ello de una forma lineal, siendo el hijo de uno el padre del siguiente y sin bifurcaciones
//ni ramificaciones.

int compararPID(int array[], int num, int bucle){
  int check=1;
  int i;
  for(i=0; i<bucle; i++){
    if(array[i]==num){
      check=0;
    }
  }
  return check;
}

int main(int argc, char const *argv[]) {
  int i;
  pid_t forks[argc];
  int guardadPID[argc];
  printf("SOY EL PROCESO PROCESO SUPREMO, Y MI PID ES %d\n",getpid());

  //inicialización del guardadPID
  for (i=0; i<argc; i++) {
    guardadPID[i]=0;
  }


  printf("\nEjecutando el programa invocador %s \nSus argumentos son:\n",argv[0]);
  for (i = 1; i < argc; i++) {
    printf("argv[%d]: %s\n",i, argv[i]);
  }

  printf("\nSe han pasado %d argumentos por lo tanto se crearán %d procesos\n",argc-1,argc-1);

  for(i=0; i< argc; i++){
    if(i!=0){
    //printf("Dentro de argv[%d]: %s\n",i,argv[i]);
    if(compararPID(guardadPID,getpid(),argc)==1){
    printf("\nProceso creado...\n" );
    guardadPID[i]=getpid();
    forks[i]=fork();
    switch (forks[i]) {
      case -1: printf("No se ha podido crear el proceso hijo en la vuelta del bucle %d\n", i);
      break;
      case 0: printf("Soy el proceso hijo creado, mi PID es %d y mi PPID es %d \n", getpid(), getppid());
      break;
      default: printf("Soy el proceso padre, mi PID es %d y el PID de mi hijo es %d\n",getpid(), forks[i]);
      wait(0);
    }
  }
  }
}
}
