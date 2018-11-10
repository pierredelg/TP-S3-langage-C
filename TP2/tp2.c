#include <stdio.h>
#include "tp2.h"

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

	struct rat n3;
	
	n3.num = n1.num * n2.num;

	n3.den = n1.den * n2.den;

	return n3;
}

struct rat rat_somme(struct rat n1, struct rat n2){

	struct rat n3;

	n3.num = (n1.num * n2.den) + (n2.num * n1.den);
	n3.den = n1.den * n2.den;

	if(n3.num == n3.den){
		n3.num = 1;
		n3.den = 1;
	}

	return n3;
}

struct rat rat_plus_petit(struct rat list[]){

	int i = 1;

	struct rat result = list[0];

	while(list[i].den != 0){

		if(result.den == list[i].den){

			if(list[i].num < result.num){

				result.num = list[i].num;
			}
		}
		else{

			//On ramene au meme denominateur et on compare les numerateurs
			if((list[i].num * result.den) < (result.num * list[i].den)){
				
				result.num = list[i].num;
				result.den = list[i].den;
			}
		}

		i++;
	}
	return result;
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

	struct rat n1 = {1,4};
	struct rat n2 = {3,4};
	struct rat n3 = {0,0};
	struct rat n5 = {3,6};
	struct rat n6 = {2,6};
	struct rat n7 = {2,8};
	struct rat n8 = {1,600};

	n3 = rat_produit(n1,n2);

	printf("\nRésultat du produit de (%d/%d * %d/%d) = %d/%d\n",n1.num,n1.den,n2.num,n2.den,n3.num,n3.den);
	
	n3 = rat_somme(n1,n2);

	printf("\nRésultat de la somme de (%d/%d + %d/%d) = %d/%d\n",n1.num,n1.den,n2.num,n2.den,n3.num,n3.den);

	struct rat list[] = {n8,n2,n3,n5,n6,n7,n1};

	struct rat n4 = {0,0};

	n4 = rat_plus_petit(list);

	printf("Le rationnel le plus petit est %d/%d\n",n4.num,n4.den);

	return 0;
}
