/* A et B 2 matrices sont diffetent */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h> 


int get_random_number(){
    return rand()%100 ;
}


void affiche_matrice_non_caree(int **mat,unsigned n,unsigned m){
    printf("\n\n-------------------------------------------------------------------\n");
    int i;
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]>9)
            printf("     %d     |",mat[i][j]);
            else
            printf("     %d      |",mat[i][j]);
        }
        
    printf("\n-------------------------------------------------------------------\n");
        
    }
}


void remplir_matrice_non_carre(int **mat,unsigned n,unsigned m){
    /*avec n est le nombre de ligne et m nombre de clonne */
        
    unsigned i ;
    unsigned j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            mat[i][j]=get_random_number();
        }
    }

}

void produit_matrices_differents(int **mat1,unsigned n1,unsigned m1,int **mat2,unsigned n2,unsigned m2){
    /* (3,2)(2,3) */
    unsigned i ;
    unsigned j ;
    unsigned k ;
    int **res ;
 
    res = (int**)malloc(sizeof(int*)*n1);
    for(i=0;i<n1;i++){
      res[i]=(int*)calloc(m2,sizeof(int))  ;
    }
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            for(k=0;k<m1;k++){
                res[i][j]=res[i][j]+mat1[i][k]*mat2[k][j];
            }
        }
    }

    affiche_matrice_non_caree(res,m1,n2);


}

int main(){
    int **mat1;
    int **mat2;
    unsigned n1;
    unsigned m1;
    unsigned m2;
    unsigned i;
    printf("donner nombre de ligne pour la matrice 1 :");
    scanf("%u",&n1);
    printf("donner nombre de colnne pour la matrice 1: ");
    scanf("%u",&m1);
    printf("donner nombre de colnne pour matrice 2: ");
    scanf("%u",&m2);
    mat1 = (int**)malloc(sizeof(int*)*n1);
    mat2 = (int**)malloc(sizeof(int*)*m1);
    for(i=0;i<n1;i++){
        mat1[i] = (int*)malloc(sizeof(int)*m1);
    }
    for(i=0;i<m1;i++){
        mat2[i] = (int*)malloc(sizeof(int)*m2);
    }
    remplir_matrice_non_carre(mat1,n1,m1);
    affiche_matrice_non_caree(mat1,n1,m1);
    remplir_matrice_non_carre(mat2,m1,m2);
    affiche_matrice_non_caree(mat2,m1,m2);

   produit_matrices_differents(mat1,n1,m1,mat2,m1,m2);
    
    return 0 ;
}