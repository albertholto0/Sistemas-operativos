// ejecuta_simuladores.c
// Ejecuta los simuladores específicos del proyecto
//////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

// Ruta base donde se encuentran los ejecutables
#define BASE_PATH "/home/albertholto/Sistemas-operativos/PCL/Proyectos/P03/A03.1/"

int main() {
    // Nombres de los programas a ejecutar
    const char *programas[] = {"sim_C02", "sim_H20", "sim_pos"};
    int num_programas = sizeof(programas) / sizeof(programas[0]);
    
    printf("Iniciando ejecución de simuladores...\n");
    
    for (int i = 0; i < num_programas; i++) {
        // Construir la ruta completa al ejecutable
        char ruta_completa[256];
        snprintf(ruta_completa, sizeof(ruta_completa), "%s%s", BASE_PATH, programas[i]);
        
        pid_t pid = fork();
        
        if (pid == -1) {
            perror("Error en fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { // Proceso hijo
            printf("Ejecutando: %s\n", programas[i]);
            
            // Ejecutar el programa
            execl(ruta_completa, programas[i], NULL);
            
            // Si execl falla:
            perror("Error en execl");
            exit(EXIT_FAILURE);
        }
    }
    
    // Esperar a que todos los hijos terminen
    for (int i = 0; i < num_programas; i++) {
        int status;
        pid_t child_pid = wait(&status);
        
        if (WIFEXITED(status)) {
            printf("%d terminó con estado: %d\n", child_pid, WEXITSTATUS(status));
        } else {
            printf("%d terminó anormalmente\n", child_pid);
        }
    }
    
    printf("Todos los simuladores han terminado\n");
    return EXIT_SUCCESS;
}
