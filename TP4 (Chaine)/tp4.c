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

	int taille = 0;

	char c = 'a';

	resultat = malloc(sizeof(c) * 1);
	
	while(isspace(c) == 0 && c != EOF && c != '\n'){
		c = getchar();

		if(isspace(c) == 0){

			resultat += taille;
			*resultat = c;
			resultat -= taille;
			taille++;
			resultat = realloc(resultat,sizeof(c) * taille);
		}
		
	}
	return resultat;
}



int main (){

	char * t1 = "salut";

	printf("%s\n",miroir(t1));

	printf("%s\n",saisie());

	return 0;
}