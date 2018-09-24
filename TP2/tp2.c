#include <stdio.h>

void afficher(int liste[], int taille){

	int i;

	for(i = 0; i < taille ; i++){

		printf("%d : %d\n",i,liste[i]);	

	}
}

int somme(int liste[],int taille){

	int j;
	
	int somme = 0;

	for(j = 0; j < taille ; j++){
		
		somme += liste[j];	
	}
	return somme;
}

void copie_dans(int dest[], int src[], int taille){
	int i = 0;

	for(i = 0;i < taille;i++){
		dest[i] = src[i];
	}
	printf("copie ok\n");
}

void ajoute_apres(int dest[], int taille_dest, int src[], int taille_src){

	int i = 0;

	for(i = taille_dest;i < (taille_dest + taille_src); i++){
		
		dest[i] = src[i - taille_dest];
	} 	
}

struct rat rat_produit(struct rat n1, struct rat n2){

	typedef struct rat rat_produit;
	
	rat_produit.den = n1.den * n2.den;

	rat_produit.num = n1.num * n2.num;

	return rat_produit;
}

int main(){

	printf("\nExercice 1:");
	
	printf("\n1)\n");
	
	int som;

	int liste[5]= {1,2,3,4,5};
	
	afficher(liste,5);

	printf("\n2)\n");
	
	som = somme(liste,5);

	printf("la somme est = %d\n", som);

	int copieListe[5];

	printf("\n3)\n");

	copie_dans(copieListe ,liste,5);
	
	afficher(copieListe,5);

	printf("\n4)\n");

	int listeG[50]= {0,1,2,3,4,5};

	ajoute_apres(listeG,6,liste,5);

	afficher(listeG,50);

	printf("\nExercice 2:\n");

	struct rat
	{
		int den;
		int num;
	};

	typedef struct rat n1;

	typedef struct rat n2;

	rat_produit(n1,n2);

	

	return 0;
}
