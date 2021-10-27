#include<stdio.h>



int main(){
    int n ; 
    do{
    printf("donner n :");
    scanf("%d",&n);
    }while (!(n<50 && n>0) );
    int i = 0;
    int tab[n];
    for(;i<n;i++){
        printf("donner tab[%d]:",i);
        scanf("%d",&tab[i]);
    }
    i=0;
    printf("-------------------\n");
    printf("[ ");
    for(;i<n;i++){
        
        printf("%d",tab[i]);
        printf(",");

    }
    printf(" ]");

    return 0 ;
}