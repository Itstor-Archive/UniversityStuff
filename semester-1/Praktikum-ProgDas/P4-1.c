#include <stdio.h>
 
int main(){
    char str[99];
    int x, y;
 
    scanf("%s", &str);
    scanf("%d %d", &x, &y);
 
    for (int i=x; i<y; i++){
        str[i] = '*';
    }
    printf("%s", str);
}