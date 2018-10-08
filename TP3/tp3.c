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

	while(*s != '\0'){  // for(i=0; *s; s++, i++) {}
		s++;
		i++;
	}
	return i;
}

int mon_strcmp(const char * s1, const char * s2){
	
	int resultat = 0;

	while(*s1 != '\0' && *s2 != '\0'){

		if(*s1 > *s2){//si s1 == s2 s1++ s2++
			//sinon  return *s1 -*s2}
			return 1;
		
		}
		if(*s1 < *s2){
			return -1;
		}

		s1++;
		s2++;
	}
	//return *s1-*s2;
	if(*s1 == '\0'){
		return -1;
	}
	if(*s2 == '\0'){
		return 1;
	}
	return resultat;
}

int mon_strncmp(const char * s1, const char * s2, int n){

	int resultat = 0;
	int i = 0;

	for(i = 0 ; i < n && *s1 != '\0' && *s2 != '\0';i++){

		if(*s1 > *s2 ){
			return 1;
		}
		if(*s1 < *s2){
			return -1;
		}

		s1++;
		s2++;
	}
	if(*s1 == '\0'){
		return -1;
	}
	if(*s2 == '\0'){
		return 1;
	}
	return resultat;
}
char *mon_strcat(char *s1,const char *s2){
	
	while(*s1 != '\0'){   // for(;*s1;s1++) {}
		s1 ++;
	}

	while(*s2 != '\0'){
		*s1 = *s2;
		s1++;
		s2++;
	}

	*s1 = '\0';

	return s1;
}

char *mon_strchr(char *s, int c){

	char *s1 = NULL;

	while(*s != '\0'){
		if(*s == c){
			s1 = s;
			return s1;
		}
		s++;
	}
	return s1;
}

char *mon_strstr(char *haystack, char *needle){

	char *s = NULL;
	int compteur = 0;

	//On parcours la chaine reference
	while(*haystack){

		//si la lettre correspond au debut de la deuxieme chaine
		if(*haystack == *needle){
			
			compteur = 1;
			
			//tant que les lettres sont egales et que la deuxieme chaine n'est pas a la fin
			while(*haystack == *needle && *needle != '\0'){
				compteur++;
				haystack++;
				needle++;
			}
			//si la 2eme chaine est arrivée a la fin
			if(*needle == '\0'){
				//On remonte le pointeur a la premiere lettre trouvée
				while(compteur != 0){  // haystack -= compteur;
					compteur --;
					haystack --;
				}
				
				s = haystack;
				return s;
			}
		}else{
			haystack++;
		}
	}
	return s;
}

char *mon_strstr2(char *haystack, char *needle){

	int compteur = 0;
	
	while(*haystack){

		if(mon_strcmp(haystack, needle) == 0){
			return haystack;	
		}
		else{
			compteur++;
			haystack++;
		}
	}
	haystack -= compteur;
	return NULL;
}



int main(){

	char mot[]="bonjour";

	char *mot2 = "Amour";

	printf("Exercice 1:\nLa longueur du tableau est %d\n",mon_strlen(mot));

	printf("\nExercice 2:\nLa longueur du tableau (version pointeur) est %d\n",mon_strlen2(mot2));

	printf("\nExercice 3:\nLe resultat de la comparaison est %d\n",mon_strcmp(mot,mot2));

	printf("\nExercice 3:\nLe resultat de la comparaison avec bon est %d\n",mon_strcmp("aaaaaaaaaaaaaa",mot));

	printf("\nExercice 4:\nLe resultat de la comparaison jusqu'au caractere %d est %d\n",3,mon_strncmp(mot,mot2,3));

	char mot3 [20] = {"bonjour"};

	char *mot4 = "toi";

	printf("\nExercice 5:\nLe resultat de la concatenation de %s et de %s ",mot3,mot4);

	mon_strcat(mot3,mot4);

	printf("est %s\n",mot3);
	
	printf("\nExercice 6:\n%s\n",mon_strchr(mot4,'o'));

	printf("\nExercice 7:\n%s\n",mon_strstr("ludovic","ov"));

	printf("\nExercice 8:\n%s\n",mon_strstr2("boudqNCDSKloorccSOCDoonbovhuofun","on"));

	return 0;
}
