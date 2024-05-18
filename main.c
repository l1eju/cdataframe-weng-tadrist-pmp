//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include "column2.h"
#include "cdataframe.h"


int main() {

    //1. Alimentation

    COLUMN  *dur1=create_column(INT, "Julie");
    int tab_1[5]={19, 13, 11, 16, 20};
    for (int i=0; i<5; i++){
        insert_value(dur1, &(tab_1[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur2=create_column(INT, "Fahed");
    int tab_f[5]={20, 17, 11, 13, 10};
    for (int i=0; i<5; i++){
        insert_value(dur2, &(tab_f[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur=create_column(CHAR, "Lettre");
    int tab[5]={'A', 'H', 'P', 'F', 'N'};
    for (int i=0; i<5; i++){
        insert_value(dur, &(tab[i]));
    }//Initalisation en dur d'une colonne de char

    COLUMN  *dur_str=create_column(STRING, "Noms");
    char* tab_s[5]={"Pierre", "Paul", "Elodie", "Nathalie", "Kevin"};
    for (int i=0; i<5; i++){
        insert_value(dur_str, &(tab_s[i]));
    }//Initalisation en dur d'une colonne de string

    int cdf_dur_nb_col=4;
    COLUMN **cdf_dur=cdataframe_vide(cdf_dur_nb_col);
    cdf_dur[0]=dur1;
    cdf_dur[1]=dur2;
    cdf_dur[2]=dur;
    cdf_dur[3]=dur_str;
    //Remplissage en dur du CDataframe

    int cdataframe_dur, r, choix;
    do{
        printf("Souhaitez vous utiliser le CDataFrame en dur?\n");
        printf("[0]: Non\n[1]: Oui\nChoix: ");
        r = scanf("%d", &cdataframe_dur);
    } while (r==0 || cdataframe_dur>1 || cdataframe_dur<0);

    COLUMN **cdf;
    int nb_col;
    if (cdataframe_dur==1){ //Si l'utilisateur à choisi d'utiliser le CDataFrame en dur, on definit le cdf de toutes les fonctions sur celle ci
        cdf=cdf_dur;
        nb_col=cdf_dur_nb_col;
    }
    else{   // Remplissage du CDataframe à partir de saisies utilisateurs
        do {
            printf("Entrez le nombre de colonne souhaite :");
            scanf("%d", &nb_col);
        } while ((nb_col) < 0); //Saisie sécurisé taille CDataFrame
        cdf= cdataframe_vide(nb_col);

        for(int i=0; i<nb_col; i++) {   //Création d'une colonne et implémentation dans le CDataFrame
            COLUMN *col;
            char title[N][N];

            printf("Entrez le titre de la colonne: ");  //Saisie titre de la colonne
            scanf("%s", title[i]);

            int choix_type, nb_lig;
            do {                    //Saisie choix du type de la colonne
                printf("Choisissez le type de donnee de la colonne: \n"
                       "[1]: UNSIGNED INT\n"
                       "[2]: INT\n"
                       "[3]: CHAR\n"
                       "[4]: FLOAT\n"
                       "[5]: DOUBLE\n"
                       "[6]: STRING\n"
                       "[7]: STRUCTURE\n");
                scanf("%d", &choix_type);
            } while (choix_type < 1 || choix_type > 7);

            ENUM_TYPE type;     //Transformer le choix numeroté en ENUM_TYPE
            switch (choix_type) {   //Selon le numero donné lors du choix, on intialise le type de la colonne
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
            col = create_column(type, title[i]);   //On crée la colonne selon le titre et le type
            cdf[i]=col; //On implémente la colonne dans le CDataFrame

            do {
                printf("Entrez le nombre de valeur que vous souhaitez saisir:");
                scanf("%d", &nb_lig);
            } while (nb_lig < 0);       //Saisie sécurisée sur le nombre de valeur à saisir dans la colonne créé

            for (int j=0; j<nb_lig; j++) {  //Boucle où on saisie les valeurs
                void *value;
                printf("Entrez la valeur: ");
                switch (cdf[i]->column_type) {
                    case UINT: {
                        unsigned int tmp;
                        scanf("%u", &tmp);
                        value = &tmp;
                        break;
                    }
                    case INT: {
                        int tmp;
                        scanf("%d", &tmp);
                        value = &tmp;
                        break;
                    }
                    case CHAR: {
                        char tmp;
                        scanf(" %c", &tmp);
                        value = &tmp;
                        break;
                    }
                    case FLOAT: {
                        float tmp;
                        scanf("%f", &tmp);
                        value = &tmp;
                        break;
                    }
                    case DOUBLE: {
                        double tmp;
                        scanf("%lf", &tmp);
                        value = &tmp;
                        break;
                    }
                    case STRING: {
                        char tmp[N];
                        scanf("%s", tmp);
                        value = &tmp;
                        break;
                    }
                    case STRUCTURE: {
                        void *tmp;
                        scanf("%p", &tmp);
                        value = &tmp;
                        break;
                    }
                }
                insert_value(cdf[i], value);    //Insérer la valeur dans la colonne du CDataFrame
            }
        }

    }

    //Fonctionnalités
    do {
        do {    //Tant que l'utilisateur n'a pas choisit une fonction
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
                   "[12]: Afficher le nombre de ligne\n"
                   "[13]: Afficher le nombre de colonne\n"
                   "[0]: Arreter le programme\n");

            r = scanf("%d", &choix);
        } while (r==0 || choix>16 || choix<0);  //Si le numero saisi est incorrecte ou que ce n'est pas un entier on recommence

        switch (choix){ //Selon le choix de la fonction, on utilise les fonctions suivantes
            case 1:{    //Afficher tout le CDataframe
                afficher_tout_cdataframe(cdf, nb_col);
                break;
            }
            case 2:{    //Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
                int tete, queue;
                printf("Entrez l'intervalle de ligne a afficher\n Debut: ");    //L'utilisateur entre les intervalles à afficher
                scanf("%d", &tete);
                printf("Fin: ");
                scanf("%d", &queue);
                afficher_p_ligne_cdataframe(cdf, nb_col, tete, queue);  //On affiche selon l'intervalle donné
                break;
            }
            case 3: {   //Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur
                int tete, queue;
                afficher_nom_col(cdf, nb_col);
                printf("Entrez l'intervalle de colonne a afficher\n Debut: ");  //L'utilisateur entre les intervalles à afficher
                scanf("%d", &tete);
                do {                            //Saisie sécurisé
                    printf("Fin: ");
                    scanf("%d", &queue);
                } while (queue>=nb_col);
                afficher_p_colonne_cdataframe(cdf, tete, queue);    //On affiche selon l'intervalle donné
                break;
            }
            case 4:{    //Ajouter une ligne de valeurs au CDataframe
                int indice;
                void* value;
                afficher_nom_col(cdf, nb_col);
                printf("Entrez l'indice de la colonne a ajouter la valeur : "); //Saisie de la colonne pour ajouter la valeur
                scanf("%d", &indice);
                printf("Entrez la valeur a ajouter: "); //Saisie de la valeur a ajouter

                switch (cdf[indice]->column_type) { //Selon le type de data de la colonne, on fait saisir la valeur puis pointé par un void*
                    case UINT: {
                        unsigned int tmp;
                        scanf("%u", &tmp);
                        value = &tmp;
                        break;
                    }
                    case INT: {
                        int tmp;
                        scanf("%d", &tmp);
                        value = &tmp;
                        break;
                    }
                    case CHAR: {
                        char tmp;
                        scanf(" %c", &tmp);
                        value = &tmp;
                        break;
                    }
                    case FLOAT: {
                        float tmp;
                        scanf("%f", &tmp);
                        value = &tmp;
                        break;
                    }
                    case DOUBLE: {
                        double tmp;
                        scanf("%lf", &tmp);
                        value = &tmp;
                        break;
                    }
                    case STRING: {
                        char tmp[N];
                        scanf("%s", tmp);
                        value = &tmp;
                        break;
                    }
                    case STRUCTURE: {
                        void *tmp;
                        scanf("%p", &tmp);
                        value = &tmp;
                        break;
                    }
                }

                add_lig_cdataframe(&cdf, indice,value); //On ajoute la valeur
                break;
            }
            case 5:{    //Supprimer une ligne de valeurs du CDataframe
                int indice;
                afficher_nom_col(cdf, nb_col);  //On afficher les noms de colonnes et leur indice
                printf("Entrez l'indice de la colonne a ajouter supprimer une valeur : ");
                scanf("%d", &indice);
                del_lig_cdataframe(&cdf, indice);   //On supprime la ligne de la colonne choisie
                break;
            }
            case 6:{    //Ajouter une colonne au CDataframe
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

                switch (choix_type) {   //Selon le numero donné lors du choix, on intialise le type de la colonne
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
                col = create_column(type, title);   //On crée la colonne selon le titre et le type
                add_col_cdataframe(&cdf, &nb_col, col); //On l'ajoute
                break;
            }
            case 7:{    //Supprimer une colonne du CDataframe
                int indice_col;
                afficher_nom_col(cdf, nb_col);  //On affiche les colonnes et les indices
                do{
                    printf("Entrez l'indice de la colonne a supprimer: ");
                    scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);   //On fait une saisie sécurisée
                del_col_cdataframe(&cdf, &nb_col, indice_col);  //On supprime la colonne selon la saisie
                break;
            }
            case 8:{    //Renommer le titre d’une colonne du CDataframe
                int indice_col;
                char title[N];
                afficher_nom_col(cdf, nb_col);  //On affiche les colonnes et les indices
                do{
                    printf("Entrez l'indice de la colonne a modifier: ");
                    scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);   //Saisie sécurisée de la colonne à modifier
                printf("Entrez le nouveau titre de la colonne: ");
                scanf("%s", title); //Saisie du nouveau titre
                rename_title_of_col_in_cdf(&cdf, indice_col, title);    //Changement du titre de la colonne
                break;
            }
            case 9:{    //Vérifier l’existence d’une valeur (recherche) dans le CDataframe
                char val[N];
                int existence;
                printf("Entrez la valeur a rechercher: ");
                scanf("%s", val);   //Saisie de la valeur à chercher (sous forme chaine de caractère)
                existence=val_existence_cdataframe(cdf, nb_col, val);   //Verifie son existence
                if(existence==1){   //On affiche son existence
                    printf("La valeur existe dans le CdataFrame\n");
                } else{
                    printf("La valeur n'existe pas dans le CdataFrame\n");
                }
                break;
            }
            case 10:{   //Accéder et remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numéro de ligne et de colonne
                int indice_col, indice_ligne;
                do{
                    printf("Entrez l'indice de la colonne a supprimer: ");
                    scanf("%d", &indice_col);
                } while (indice_col<0 || indice_col>=nb_col);   //On fait une saisie sécurisée
                do{
                    printf("Entrez l'indice de la ligne de la colonne a supprimer: ");
                    scanf("%d", &indice_ligne);
                } while (indice_ligne<0 || indice_ligne>=cdf[indice_col]->size);   //On fait une saisie sécurisée

                void* value;
                printf("Saisir la valeur de remplacement: ");

                switch (cdf[indice_col]->column_type) { //Selon le type de data de la colonne, on fait saisir la valeur puis pointé par un void*
                    case UINT: {
                        unsigned int tmp;
                        scanf("%u", &tmp);
                        value = &tmp;
                        break;
                    }
                    case INT: {
                        int tmp;
                        scanf("%d", &tmp);
                        value = &tmp;
                        break;
                    }
                    case CHAR: {
                        char tmp;
                        scanf(" %c", &tmp);
                        value = &tmp;
                        break;
                    }
                    case FLOAT: {
                        float tmp;
                        scanf("%f", &tmp);
                        value = &tmp;
                        break;
                    }
                    case DOUBLE: {
                        double tmp;
                        scanf("%lf", &tmp);
                        value = &tmp;
                        break;
                    }
                    case STRING: {
                        char tmp[N];
                        scanf("%s", tmp);
                        value = &tmp;
                        break;
                    }
                    case STRUCTURE: {
                        void *tmp;
                        scanf("%p", &tmp);
                        value = &tmp;
                        break;
                    }
                }

                acceder_remplacer_val_cellule(&cdf,indice_ligne, indice_col, value);
                break;
            }
            case 11: {  //Afficher les noms des colonnes
                afficher_nom_col(cdf, nb_col);  //On affiche les noms et indices des colonnes
                break;
            }
            case 12:{   //Afficher le nombre de lignes
                for(int i=0; i<nb_col; i++){    //On affiche le noms et le nombres de ligne de chaque colonne
                    printf("%s : %d ligne(s)\n",cdf[i]->title, cdf[i]->size);
                }
                break;
            }
            case 13: {  //Afficher le nombre de colonnes
                printf("Le CDataFrame contient %d colonne(s)\n", nb_col);   //On affiche le nombre de colonne du CDataFrame
                break;
            }
            case 14:{   //Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
                char str[N];
                printf("Saisir une valeur pour connaitre son nombre d'occurence: ");
                scanf("%s", str);   //Saisie de la valeur à chercher
                if (val_existence_cdataframe(cdf, nb_col, str)==0){ //Si la valeur n'existe pas dans le Cdataframe
                    printf("Nombre de cellule contenant %s : 0\n", str);    //On a 0 occurrence
                }
                else{   //Sinon on cherche son nombre d'occurrence et on l'affiche
                    printf("Nombre de cellule contenant %s : %d\n", str, nb_cellule_val(cdf, nb_col, str));
                }
                break;
            }
            case 15:{   //Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
                int choix_type;
                ENUM_TYPE type;

                do {
                    printf("Choisissez le type de valeur a chercher: \n"
                           "[1]: UNSIGNED INT\n"
                           "[2]: INT\n"
                           "[3]: CHAR\n"
                           "[4]: FLOAT\n"
                           "[5]: DOUBLE\n"
                           "[6]: STRING\n"
                           "[7]: STRUCTURE\n");
                    scanf("%d", &choix_type);
                } while (choix_type < 1 || choix_type > 7);

                void* value;
                printf("Saisir la valeur de comparaison: ");
                switch (choix_type) { //Selon le type de data de la colonne, on fait saisir la valeur puis pointé par un void*
                    case 1: {
                        unsigned int tmp;
                        type=UINT;
                        scanf("%u", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 2: {
                        int tmp;
                        type=INT;
                        scanf("%d", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 3: {
                        char tmp;
                        type=CHAR;
                        scanf(" %c", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 4: {
                        float tmp;
                        type=FLOAT;
                        scanf("%f", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 5: {
                        double tmp;
                        type=DOUBLE;
                        scanf("%lf", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 6: {
                        char tmp[N];
                        type=STRING;
                        scanf("%s", tmp);
                        value = &tmp;
                        break;
                    }
                    case 7: {
                        void *tmp;
                        type=STRUCTURE;
                        scanf("%p", &tmp);
                        value = &tmp;
                        break;
                    }
                }
                printf("Il y a %d cellule(s) qui contient une valeur superieur a celle donne\n", nb_cellule_val_sup(cdf, nb_col, type, value));
                break;
            }
            case 16:{   //Nombre de cellules contenant une valeur inférieure à x(x donné en paramètre)
                int choix_type;
                ENUM_TYPE type;

                do {
                    printf("Choisissez le type de valeur a chercher: \n"
                           "[1]: UNSIGNED INT\n"
                           "[2]: INT\n"
                           "[3]: CHAR\n"
                           "[4]: FLOAT\n"
                           "[5]: DOUBLE\n"
                           "[6]: STRING\n"
                           "[7]: STRUCTURE\n");
                    scanf("%d", &choix_type);
                } while (choix_type < 1 || choix_type > 7);

                void* value;
                printf("Saisir la valeur de comparaison: ");
                switch (choix_type) { //Selon le type de data de la colonne, on fait saisir la valeur puis pointé par un void*
                    case 1: {
                        unsigned int tmp;
                        type=UINT;
                        scanf("%u", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 2: {
                        int tmp;
                        type=INT;
                        scanf("%d", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 3: {
                        char tmp;
                        type=CHAR;
                        scanf(" %c", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 4: {
                        float tmp;
                        type=FLOAT;
                        scanf("%f", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 5: {
                        double tmp;
                        type=DOUBLE;
                        scanf("%lf", &tmp);
                        value = &tmp;
                        break;
                    }
                    case 6: {
                        char tmp[N];
                        type=STRING;
                        scanf("%s", tmp);
                        value = &tmp;
                        break;
                    }
                    case 7: {
                        void *tmp;
                        type=STRUCTURE;
                        scanf("%p", &tmp);
                        value = &tmp;
                        break;
                    }
                }
                printf("Il y a %d cellule(s) qui contient une valeur inferieur a celle donne\n", nb_cellule_val_inf(cdf, nb_col, type, value));
                break;
            }
        }
        printf("Contiuer le programme?\n"
               "[0]: NON\n"
               "[1]: OUI\n");
        scanf("%d", &choix);
    }while(choix!=0);
}