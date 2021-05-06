#include <stdio.h>
 
int main(){
    int x, y;
 
    scanf("%d%d", &x, &y);
 
    if (x>0 && y>0){
        printf("Titik berada di kuadran 1");
    }
    if (x<0 && y<0){
        printf("Titik berada di kuadran 3");
    }
    if (x<0 && y>0){
        printf("Titik berada di kuadran 2");
    }
    if (x>0 && y<0){
        printf("Titik berada di kuadran 4");
    }
}