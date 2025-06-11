#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Prototipos de las funciones de los hilos
void *sim_co2_thread(void *arg);
void *sim_h20_thread(void *arg);
void *sim_pos_thread(void *arg);

int main() {
    pthread_t thread_co2, thread_h20, thread_pos;
    int rc;
    
    printf("Iniciando simuladores con hilos...\n");
    
    // Crear hilos para cada simulador
    rc = pthread_create(&thread_co2, NULL, sim_co2_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error al crear hilo CO2: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    
    rc = pthread_create(&thread_h20, NULL, sim_h20_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error al crear hilo H20: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    
    rc = pthread_create(&thread_pos, NULL, sim_pos_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error al crear hilo POS: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    
    // Esperar a que todos los hilos terminen
    pthread_join(thread_co2, NULL);
    pthread_join(thread_h20, NULL);
    pthread_join(thread_pos, NULL);
    
    printf("\nTodos los simuladores han terminado\n");
    return EXIT_SUCCESS;
}

// Implementación del simulador de CO2 como hilo
void *sim_co2_thread(void *arg) {
    char s[2];
    int i;
    
    srand(time(NULL) ^ pthread_self());
    
    for (i = 0; i < 20; i++) {
        sleep(1);
        sprintf(s, "%1d", rand() % 6);
        write(1, s, 1);
        fflush(stdout);
    }
    
    pthread_exit(NULL);
}

// Implementación del simulador de H20 como hilo
void *sim_h20_thread(void *arg) {
    char s[2];
    int i;
    
    srand(time(NULL) ^ pthread_self());
    
    for (i = 0; i < 20; i++) {
        sleep(1);
        sprintf(s, "%1c", rand() % 6 + 'a');
        write(1, s, 1);
        fflush(stdout);
    }
    
    pthread_exit(NULL);
}

// Implementación del simulador de posición como hilo
void *sim_pos_thread(void *arg) {
    char p = 'N';
    int i;
    
    srand(time(NULL) ^ pthread_self());
    
    for (i = 0; i < 10; i++) {
        write(1, &p, 1);
        fflush(stdout);
        sleep(rand() % 5 + 1);
        p = p + rand() % 7 - 3;
        if (p < 'A') p = 'A';
        if (p > 'Z') p = 'Z';
    }
    
    pthread_exit(NULL);
}
