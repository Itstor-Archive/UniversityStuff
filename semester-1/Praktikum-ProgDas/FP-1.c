/*
DICTIONARY
FUNCTION
firstDate = function to determine first day of week
isLeap = to determine wether year leap or not
printCalendar = to print calendar

VARIABLE
dim = total of day in one month
nod = Name of Day
nom = Name of Month
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define PADDING 7

/*Global Variable*/
const char *nod[8] = {"NULL", "Min", "Sen", "Sel", "Rab", "Kam", "Jum", "Sab"};
const char *nom[13] = {"NULL", "Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Augustus", "September", "Oktober", "November", "Desember"};

/*Protorype Function*/
int firstDate(int m, int y);
int isLeap (int y);
void printCalendar (int m, int y);

/*Main Function*/
void main(){
    int month, year, update;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=KALENDAR=-=-=-=-=-=-=-=-=-=-=-=-\n");
input:
    printf("Masukkan bulan dan tahun (mm yyyy): ");
    scanf("%d %d", &month, &year);
    update = 1;
    while (1){
        if (update) printCalendar(month, year);
        update = 0;
        if (_kbhit()){
            switch (_getch()){
                case 77: month++; update++; break;
                case 75: month--; update++; break;
                case 113: goto exitloop; break;
                case 105: goto input; break;
                default: break;
            }
            if (month > 12){
                month = 1;
                year++;
            } else if (month < 1){
                month = 12;
                year--;
            }
        }
    }
exitloop:
printf("EXIT. Calendar by Akhmad Thoriq Afif");
}

/*Oother Function*/
int firstDate(int m, int y){
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + "-bed=pen+mad."[m] + 1) % 7 + 1;
}

int isLeap (int y){
    return y % 100 != 0 && y % 4 == 0 || y % 400 == 0? 1:0;
}

void printCalendar(int m, int y){
    int row = 1, col = 1, datenum = 1, fd;
    int dim[13] = {0, 31, 28+isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    fd = firstDate(m, y);

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%*s %d%*s\n", 21+strlen(nom[m])/2+4, nom[m], y, 21+strlen(nom[m])/2+4, "");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    for (; datenum <= dim[m]; col++){
        row = 1;
        for (; row <= 7; row++){
            if (col == 1) printf("%*s ", PADDING, nod[row]);
            if (col > 1 && datenum <= dim[m]) {
                if (col == 2 && row < fd) printf("%*s ", PADDING, "");
                if (row >= fd || datenum > 8-fd){ 
                    printf("%*d ", PADDING, datenum);
                    datenum++; 
                }
            }
        }
        printf("\n");
    }

    printf("%-*s (i)nput (q)uit %*s\n", 13+PADDING, "<----", 13+PADDING,"---->");
}