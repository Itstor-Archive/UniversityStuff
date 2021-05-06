#include <stdio.h>
 
int main(){
    int x, n;
 
    scanf("%d%d", &x, &n);
 
    for (int i; i<n; i++){
        if (x % 10 == 0){
            x = x / 10;
        } else {
            x = x - 1;
        }
    }
    printf("%d", x);
}