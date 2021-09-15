#include <stdio.h>
 
int main(){
    int n, ganjil, genap;
    char kelas;
    scanf("%d", &n);
    int nilai[n];
 
    for (int i=0; i<n; i++){
        scanf("%d", &nilai[i]);
        if (i%2==0){
            genap += nilai[i];
        } else {
            ganjil += nilai[i];
        }
    }
    scanf("%s", &kelas);
    if (kelas == 'A') printf("%d", genap);   
    else if (kelas == 'B')printf("%d", ganjil);
    else printf("ERROR");
}