#include <stdio.h>  
#include <time.h> 
#include <stdlib.h>  


/*

multiplication matrice triangulaire inférieur par vecteur


*/

/*cette fonction retourne un nombre entre 1 .. 100*/
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

void remplir_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        tab[i]=get_random_number();

    }
}

void affiche_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d |",tab[i]);
       

    }
    printf("\n");
}

void produit_mat_tri_sup_vect(int **mat,int *tab,unsigned n){
    unsigned i;
    unsigned j;
    int x;
    int *resultat=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        x=0;
        for(j=i;j<n;j++){
            x=x+(mat[i][j]*tab[i]);
        }
        resultat[i]=x;
    } 
    affiche_tab(resultat,n);
}


int main(){
    int **mat ;
    int *tab;
    unsigned n;
    unsigned i;
    printf("donner le taille de votre matrice: ");
    scanf("%u",&n);
    tab=(int*)malloc(sizeof(int)*n);
    mat =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        mat[i] =(int*)calloc(n,sizeof(int));

    }
    remplir_mat_tri_sup(mat,n);
    printf("\n\n                  votre mat                  ");
    affiche_matrice(mat,n);
    remplir_tab(tab,n);
    printf("\n\n                  votre vec                   \n\n");
    affiche_tab(tab,n);
    printf(" \n\n");
    printf("\n\n                  votre res                  \n\n");
    produit_mat_tri_sup_vect(mat,tab,n);
    printf(" \n\n");
}