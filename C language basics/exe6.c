#include<stdio.h>
int main(){
    /*
    int M[5][5] = {1,2,3,4,5....}
    OR 
    int M[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},...}
    */
    int n ; 
    do{
    printf("donner n :");
    scanf("%d",&n);
    }while (!(n<50 && n>0) );
    int M[n][n];
    int i ;
    int j ;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("donner M[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    }
  printf("\n-------------------------------------\n\n\n");

    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++){
            if(M[i][j] > 9){
              printf("%d      ",M[i][j]) ;  
            }else{
                printf("%d       ",M[i][j]) ;
            }
            
        }
        printf("\n\n");
    }

    return 0 ;
}