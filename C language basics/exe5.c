#include<stdio.h>
int main(){
    /*
    int M[5][5] = {1,2,3,4,5....}
    OR 
    int M[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},...}
    */
    int M[5][5];
    int i ;
    int j ;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            M[i][j] = i*j+3 ;
        }
    }
  

    for(i = 0;i<5;i++){
        for(j = 0;j<5;j++){
            if(M[i][j] > 9){
              printf("%d      ",M[i][j]) ;  
            }else{
                printf("%d       ",M[i][j]) ;
            }
            
        }
        printf("\n");
    }

    return 0 ;
}