#include<stdio.h>  
#include<time.h> 
#include<stdlib.h>  


/*


system inf

*/



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
void affiche_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d |",tab[i]);
       

    }
    printf("\n");
}

void affiche_tab_float(float *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %f |",tab[i]);
       

    }
    printf("\n");
}

void remplir_mat_tri_inf(int **mat,unsigned n){
    unsigned i;
    unsigned j;
    for(i=0 ; i<n;i++){
        for(j=0;j<=i;j++){
            mat[i][j] = get_random_number();
        }
    }
}


void remplir_tab(int *tab,unsigned n){
    int i;
    for(i=0;i<n;i++){
        tab[i]= get_random_number();

    }
}




void system_resoultion(int **mat,int *vect,unsigned n){

    float *res = (float*)malloc(sizeof(float)*n);
    unsigned i ;
    unsigned j ;
    for(i=0;i<n;i++){
        res[i]=vect[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            res[i]=res[i]-mat[i][j]*res[j];
        }
        res[i]=(float)res[i]/mat[i][i] ;
    }

    affiche_tab_float(res,n);

}





int main(){
    int **mat1;
    unsigned n;
    unsigned i;
    int *x ;
    printf("donner le taille de votre matrice: ");
    scanf("%u",&n);
    mat1 =(int**)malloc(sizeof(int*)*n);
    x = (int*)calloc(n,sizeof(int)) ;
    for(i=0;i<n;i++){
        mat1[i]=(int*)calloc(n,sizeof(int));
    }
    remplir_mat_tri_inf(mat1,n);
    printf("\n\n-------------------------matrice1-------------------------\n\n");
    affiche_matrice(mat1,n);
    remplir_tab(x,n);
    affiche_tab(x,n);
    system_resoultion(mat1,x,n);
    return 0;
}