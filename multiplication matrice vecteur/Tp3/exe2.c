#include<stdio.h>  
#include<time.h> 
#include<stdlib.h>  




int get_random_number(){
    return rand()%100 ;
}


void affiche_matrice(int **mat,unsigned n){
    printf("\n\n-------------------------------------------------------------------\n");
    int i;
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]>9)
            printf("     %d     |",mat[i][j]);
            else
            printf("     %d      |",mat[i][j]);
        }
        
    printf("\n-------------------------------------------------------------------\n");
        
    }
}

void remplir_matrice(int **mat,unsigned n){
    unsigned i ;
    unsigned j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j]=get_random_number();
        }
    }
}


void produit_matrice(int **mat1,int **mat2,unsigned n){
    unsigned i;
    unsigned j;
    unsigned k;
    int **res =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        res[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            res[i][j]=0;
            for(k=0;k<n;k++){
                res[i][j]=res[i][j]=0+mat1[i][k]*mat2[k][j];
            }
        }
    }

    affiche_matrice(res,n);


}


int main(){
    int **mat1 ;
    int **mat2 ;
    unsigned n;
    unsigned i;
    printf("donner matrice taille : ");
    scanf("%u",&n);
    mat1 = (int**)malloc(sizeof(int*)*n);
    mat2 = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        mat1[i] = (int*)malloc(sizeof(int)*n);
        mat2[i] = (int*)malloc(sizeof(int)*n);
    }
    remplir_matrice(mat1,n);
    printf("\n_____matrice1_____\n");
    affiche_matrice(mat1,n);


    remplir_matrice(mat2,n);
    printf("\n_____matrice2_____\n");
    affiche_matrice(mat2,n);

    printf("\n_____resultat_____\n");
    produit_matrice(mat1,mat2,n);
    return 0;
}