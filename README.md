# PROJET C : CDATAFRAME

Étudiant 1: Fahed Tadrist  
Étudiant 2: Weng Julie

[Cliquez ici](https://github.com/l1eju/cdataframe-weng-tadrist-pmp.git) pour accéder directement au dépôt Git de notre projet.

## Explication concise :
Le projet a pour but de nous faire travailler afin de faciliter le traitement des données d'un utilisateur, pour qu'il puisse les manipuler et y accéder de manière plus simple et optimale.

## Fonctionnalités principales :

Nous avons fait les 2 types de colonnes pour la 1<sup>ère</sup> partie :
1. COLUMN d'entier se trouvant dans les fichiers `column.c` et `column.h`,
2. COLUMN tout type de données dans les fichiers `colmn2.c` et `column.2.h`.

Cela va de la création d'une colonne jusqu'à la création des fonctions supplémentaires.

Pour la 2<sup>ème</sup> partie sur la création du CDataframe, nous avons choisi la partie "Tableau dynamique", pour ce faire, nous avons programmé les fichiers `cdataframe.c` et `cdataframe.h`.

Et finalement, pour la partie fonctionnalité, nous avons choisi de faire les fonctions dites "basiques".

> [!IMPORTANT]
> Au lancement du programme dans le `main.c`, l'utilisateur a le choix entre utiliser le CDataFrame donné en dur ou de créer son propre CDataFrame pour utiliser toutes les fonctionnalités.

Voici ci-dessous l'ensemble des fonctions/fonctionnalités faites :

COLUMN (Tout type de données) :  
-[x] Creation d'une structure COLUMN intégrant un titre, une taille physique et logique, un type de données et un tableau de pointeur de données
-[x] Insérer une valeur dans une colonne
-[x] Convertir une valeur en chaine de caractère
-[x] Afficher le contenu d'une colonne grâce à la fonction précédente
-[x] Libérer l’espace allouée par une colonne
-[x] Retourner le nombre de d’occurrences d’une valeur x (x donné en paramètre).
-[x] Retourner la valeur présente à la position x (x donné en paramètre).
-[x] Retourner le nombre de valeurs qui sont supérieures à x (x donné en paramètre).
-[x] Retourner le nombre de valeurs qui sont inférieures à x (x donné en paramètre).


CDATAFRAME:

1. Alimentation
-[x]  Création d’un CDataframe vide
-[x]  Remplissage du CDataframe à partir de saisies utilisateurs dans le main
-[x]  Remplissage en dur du CDataframe dans le main
  
2. Affichage
-[x] Afficher tout le CDataframe
-[x] Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
-[x] Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur

3. Opérations usuelles
-[x] Ajouter une ligne de valeurs à une colonne du CDataFrame
-[x] Supprimer une ligne de valeurs d'une colonne du CDataFrame
-[x] Ajouter une colonne au CDataframe
-[x] Supprimer une colonne du CDataframe
-[x] Renommer le titre d’une colonne du CDataframe
-[x] Vérifier l’existence d’une valeur (recherche) dans le CDataframe
-[x] Accéder puis remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numéro de ligne et de colonne
-[x] Afficher les noms des colonnes

4. Analyse et statistiques
-[x] Afficher le nombre de lignes
-[x] Afficher le nombre de colonnes
-[x] Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
-[x] Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
-[x] Nombre de cellules contenant une valeur inférieure à x(x donné en paramètre)
