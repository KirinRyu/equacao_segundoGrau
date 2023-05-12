#include <stdio.h>
#include <locale.h>
#include <math.h>

//Arthur Duvareski
//Daniel Satoy

int verificacao(int f);
int deltafunc(int x, int y, int z);
float* raizesfunc(float xr, float yr, float deltar);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int a, b, c, delta;
    float d, e;
    float *resultado;

    printf("Digite os valores de a, b e c (respectivamente) para uma função de segundo grau:\n");
    scanf("%d %d %d", &a, &b, &c);

    a = verificacao(a); //a != 0
    printf("A função gerada foi:\n (%d^2)x + (%d)x + (%d)\n",a,b,c);

    delta = deltafunc(a,b,c);

    resultado = raizesfunc(a,b,delta);
    if(resultado[0] != -1){
        printf("E suas soluções são: %.02f e/ou %.02f",resultado[0],resultado[1]);
    }

    return 0;
}

int verificacao(int f){
    while(f==0){
        printf("Digite um número diferente de zero para a\n");
        scanf("%d", &f);
    }
    return(f);
}

int deltafunc(int x, int y, int z){
    float delt;
    delt = (y*y) - 4*x*z;
    return(delt);
}

float* raizesfunc(float xr, float yr, float deltar){
    static float raizes[2];
    if(deltar < 0){
        printf("A função não possui raízes reais\n");
        raizes[0] = -1;
    }else{
        raizes[0] = (-(yr) + sqrt(deltar))/2*xr;
        raizes[1] = (-(yr) - sqrt(deltar))/2*xr;
    }
    return raizes;
}
