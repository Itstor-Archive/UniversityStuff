#include <stdio.h>
 
int main(){
    int sport;
 
    scanf("%d", &sport);
    switch (sport)
    {
    case 1: printf("Olahraga favoritmu adalah renang"); break;
    case 2: printf("Olahraga favoritmu adalah basket"); break;
    case 3: printf("Olahraga favoritmu adalah volly"); break;
    case 4: printf("Olahraga favoritmu adalah sepak bola"); break;
    case 5: printf("Olahraga favoritmu adalah catur"); break;
    default:
        break;
    }
}