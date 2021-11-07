
#include<stdio.h>  
#include<time.h> 
#include<stdlib.h>  



/* produit de matrice superieur avec matrice superieur */

int get_random_number(){
    return rand()%100 ;
}


void remplir_mat_tri_sup(int **mat,unsigned n){
    unsigned i;
    unsigned j;
    for(i=0 ; i<n;i++){
        for(j=i;j<n;j++){
            mat[i][j] = get_random_number();
        }
    }
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


void produit_mat_tri_sup_avec_mat_tri_sup(int **mat1,int **mat2,unsigned n){
    int **res ;
    unsigned i;
    unsigned j;
    unsigned k;

    res=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        res[i]=(int*)calloc(n,sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            for(k=i;k<=j;k++){
                res[i][j]=res[i][j]+mat1[i][k]*mat2[k][j];
            }
        }
    }
    affiche_matrice(res,n);
}







int main(){
    int **mat1;
    int **mat2;
    unsigned n;
    unsigned i;
    printf("donner le taille de votre matrice: ");
    scanf("%u",&n);
    mat1 =(int**)malloc(sizeof(int*)*n);
    mat2 =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        mat1[i]=(int*)calloc(n,sizeof(int));
    }
    for(i=0;i<n;i++){
        mat2[i]=(int*)calloc(n,sizeof(int));
    }
    remplir_mat_tri_sup(mat1,n);
    printf("\n\n-------------------------matrice1-------------------------\n\n");
    affiche_matrice(mat1,n);
    remplir_mat_tri_sup(mat2,n);
    printf("\n\n-------------------------matrice2-------------------------\n\n");
    affiche_matrice(mat2,n);
    printf("\n\n-------------------------reasultat-------------------------\n\n");
    produit_mat_tri_sup_avec_mat_tri_sup(mat1,mat2,n);

    return 0 ;
}