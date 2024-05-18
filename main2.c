//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "column2.h"
#include "cdataframe.h"


int main() {

    COLUMN  *dur1=create_column(INT, "Julie");
    int tab_1[5]={19, 13, 11, 16, 20};
    for (int i=0; i<5; i++){
        insert_value(dur1, &(tab_1[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur2=create_column(INT, "Fahed");
    int tab_f[5]={20, 17, 12, 13, 10};
    for (int i=0; i<5; i++){
        insert_value(dur2, &(tab_f[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur=create_column(CHAR, "Lettre");
    int tab[5]={'A', 'H', 'P', 'F', 'N'};
    for (int i=0; i<5; i++){
        insert_value(dur, &(tab[i]));
    }//Initalisation en dur d'une colonne de char

    int cdf_dur_nb_col=3;
    COLUMN **cdf_dur=cdataframe_vide(cdf_dur_nb_col);
    cdf_dur[0]=dur1;
    cdf_dur[1]=dur2;
    cdf_dur[2]=dur;

    //afficher_tout_cdataframe(cdf_dur, cdf_dur_nb_col);
    //afficher_p_ligne_cdataframe(cdf_dur, cdf_dur_nb_col, 2, 4);
    //afficher_p_colonne_cdataframe(cdf_dur, 0, 1);

    int cdataframe_dur, r, choix;
    do{
        printf("Souhaitez vous utiliser le CDataFrame en dur?\n");
        printf("[0]: Non\n[1]: Oui\nChoix: ");
        r = scanf("%d", &cdataframe_dur);
    } while (r==0 || cdataframe_dur>1 || cdataframe_dur<0);

    COLUMN **cdf;
    int nb_col;
    if (cdataframe_dur==1){
        cdf=cdf_dur;
        nb_col=cdf_dur_nb_col;
    }
    else{
        cdf= cdataframe_vide(0);
        nb_col=0;
    }
    do {
        do {
            printf("A quelle fonctionnalite souhaitez vous acceder?\n"
                   "[1]: Afficher tout le Cdataframe\n"
                   "[2]: Afficher une partie des lignes du Cdataframe\n"
                   "[3]: Afficher une partie des colonne du Cdataframe\n"
                   "[4]: Ajouter une ligne de valeur au CdataFrame\n"
                   "[5]: Supprimer une ligne de valeur du CdataFrame\n"
                   "[6]: Ajouter une colonne au CdataFrame\n"
                   "[7]: Supprimer une colonne du CdataFrame\n"
                   "[8]: Renommer le titre d’une colonne du CDataframe\n"
                   "[9]: Verifier l’existence d’une valeur dans le CDataframe\n"
                   "[10]: Remplacer la valeur se trouvant dans une cellule du CDataframe\n"
                   "[11]: Afficher les noms des colonnes\n"
                   "[0]: Arreter le programme\n");

            r = scanf("%d", &choix);
        } while (r==0 || choix>11 || choix<0);

        switch (choix){
            case 1:{
                afficher_tout_cdataframe(cdf, nb_col);
                break;
            }
            case 2:{
                int tete, queue;
                printf("Entrez l'intervalle de ligne a afficher\n Debut: ");
                scanf("%d", &tete);
                printf("Fin: ");
                scanf("%d", &queue);
                afficher_p_ligne_cdataframe(cdf, nb_col, tete, queue);
                break;
            }
            case 3: {
                int tete, queue;
                afficher_nom_col(cdf, nb_col);
                printf("Entrez l'intervalle de colonne a afficher\n Debut: ");
                scanf("%d", &tete);
                do {
                    printf("Fin: ");
                    scanf("%d", &queue);
                } while (queue>=nb_col);
                afficher_p_colonne_cdataframe(cdf, tete, queue);
                break;
            }
            case 4:{
                int indice;
                void* value;
                afficher_nom_col(cdf, nb_col);
                printf("Entrez l'indice de la colonne a ajouter la valeur : ");
                scanf("%d", &indice);
                printf("Entrez la valeur a ajouter: ");

                value=adpater_valeur(cdf, indice);

                add_lig_cdataframe(&cdf, indice,value);
                break;
            }
            case 5:{
                int indice;
                afficher_nom_col(cdf, nb_col);
                printf("Entrez l'indice de la colonne a ajouter supprimer une valeur : ");
                scanf("%d", &indice);
                del_lig_cdataframe(&cdf, indice);
                break;
            }
            case 6:{
                COLUMN *col;
                int choix_type;
                enum enum_type type;
                char title[N];
                printf("Entrez le titre de la colonne: ");
                scanf("%s", title);

                do {
                    printf("Choisissez le type de donnee de la colonne: \n"
                           "[1]: UNSIGNED INT\n"
                           "[2]: INT\n"
                           "[3]: CHAR\n"
                           "[4]: FLOAT\n"
                           "[5]: DOUBLE\n"
                           "[6]: STRING\n"
                           "[7]: STRUCTURE\n");
                    scanf("%d", &choix_type);
                } while (choix_type<1 || choix_type>7);

                switch (choix_type) {
                    case 1: {
                        type = UINT;
                        break;
                    }
                    case 2: {
                        type = INT;
                        break;
                    }
                    case 3: {
                        type = CHAR;
                        break;
                    }
                    case 4: {
                        type = FLOAT;
                        break;
                    }
                    case 5: {
                        type = DOUBLE;
                        break;
                    }
                    case 6: {
                        type = STRING;
                        break;
                    }
                    case 7: {
                        type = STRUCTURE;
                        break;
                    }
                }
                col = create_column(type, title);
                print_col(col);
                add_col_cdataframe(&cdf, &nb_col, col);
                break;
            }
            case 7:{
                int indice_col;
                afficher_nom_col(cdf, nb_col);
                do{
                printf("Entrez l'indice de la colonne à supprimer: ");
                scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);
                del_col_cdataframe(&cdf, &nb_col, indice_col);
                break;
            }
            case 8:{
                int indice_col;
                char title[N];
                afficher_nom_col(cdf, nb_col);
                do{
                    printf("Entrez l'indice de la colonne à modifier: ");
                    scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);
                printf("Entrez le nouveau titre de la colonne: ");
                scanf("%s", title);
                rename_title_of_col_in_cdf(&cdf, indice_col, title);
                break;
            }
            case 9:{
                int indice_col;
                afficher_tout_cdataframe(cdf, nb_col);
                do{
                    printf("Entrez l'indice de la colonne à modifier: ");
                    scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);

            }
        }
    }while(choix!=0);


    /*COLUMN  *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    //delete_column(&(*mycol));
    print_col(mycol);

    printf("Present %d fois", nb_occurences(mycol, &a));

    //COLUMN** cdf;
    //cdf=cdataframe_vide();
    COLUMN ** cdf = (COLUMN **) malloc(sizeof(COLUMN));


    int len=5;

    remplissage_cdataframe(&cdf, &len);
    afficher_tout_cdataframe(cdf, len);*/
}