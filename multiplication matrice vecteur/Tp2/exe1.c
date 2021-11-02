#include<stdio.h>
#include<stdlib.h>
/*

multiplication matrice simple par vecteur


*/

void remplir_matrice(int **mat,unsigned  n){
    int i;
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("donner mat[%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void affiche_matrice(int **mat,unsigned n){
    printf("\n\n-------------------------------------------\n");
    int i;
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("     %d     |",mat[i][j]);
        }
        
    printf("\n-------------------------------------------\n");
        
    }
}

void remplir_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf("donner tab[%d]: ",i);
        scanf("%d",&tab[i]);

    }
}

void affiche_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d |",tab[i]);
       

    }
    printf("\n");
}

void produit_mat_vect(int **a,int *b,unsigned n){
    int i;
    int j;
    int cout= 0;
    int *t =(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        t[i]=0;
        for(j=0;j<n;j++){
            t[i]=t[i]+(a[i][j] * b[i]);
            cout += 2;
        }

    }
    affiche_tab(t,n);
    printf("cout= %d \n",cout);
}

int main(){
    unsigned n;
    int i ;
    int *tab ;
    printf("donner n: ");
    scanf("%u",&n);
    tab =(int*)malloc(sizeof(int)*n);
    int **A=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
       A[i]=(int*)calloc(n,sizeof(int));
    }
    printf("\n\n\n1)remplisage de matrice \n");
    remplir_matrice(A,n);
    /*
    affiche_matrice(A,n);
    */
    printf("\n\n\n2)remplisage de tableau \n");
    remplir_tab(tab,n);
    printf("\n\n\nvoici votre resultat: ");
    produit_mat_vect(A,tab,n);
    
    return 0; 
}