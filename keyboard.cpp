 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(CP_UTF8);
    while(true){
        char c = getch();
        printf("\nBan vua nhap phim %d", c);
    }
}