#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

int setHoraCorte(const char horaSis[50], int horaCorte){
    int horaInt;
    int hor, min, seg;
    horaInt=atoi(horaSis);
    hor=horaInt/10000;
    min=(horaInt%10000)/100;
    seg=horaInt%100;
    //printf("%d %d %d", a, b, c);
    seg=seg+4;
    if(seg>59){
        min++;
        seg=seg-59;
    }
    if(min>59){
        hor++;
        min=min-59;
    }
    if (hor>23){
        hor=00;
    }
    horaCorte=((hor*10000)+(min*100)+seg);
    printf("%d", horaCorte);
    return horaCorte;
}

int main()
{
    time_t tiempo= time(0);
    struct tm *hora=localtime(&tiempo);
    char output[50];
    strftime(output, 50, "%H%M%S", hora);
    printf("%s\n", output);
    int horaCorte=0;
    horaCorte=setHoraCorte(output, horaCorte);
    int horaSistema=atoi(output);
    //printf("%d", horaSistema);
    while(horaSistema!=horaCorte){
        tiempo=time(0);
        struct tm *hora=localtime(&tiempo);
        strftime(output, 50, "%H%M%S", hora);
        horaSistema=atoi(output);
        printf("Avion despegando________________________________");
        system("cls");
    }
    printf("Avion en vuelo :)");
    return 0;
}
