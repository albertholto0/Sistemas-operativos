#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    //FILE* fd;
    char c;
        int i;
        float j;
   if ((argc > 1)) {
        fprintf(stderr, "Error de argumentos\n");
        exit(1);
        }
    while ((c=getchar()) != EOF) {
        i =(int)(c-'0');
        if(i>=0 && i<=5){
                j=(float)i/(float)5;//1
                fprintf(stdout, "%.1f\n",j);
            }
            else{
                fprintf(stderr, "%d\n", i);
            }
    }
}



