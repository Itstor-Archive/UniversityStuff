#include <stdio.h>
 
int main(){
    int x, y;
 
    scanf("%d%d", &x, &y);
 
    for (int i=x; i<=y; i++){
        if (i > 30){
            break;
        }
        if (i%2==0){
            if (i<=9){
                continue;
            } else {
                printf("genap\n");
            } 
        } else {
            if (i<=9) {
                switch (i) {
                    case 1: printf("satu\n"); break;
                    case 3: printf("tiga\n"); break;
                    case 5: printf("lima\n"); break;
                    case 7: printf("tujuh\n"); break;
                    case 9: printf("sembilan\n"); break;
                    default: break;
                }
            } else {
                printf("ganjil\n");
            }
        }
    }
}