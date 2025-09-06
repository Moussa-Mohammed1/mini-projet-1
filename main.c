#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    printf("\t---Systeme de Gestion de Stock dans une Librairie---\n\n");

    char titre[50][20];
    char auteur[50][20];
    float prix[50];
    int Qtelivre[50];
    int booksCount = 0; 

    int choix;
    int repeat;
    int exist = -1;
    int i, j;
    char recherche[20]; 

menu:
    printf("----------------------MENU----------------------\n");
    printf("1.Ajouter un livre au stock.\n");
    printf("2.Afficher tous les livres disponibles.\n");
    printf("3.Rechercher un livre par son titre.\n");
    printf("4.Mettre a jour la quantite d'un livre.\n");
    printf("5.Supprimer un livre du stock.\n");
    printf("6.Afficher le nombre total de livres en stock.\n");
    printf("7.Termine le programme ?\n");
    printf("------------------------------------------------\n");
    printf(" Votre choix :");
    scanf("%d",&choix);

    switch (choix){
    case 1:
        if (booksCount == 50){
            printf("\n\tle stock est plein !");
        }
        else{
            printf("Entrer le titre du livre :");
            scanf(" %[^\n]", titre[booksCount]);     
            printf("Entrer le nom de l'auteur du livre :");
            scanf(" %[^\n]", auteur[booksCount]);
            printf("Entrer le prix du livre :");
            scanf("%f",&prix[booksCount]);
            printf("Entrer la quantite du livre :");
            scanf("%d",&Qtelivre[booksCount]);
            booksCount ++;
        }
        goto menu;
    case 2:
        if (booksCount == 0){
            printf("Aucun livre en stock. !!\n\n");
        }
        else{
            for ( i = 0; i < booksCount; i++){
                printf("livre %d : \n Titre: %s \tAuteur: %s \tPrix: %f \tQuantite: %d\n", i+1, titre[i], auteur[i], prix[i], Qtelivre[i]);
            }
        }
        goto menu;
    case 3:
        printf("Entrer le livre a rechercher :");
        scanf(" %[^\n]", recherche);
        for ( i = 0; i < booksCount; i++){
            if (strcmp(titre[i],recherche)==0){
                exist = i;
            }
        }
        if (exist != -1){
            printf("Livre existe : \tTitre : %s  \tAuteur : %s \tPrix : %f DH \tQuantite : %d\n", titre[exist], auteur[exist], prix[exist], Qtelivre[exist]);
        }
        else{
            printf("Ce livre n'existe pas !!\n\n");
        }
        goto menu;
    case 4:
        printf("Entrer le titre du livre :");
        scanf(" %[^\n]", recherche);
        int NewQte;
        int found = -1;
        for ( i = 0; i < booksCount; i++){
            if (strcmp(titre[i],recherche)==0){
                printf("Ce livre est existe :\n");
                printf("Entrer le nouveau quantite a ajouter :");
                scanf("%d",&NewQte);
                found = i;
                Qtelivre[i] = NewQte;
                printf("Quantite a ete modifier !!\n\n");
                break;
            }
        }
        if (found == -1){
            printf("ce livre n'exist pas.\n\n");
        }
        goto menu;
    case 5:
        printf("Entrer le titre du livre a supprime : ");
        scanf(" %[^\n]", recherche);
        for ( i = 0; i < booksCount; i++){
            if (strcmp(titre[i],recherche)==0){
                for ( j = i ; j < booksCount -1; j++){    
                    Qtelivre[j]= Qtelivre[j+1];
                    strcpy(titre[j],titre[j+1]);
                    strcpy(auteur[j],auteur[j+1]);
                    prix[j]= prix[j+1];
                }
                booksCount --;
                exist = 1;
                printf("Le livre a supprime avec success !\n\n");
                break;
            }
        }
        if (exist != 1){
            printf("ce livre n'exist pas.\n\n");
        }
        goto menu;
    case 6:
        int QuantiteTotale = 0;
        for ( i = 0; i < booksCount; i++){
            QuantiteTotale += Qtelivre[i];
        }
        printf("Le nombre totale des livres dans la librairie est : %d\n\n",QuantiteTotale);
        goto menu;
        case 7:
        goto out;
    default:
        printf("Entrer un choix valide:\n\n");
        goto menu;
    }
out:
    return 0;
}