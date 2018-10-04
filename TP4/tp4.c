#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

char * miroir (const char *s){

	char * resultat = malloc(sizeof(s) * strlen(s));
	
	while(*s){
	
		*resultat = *s;
		s++;
		resultat++;
	}
	
	*resultat = '\0';

	return resultat;
}

int main (){

	char * t1 = "salut";

	printf("%s\n",miroir(t1));

	return 0;
}