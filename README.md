# Traducteur National-Yemba en C

## Objectif du projet

Ce projet est un traducteur simple de mots français vers la langue yembà, une langue originaire des peuples bamilékés de l'Ouest Cameroun (le yemba est encore appelé appelée *atsang-bangwa*, *bafou*, *bamileke-yemba*, *dschang* ou *tchang* pour plus d'info [*cliquez ici*](https://fr.wikipedia.org/wiki/Yemba)). L'objectif est de créer un programme en langage C qui permet à un utilisateur de traduire des mots en utilisant une table de hachage comme structure de données principale.

## Approche méthodologique

Pour aborder ce projet, nous avons suivi les étapes suivantes :

### Étape 1 : Analyse des exigences

    Identifier les fonctionnalités essentielles :
    - **traduction**, 
    - **recherche dans un dictionnaire**, 
    - **gestion des données avec une table de hachage**.
    - Choisir une structure de données efficace pour optimiser les performances (table de hachage).

### Étape 2 : Conception modulaire

    Diviser le programme en modules :
        hash_table : Gestion de la table de hachage.
        file_handler : Chargement des données depuis le fichier texte.
        app_function: Gestion des fonctions du programme.
        main : Interaction avec l'utilisateur.
        makefile: Simplifier la compilation.

### Étape 3 : Développement

    Implémentation progressive des modules avec des tests à chaque étape.
    Documentation du code avec des commentaires et des noms de variables intuitives

### Étape 4 : Test et validation

    Test des cas suivants :
        Mot présent dans le dictionnaire.
        Mot absent du dictionnaire.
        Gestion des collisions dans la table de hachage.

## Organisation des fichiers

**main.c**: Point d'entrée du programme.<br>
**hash_table.c/h**: Gestion de la table de hachage (création, insertion, recherche, libération).<br>
**app_function.c/h**: Gestion des fonctions de l'appli pour plus de modulariter (affichage, liberation de memoire, insertion, recherche...).<br>
**file_handler.c/h**:	Gestion du fichier words.txt pour charger les mots et leurs traductions.<br>
**words.txt**:	Fichier contenant les mots et leurs traductions en Yemba, séparés avec des espaces.<br>
**makefile**:	Automatisation de la compilation et des tâches associées.<br>
**doc.txt**:	Documentation du projet, méthodologie et analyse. <br>

## Problèmes rencontrés et solutions

### Problèmes :
    
    **Gestion des collisions dans la table de hachage** :
        Problème : Lorsque plusieurs mots produisent le même indice, cela provoque des collisions.
        Solution : Utilisation de listes chaînées pour chaque bucket afin de gérer les collisions efficacement.

    **Lecture et chargement des mots** :
        Problème : Mauvais formatage du fichier words.txt entraînant des erreurs de lecture.
        Solution : Vérification stricte des entrées du fichier et ajout d'un exemple de format dans cette documentation.

    **Optimisation de la table de hachage** :
        Problème : Mauvaise répartition des mots causant un déséquilibre.
        Solution : Amélioration de la fonction de hachage pour réduire les conflits.

## Résultats obtenus

    Le programme fonctionne correctement :
        Les mots sont chargés depuis le fichier texte dans une table de hachage.
        L'utilisateur peut rechercher un mot et obtenir sa traduction s'il existe dans le dictionnaire.
        Les collisions sont gérées efficacement grâce aux listes chaînées.

    Le fichier makefile permet de compiler et d'exécuter facilement le programme.
    Commandes disponibles :
        **make** : Compiler le programme.
        **make clean** : Supprimer les fichiers objets et exécutables.

## Améliorations futures

    Ajouter une interface graphique minimale ou une version web et/ou mobile interactive et intuitive.
    Ajout d'une gigantesque base de données pour inclure tous les mots de la langue française

## Conclusion

ça n'a pas été facile mais ça été bien.

By [**Barthez Kenwou**](https://github.com/01Barthez)
