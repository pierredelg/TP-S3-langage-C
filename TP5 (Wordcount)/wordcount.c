#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


int traiter (int f, int *car, int *mot, int *lig){

	int lecture;
	int i;
	char buffer [80];

	do{
		i = 0;
		lecture = read(f,buffer, 80);

		if (lecture == -1){
			return -1;
		}
		else{
			*car += lecture;
			while(i < lecture){

				if(isspace(buffer[i])){
					*mot = *mot + 1;
					if(buffer[i] == '\n'){
						*lig = *lig + 1;
					}
				}
				i++;
			}
		}
	}while(lecture != 0);

	//On retire au nombre de charactere les \n
	*car -= *lig;

	//On rajoute 1 a ligne et a mot car le dernier char n'est pas \n mais EOF
	*mot += 1;
	*lig += 1;

	return 0;
}

void erreur(char * fichier){
	perror(fichier);
	exit(1);
}

int main(int argc, char *argv[]){

	char * fichier = NULL;
	int f = 0;
	int nbChar = 0;
	int nbCharTotal = 0;
	int nbMot = 0;
	int nbMotTotal = 0;
	int nbLigne = 0;
	int nbLigneTotal = 0;
	int boolC = 0;
	int boolW = 0;
	int boolL = 0;
	int i = 0;
	int j = 0;
	int nbFichier = 0;
	
	for(i = 1 ; i < argc ; i++){

		j = 0;

		if(argv[i][j] == '-'){

			while(argv[i][j]){

				if(argv[i][j] == 'c'){
					boolC = 1;
				}
				if(argv[i][j] == 'w'){
					boolW = 1;
				}
				if(argv[i][j] == 'l'){
					boolL = 1;
				}
				j++;
			}
		}
		else{
			
			fichier = argv[i];

			f = open(fichier,O_RDONLY);

			if(f == -1){

				erreur(fichier);
			}
			
			nbFichier++;

			traiter(f,&nbChar,&nbMot,&nbLigne);
			
			if (boolC == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
				printf("caracteres : %d ",nbChar);
				nbCharTotal += nbChar;
				nbChar = 0;
			}
			if (boolW == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
				printf("mots : %d ",nbMot);
				nbMotTotal += nbMot;
				nbMot = 0;
			}
			if (boolL == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
				printf("lignes : %d ",nbLigne);
				nbLigneTotal += nbLigne;
				nbLigne = 0;
			}

			printf(" -> %s",fichier);
			printf("\n");
			close(f);

		}
	}

	if(nbFichier > 1){
		
		printf("\n");

		if (boolC == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
			printf("caracteres : %d ",nbCharTotal);
		}
		
		if (boolW == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
			printf("mots : %d ",nbMotTotal);
		}
		
		if (boolL == 1 || (boolC == 0 && boolL == 0 && boolW == 0)){
			printf("lignes : %d ",nbLigneTotal);
		}

		printf(" -> total");
		printf("\n");
	}	
}