#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp4.h"

char * miroir (const char *s){

	int compteur = 0;

	char * resultat = malloc(strlen(s)+1);

	if(resultat == NULL){
		return 0;
	}
	resultat += strlen(s);
	*resultat = '\0';

	while(*s){

		resultat--;
		*resultat = *s;
		s++;
		compteur++;
	}
	s -= compteur;
	
	return resultat;
}

char * saisie (){

	char * resultat = NULL;

	int taille = 0;

	int tailleBuffer = 50;

	char c = 'a';

	resultat = malloc(tailleBuffer);

	if(resultat == NULL){
		return 0;
	}

	while(isspace(c) == 0 && c != EOF ){
		c = getchar();

		if(isspace(c) == 0){

			*resultat = c;
			resultat++;
			taille++;
		}

		if(taille == tailleBuffer){
			
			resultat -= taille;
			tailleBuffer += 50;
			resultat = realloc(resultat,tailleBuffer);
			
			if(resultat == NULL){
				return 0;
			}
			resultat += taille;
		}
	}
	
	*resultat = '\0';

	if(taille < tailleBuffer){
		resultat = realloc(resultat,(taille + 1));
	}
	
	resultat -= taille; 
	
	return resultat;
}

int main(int argc, char *argv[]){

	int i = 1;
	int j = 0;
	int bmirroir = 0;
	int bscan = 0;

	if(argc == 1){
		printf("mauvaise utilisation\n");
		return 0;
	}

	for(i = 1 ; i < argc ; i++){

		j = 0;

		if(argv[i][j] == '-'){

			while(argv[i][j]){
				j++;

				if(argv[i][j] == 'm'){
					bmirroir = 1;
				}
				else{
					if(argv[i][j] == 's'){
						bscan = 1;
					}
					else{
						printf("mauvaise utilisation\n");
						return 0;
					}
				}
				j++;
			}
		}
	}
	
	if (argv[argc - 1][1] != '-') {
		if (! bscan) {
			printf("mauvaise utilisation\n");
			return 0;
		}
	}

	char * mot = NULL;

	if(bscan == 1){

		mot = saisie();
	}
	else {

		mot = argv[argc];
	}

	if(bmirroir == 1){
		printf("%s\n",miroir(mot));
	}
	else{
		printf("%s\n",mot);
	}
			
	return 0;
}
