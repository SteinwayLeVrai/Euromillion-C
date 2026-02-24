#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void){

  srand(time(NULL));

  int *num = malloc(5 * sizeof(int));

  
  int *num_e = malloc(2 * sizeof(int));


  
  int *res = malloc(5 * sizeof(int));


  
  int *res_e = malloc(2 * sizeof(int));


  if (num == NULL || num_e == NULL || res == NULL || res_e == NULL){
    exit(EXIT_FAILURE);
  }

  
  int cpt = 0;
  int cpt_e = 0;
  
  printf("Entrez une combinaison de 5 numero compris entre 1 et 50\n");

  // Boucle pour numero joueur 
  
  for (int i = 0; i < 5; i++){
    scanf("%d", (num + i));
    while (*(num + i) > 50 || *(num + i) < 1){
      printf("Numero %d invalide \n", i + 1);
      scanf("%d", (num + i));
    }
    for (int j = 0; j < i; j++){
      if (*(num + i) == *(num + j)){
	printf("Numero %d deja choisis \n", i + 1);
	i--;
	break;
      }
    }
  }
  
  printf("Entrez une combinaison de 2 numero etoile compris entre 1 et 12\n");

  // Boucle pour numero joueur etoile
  
  for (int i = 0; i < 2; i++){
    scanf("%d", (num_e + i));
    while (*(num_e + i) > 12 || *(num_e + i) < 1){
      printf("Numero %d invalide \n", i + 1);
      scanf("%d", (num_e + i));
    }
    for (int j = 0; j < i; j++){
      if (*(num_e + i) == *(num_e + j)){
	printf("Numero %d deja choisis \n", i + 1);
	i--;
	break;
      }
    }
  }

  printf("\n");

      // Boucle pour resultat
  for (int i = 0; i < 5; i++){
    int n,ok;

    do {
      ok = 1;
      n = rand() % 50 + 1;

      for(int j = 0; j < i; j++){
	if(*(res + j) == n){
	  ok = 0;
	  break;
	}
      }
    } while (!ok);

    *(res + i) = n;
    printf("Tirage %d : %d\n",i + 1, *(res + i));
    usleep(700000);
  }

 

  //Boucle pour resultat etoile
  for (int i = 0; i < 2; i++){
    int n,ok;

    do {
      ok = 1;
      n = rand() % 12 + 1;

      for(int j = 0; j < i; j++){
	if(*(res_e + j) == n){
	  ok = 0;
	  break;
	}
      }
    } while(!ok);

    *(res_e + i) = n;
    printf("Tirage etoile %d : %d\n",i + 1, *(res_e + i));
    usleep(700000);
  }

  printf("\n");
    


  // Boucle pour comparé

  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if (*(num + i) == *(res + j)){
	printf("Bon numéro : %d\n", *(num + i));
	cpt++;
      }
    }
  }

  // Boucle pour comparé etoile

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      if (*(num_e + i) == *(res_e + j)){
	printf("Bon numero etoile : %d\n", *(num_e + i));
	cpt_e++;
      }
    }
  }

  printf("\n");

  printf("Vous avez %d numero gagnant \n", cpt);
  printf("Vous avez %d numero etoile gagnant \n", cpt_e);

  printf("\n");

  if ((cpt == 0 && cpt_e == 0) ||( cpt == 1 && cpt_e == 0) ||( cpt == 0 && cpt_e == 1) ||( cpt == 0 && cpt_e == 2) || (cpt == 1 && cpt_e == 1)){
    printf("Gain : 0.00€\n");
  }
  else if (cpt == 2 && cpt_e == 0){
    printf("Gain : 3.90€\n");
  }
  else if (cpt == 2 && cpt_e == 1){
    printf("Gain : 5.50€\n");
  }
  else if (cpt == 1 && cpt_e == 2){
    printf("Gain : 6.70€\n");
  }
  else if (cpt == 3 && cpt_e == 0){
    printf("Gain : 9.30€\n");
  }
  else if (cpt == 3 && cpt_e == 1){
    printf("Gain : 11.20€\n");
  }
  else if (cpt == 2 && cpt_e == 2){
    printf("Gain : 14.00€\n");
  }
  else if (cpt == 4 && cpt_e == 0){
    printf("Gain : 39.40€\n");
  }
  else if (cpt == 3 && cpt_e == 2){
    printf("Gain : 57.40€\n");
  }
  else if (cpt == 4 && cpt_e == 1){
    printf("Gain : 119.60€\n");
  }
  else if (cpt == 4 && cpt_e == 2){
    printf("Gain : 1298.90€\n");
  }
  else if (cpt == 5 && cpt_e == 0){
    printf("Gain : 20 851.40€\n");
  }
  else if (cpt == 5 && cpt_e == 1){
    printf("Gain : 200 737.60€\n");
  }
  else if (cpt == 5 && cpt_e == 2){
    printf("Jackpot, Gain : 240 000 000€\n");
  }

  free(num);
  free(num_e);
  free(res);
  free(res_e);

  
  return 0;
}
