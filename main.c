#include <stdio.h>
#include <stdbool.h>
 typedef struct {
    char titre[30],description [100],date_echeance[20], priorite[20];
}tache;
void AjouterTache(tache t[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("\nEntrez la Tache N° %d\n", i + 1);

        printf("Entrez le titre :\n");
        scanf("%s",t[i].titre);

        printf("Entrez la description :\n");
        scanf("%s", t[i].description);

        printf("Entrez la date d'echeance :\n");
        scanf("%s", t[i].date_echeance);

        printf("Entrez la priorite :\n");
        scanf("%s", t[i].priorite);
    }
}
void afficherTache(tache t[], int taille){
    if(taille==0){
        printf("Aucune valeur a afficher");
        return;
    }
        for(int i=0;i<taille;i++){
            printf("Les informations de tache N°:%d\n",i+1);
            printf("Titre:%s\n",t[i].titre);
            printf("Description:%s\n",t[i].description);
            printf("Date d'echeance:%s\n",t[i].date_echeance);
            printf("Priorite:%s\n", t[i].priorite);
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
        printf("5. Filtrer les taches:\n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);


    switch (choix) {
  case 1:
    AjouterTache(t,taille);
    break;
  case 2:
    afficherTache(t,taille);
    break;
  default:
    // code block
}
}}
