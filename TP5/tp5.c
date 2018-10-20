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

int main(int argc, char *argv[]){

	int f = 0;
	char * fichier = argv[argc - 1];
	int nbChar = 0;
	int nbMot = 0;
	int nbLigne = 0;
	int* ptChar = &nbChar;
	int* ptMot = &nbMot;
	int* ptLigne = &nbLigne;

	f = open(fichier,O_RDONLY);

	if(f == -1){
		perror(fichier);
		exit(1);
	}else{

		traiter(f,ptChar,ptMot,ptLigne);
		printf("caracteres : %d ",nbChar);
		printf("mots : %d ",nbMot);
		printf("lignes : %d ",nbLigne);
		printf(" -> %s",fichier);
		printf("\n");
		close(f);
	}
}