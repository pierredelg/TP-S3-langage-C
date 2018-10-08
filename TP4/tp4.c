#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

char * miroir (const char *s){

	char * resultat = malloc(sizeof(*s) * strlen(s));
	int compteur = 0;

	if(resultat != NULL){
	
		while(*s){
	
			*resultat = *s;
			s++;
			resultat++;
			compteur++;
		}
	
		*resultat = '\0';

		while(compteur != 0){
			s--;
			compteur --;
			resultat --;
		}
	}
	return resultat;
}

char * saisie (){

	char * resultat = NULL;
	int taille = 1;
	int compteur = 0;
	char c = ' ';
	
	do{
		resultat = malloc(sizeof(*resultat) * taille);
		c = getchar();
		*resultat = c;
		taille++;
		resultat++;
		compteur ++;
	}while(c != EOF);

	resultat -= compteur;
	return resultat;
}

int main (){

	char * t1 = "salut";

	printf("%s\n",miroir(t1));

	printf("%s\n",saisie());

	return 0;
}