#include <stdio.h>

int main(){
    int Enternum;
    printf("Please Enter any number: ");
    if(scanf("%d", &Enternum) != 1){
        printf("This is not a number goodby!");
        return 1;
    }
    for(int i = 1; i <= Enternum; i++){
        printf("[%d] Hello world\n", i);
    }
    
    return 0;
}