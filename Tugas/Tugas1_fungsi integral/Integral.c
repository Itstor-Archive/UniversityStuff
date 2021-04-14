#include <stdio.h>

float f(float x);
float findArea(int from, int to);

int main(){
    int from, to;

    scanf("%d %d", &from, &to);
    printf("Hasil dari %f", findArea(from, to));
}

float f(float x){
    return 1/(1+(x*x));
}

float findArea(int from, int to){
    float Dx = 0.001;
    float area = 0;
    float i;
    for (i = from + Dx; i<=to; i+=Dx){
        area+=f(i)*Dx;
    }
    return area;
}
