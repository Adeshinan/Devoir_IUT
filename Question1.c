#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc!=3){
    fprintf(stderr,"le format exiger est : %s <fichier_source><fichier_destination>\n",argv[0]);
    return 1;
  }
  FILE *fichier1, *fichier2;
  int retour;
  fichier1=fopen(argv[1],"r");
  if(fichier1==NULL){
    printf("Erreur d'ouverture %s\n",argv[1]);
    exit(1);
  }
  fichier2=fopen(argv[2],"w");
  if(fichier2==NULL){
    fclose(fichier1);
    printf("Erreur d'ouverture %s\n",argv[2]);
    exit(2);
  }
  else{
    int car_courant=0;
    while(1){
      car_courant=fgetc(fichier1);
      fputc(car_courant,fichier2);
      if (car_courant==EOF){
        break;
      }
    } 
  }
  printf("La copie s'est bien passée.\n");
  fclose(fichier1);
  fclose(fichier2);
}
