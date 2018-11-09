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

	resultat = malloc(10);
	
	while(isspace(c) == 0 && c != EOF){
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

int main(int argc, char *argv[]){

	int i = 1;
	int bmirroir = 0;
	int bscan = 0;

	if(argc == 2 || argc == 3){
		
		if(argv[1][0] == '-'){
			
			while(argv[1][i]){

				if(argv[1][i] == 'm'){
					bmirroir = 1;
				}
				if(argv[1][i] == 's'){
					bscan = 1;
				}
				i++;
			}

			if(bscan == 1 && argc == 2 && bmirroir == 0){
				printf("%s\n",saisie());
				return 0;
			}
			if(bscan == 1 && argc == 2 && bmirroir == 1){
				printf("%s\n",miroir(saisie()));
				return 0;
			}
			if(bscan == 0 && argc == 3 && bmirroir == 1){
				printf("%s\n",miroir(argv[2]));
				return 0;
			}
			
		}
	}
	
	printf("mauvaise utilisation\n");
	
	return 0;
}
