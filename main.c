#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 typedef struct {
    char titre[30],description [100],date_echeance[20];
    char priorite[20];
}tache;
tache t[100];
int taille=0;
void AjouterTache() {
    int choix;
printf("\nEntrez la Tache N� %d\n", taille + 1);
    printf("Entrez le titre :\n");
    scanf(" %[^\n]s", t[taille].titre);
    printf("Entrez la description :\n");
    scanf(" %[^\n]s", t[taille].description);
    printf("Entrez la date d'�ch�ance (format : JJ-MM-AAAA) :\n");
    scanf("%s", t[taille].date_echeance);
    do {
        printf("Donnez la priorite (1. High / 2. Low):\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                strcpy(t[taille].priorite, "high");
                break;
            case 2:
                strcpy(t[taille].priorite, "low");
                break;
            default:
                printf("Choix invalide ! R�essayez.\n");
        }
    } while (choix != 1 && choix != 2);

    taille++;
    printf("Tache ajout�e avec succ�s !\n");
}
void afficherTache(){
    if(taille==0){
        printf("Aucune valeur a afficher");
        return;
    }
        for(int i=0;i<taille;i++){
            printf("Les informations de tache N�:%d\n",i+1);
            printf("Titre:%s\n",t[i].titre);
            printf("Description:%s\n",t[i].description);
            printf("Date d'echeance:%s\n",t[i].date_echeance);
            printf("Priorite:%s\n",t[i].priorite);
        }

}

void modifierTache() {
    int M, choix;
printf("\nEntrez la Tache a modifier:");
scanf("%d",&M);
 if (M >0 && M <= taille) {
      M--;
    printf("Entrez le nouveau titre :\n");
    scanf(" %[^\n]s", t[M].titre);
    printf("Entrez la nouvelle description :\n");
    scanf(" %[^\n]s", t[M].description);
    printf("Entrez la nouvelle date d'�ch�ance (format : JJ-MM-AAAA) :\n");
    scanf("%s", t[M].date_echeance);

    do {
        printf("Donnez la priorite (1. High / 2. Low):\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                strcpy(t[M].priorite, "high");
                break;
            case 2:
                strcpy(t[M].priorite, "low");
                break;
            default:
                printf("Choix invalide ! R�essayez.\n");
        }
    } while (choix != 1 && choix != 2);

    printf("Tache modifier avec succ�s !\n");
}else{
    printf("invalide index!");
}
}

void supprimerTache() {
    int z;
    printf("Entrez le num�ro de la tache a supprimer (1 � %d): ", taille);
    scanf("%d", &z);
    if (z < 1 || z > taille) {
        printf("Tache invalide.\n");
        return;
    }
        for (int i = z; i < taille - 1; i++) {
            z--;
        t[i] = t[i + 1];
    }
    taille--;
    printf("Tache supprimer avec succes.\n");
}

void FiltrerTache() {
    int choix;
    int trouve = 0;
    char prioriteRecherchee[10];

    printf("\nEntrez la priorite que vous voulez afficher (1. High / 2. Low) : ");
    scanf("%d", &choix);
    if (choix == 1) {
        strcpy(prioriteRecherchee, "high");
    } else if (choix == 2) {
        strcpy(prioriteRecherchee, "low");
    } else {
        printf("Choix invalide ! R�essayez.\n");
        return;
    }
    printf("\n=== T�ches avec priorit� '%s' ===\n", prioriteRecherchee);
    for (int i = 0; i < taille; i++) {
        if (strcmp(t[i].priorite, prioriteRecherchee) == 0) {
            printf("\nT�che N�%d:\n", i + 1);
            printf("Titre: %s\n", t[i].titre);
            printf("Description: %s\n", t[i].description);
            printf("Date d'�ch�ance: %s\n", t[i].date_echeance);
            printf("Priorit�: %s\n", t[i].priorite);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune t�che avec la priorit� '%s'.\n", prioriteRecherchee);
    }
}

int main()
{
    //MENU//

    int choix;
    int taille=0;
    bool continuer= true;
    tache t[100];
    while(continuer){
        printf("\n=== Menu ===\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher une tache:\n");
        printf("3. Modifier une tache:\n");
        printf("4. Supprimer une tache:\n");
        printf("5. Filtrer les taches par priorite:\n");
        printf("6. Quitter:\n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);


    switch (choix) {
  case 1:
    AjouterTache();
    break;
  case 2:
    afficherTache();
    break;
  case 3:
    modifierTache();
    break;
  case 4:
    supprimerTache();
    break;
    case 5:
    FiltrerTache();
    break;
  case 6:
    printf("Merci d'avoir utilise l'application. Au revoir !\n");
    continuer = false;  // Termine la boucle et quitte l'application
    break;
    default:
    printf("Choix invalide. Veuillez reessayer.\n");
}
}}
