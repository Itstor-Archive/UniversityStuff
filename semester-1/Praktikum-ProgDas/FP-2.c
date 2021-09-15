#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Prototype Function*/
int isVokal(char a);
int jKonsoSeb(char string[], int start);
int jKonsoSet(char string[], int start);
void printSisa(char string[], int n, int start);

/*Main Function*/
int main(){
    char text[200];
    int jumlahSeb, jumlahSet;
    gets(text);
    for (int i=0; i<strlen(text); i++){
        if (isVokal(text[i])){
            jumlahSeb = jKonsoSeb(text, i);
            jumlahSet = jKonsoSet(text, i);

            switch (jumlahSeb){
            case 1: printf("%c", text[i-1]); break;
            case 2:
                if (text[i-2] == 'n' && (text[i-1] == 'g' || text[i-1] == 'y')){
                    if (text[i-1] == 'g') printf("ng");
                    else printf("ny");         
                } else if ((text[i-3] >= 32 && text[i-3] <= 64) || i == 2){
                    printf("%c%c", text[i-2], text[i-1]);
                } else {
                    printf("%c", text[i-1]);
                }
                break;
            case 3: printf("%c", text[i-1]); break;
            case 4: printf("%c%c", text[i-2], text[i-1]); break;
            default: break;
            }

            printf("%c", text[i]);

            switch (jumlahSet){
            case 2: if (!(text[i+1] == 'n' && (text[i+2] == 'g' || text[i+2] == 'y'))) printf("%c", text[i+1]); break;
            case 3: case 4: printf("%c%c", text[i+1], text[i+2]); break;
            default: break;
            }
            
            if ((text[jumlahSet+i+1] >= 32 && text[jumlahSet+i+1] <= 64) || text[jumlahSet+i+1] == '\0')
                printSisa(text, i, jumlahSet);
            if (isVokal(text[jumlahSet+i+1]) || (!isVokal(text[jumlahSet+i+1]) && text[jumlahSet+i+1]<=122 && text[jumlahSet+i+1]>=97))
                printf("-");
        }
        if (text[i] >= 32 && text[i] <= 64) printf("%c", text[i]);
    }
    getch();
}

/*Check Function*/
void printSisa(char string[], int start, int n){
    start++;
    for (int i=start; i<start+n; i++)
        printf("%c", string[i]);
}

int isVokal(char a){
    char vokal[] = {'a', 'i', 'u', 'e', 'o'};
    a = tolower(a);
    for (int i=0; i<5; i++){
        if (vokal[i] == a)
            return 1;
    }
    return 0;
}

int jKonsoSeb(char string[], int start){
    int total = 0;
    for (int i=start-1; i>=0; i--){
        char a = tolower(string[i]);
        if (!isVokal(a) && a<=122 && a>=97)
            total++;
        else
            break;
    }
    return total;
}

int jKonsoSet(char string[], int start){
    int total = 0;
    for (int i=start+1; i<strlen(string); i++){
        char a = tolower(string[i]);
        if (!isVokal(a) && a<=122 && a>=97)
            total++;
        else
            break;
    }
    return total;
}