#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp4.h"

char * miroir (const char *s){

	int compteur = 0;

	char * resultat = malloc(sizeof(*s) * strlen(s));

	if(resultat != NULL){

		resultat += strlen(s) - 1;
		*resultat = '\0';

		while(*s){

			resultat--;
			*resultat = *s;
			s++;
			compteur++;
		}
		s -= compteur;
	}
	return resultat;
}

char * saisie (){

	char * resultat = NULL;
	int taille = 1;
	char c = '*';
	//int compteur = 0;
	resultat = malloc(sizeof(*resultat) * taille);
	
	while(isspace(c) == 0 || c == '\n'){
		resultat = realloc(resultat,sizeof(*resultat) * taille);
		c = getchar();
		*resultat = c;
		taille++;
	}
	return resultat;
}

int main (){

	char * t1 = "salut";

	printf("%s\n",miroir(t1));

	printf("%s\n",saisie());

	return 0;
}