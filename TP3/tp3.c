#include <stdio.h>
#include "tp3.h"

int mon_strlen(char s[]){

	int i = 0;

	while(s[i] != '\0'){
		i++;
	}
	return i;
}

int mon_strlen2(const char *s){

	int i = 0;

	while(*s != '\0'){
		s++;
		i++;
	}
	return i;
}

int mon_strcmp(const char * s1, const char * s2){

	int resultat = 0;

	while(*s1 != '\0' && *s2 != '\0'){

		if(*s1 > *s2){
			return 1;
		}
		if(*s1 < *s2){
			return -1;
		}

		s1++;
		s2++;
	}

	return resultat;
}

int main(){

	char mot[]="bonjour";

	char *mot2 = "amour";

	printf("Exercice 1:\nLa longueur du tableau est %d\n",mon_strlen(mot));

	printf("\nExercice 2:\nLa longueur du tableau (version pointeur) est %d\n",mon_strlen2(mot2));

	char *mot3 = "bonjour";

	printf("\nExercice 3:\nLe resultat de la comparaison est %d\n",mon_strcmp(mot2,mot3));

	return 0;
}
