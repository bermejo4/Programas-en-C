#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>
#define TUR_SIZE 4
#define MAX_TAR 24

int car[TUR_SIZE];
int counter = 0;
sem_t num_asient;

void arrancar()
{
    printf("");
    sem_wait(&num_asient);
}
void bajar()
{
    for (int i = 0; i < 4; i++)
    {
        sem_post(&num_asient);
    }
}
void *generar(void *args)
{
    while (counter < MAX_TAR)
    {
        int num_ale = (int)(rand() % (MAX_TAR - counter));
        printf("Acaban de llegar %i turistas", num_ale);
        printf("Hay %i que todavía no han disfrutado del Dino.", MAX_TAR-counter);
        arrancar();
        counter + num_ale;
    }
}
void turista_vive(void* experience){

}
void coche_arranca(){
    
}

int main(int argc, char const *argv[])
{
    pthread_t coche;
    pthread_t turista[MAX_TAR];

    for (int i = 0; i < MAX_TAR; i++)
    {
        pthread_create(&turista[i],NULL,turista_vive,(void*) 0l);
    }
    pthread_create(&coche, NULL, coche_arraca, (void*) 0l)
    pthread_create(&generador, NULL, generar, (void *)0l);
    sem_init(&num_asient, 0, TUR_SIZE);

    sem_destroy(&num_asient);
}
