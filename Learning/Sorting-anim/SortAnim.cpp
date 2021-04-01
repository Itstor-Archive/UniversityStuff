#include <graphics.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int number[500];
    int i = 0;

    initwindow(500, 300);

    for (int i = 0; i<500; i++){
        number[i] = rand() % 1500;
//        line(i, 300, i, 300 - number[i]/5);
    }

    while(i<500){
        if (i<500){
            for (int k= 0; k<500-i-1; k++){
                if (number[k+1]<number[k]){
                    swap(number[k], number[k+1]);
//                    cout << "SWAP" << endl;
                }
            }
        }
        i++;
        for (int j = 0; j < 500; j++) {
            line(j, 300, j, 300 - number[j]/5);
        }
        delay(25);
        if (i<500) cleardevice();
    }

    getch();
}
