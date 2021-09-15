#include <stdio.h>
 
int fibke(int number){
    if (number <= 1){
        return 1;
    }
    return fibke(number-1) + fibke(number-2);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("Fibonnaci ke %d adalah %d", n, fibke(n-1));
}