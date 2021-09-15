#include <stdio.h>
 
int main(){
    int input, sum;
    while (input != -999){
        scanf("%d", &input);
        if (input<0){
            continue;
        } else {
            sum += input;
        }
    }
    printf("%d", sum);
}