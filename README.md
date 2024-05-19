# PROJET C : CDATAFRAME

Étudiant 1: Fahed Tadrist  
Étudiant 2: Weng Julie

Lien direct vers le dépôt Git de notre projet :  
https://github.com/l1eju/cdataframe-weng-tadrist-pmp.git

## Explication concise :
Le projet a pour but de faciliter le traitement de données, pour une manipulation des données plus simple et efficace.

## Fonctionnalités principales :

Notre code remplit toutes les fonctionnalités de la première partie (COLUMN d'entier se trouvant dans les fichiers column et la CDataFrame), allant de la création d'une colonne jusqu'à la création des fonctions supplémentaires
Nous avons programmé toutes les fonctionnalités sur le type COLUMN de la 2ème partie (COLUMN tout type de données dans les fichiers colmn2).
Au lancement du programme l'utilisateur à le choix entre utiliser le CDataFrame donné en dur ou de créer son propre CDataFrame pour utiliser toutes les fonctionnalités.

COLUMN (Tout type de données):  
- Creation d'une structure COLUMN intégrant un titre, une taille physique et logique, un type de données et un tableau de pointeur de données
- Insérer une valeur dans une colonne
- Convertir une valeur en chaine de caractère
- Afficher le contenu d'une colonne grâce à la fonction précédente
- Libérer l’espace allouée par une colonne
- Retourner le nombre de d’occurrences d’une valeur x (x donné en paramètre).
- Retourner la valeur présente à la position x (x donné en paramètre).
- Retourner le nombre de valeurs qui sont supérieures à x (x donné en paramètre).
- Retourner le nombre de valeurs qui sont inférieures à x (x donné en paramètre).


CDATAFRAME:

1. Alimentation
-  Création d’un CDataframe vide
-  Remplissage du CDataframe à partir de saisies utilisateurs dans le main
-  Remplissage en dur du CDataframe dans le main
-  
2. Affichage
— Afficher tout le CDataframe
— Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
— Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur

3. Opérations usuelles
— Ajouter une ligne de valeurs à une colonne du CDataFrame
— Supprimer une ligne de valeurs d'une colonne du CDataFrame
— Ajouter une colonne au CDataframe
— Supprimer une colonne du CDataframe
— Renommer le titre d’une colonne du CDataframe
— Vérifier l’existence d’une valeur (recherche) dans le CDataframe
— Accéder puis remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numéro de ligne et de colonne
— Afficher les noms des colonnes

5. Analyse et statistiques

— Afficher le nombre de lignes
— Afficher le nombre de colonnes
— Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
— Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
— Nombre de cellules contenant une valeur inférieure à x(x donné en paramètre)
