#include <math.h>
#include <stdio.h>
int main(){
    char c = 66;
    int arr[254], i =0;
    for (i = 0; i < 255; i++)
    {
        arr[i]=0;
    }
    do{
        c = getchar();
        if(c > 0 && c < 256){
        arr[c-1]++;
        printf("%c", c);
        }
    }while (c > 0 && c < 256);
    
}