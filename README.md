# Module Image

Ce module à été créé dans le cadre de l'UE LIFAPCD à Polytech Lyon en vue de s'exercer et d'apprendre à implémenter un
programme avec la bibliothèque graphique SDL2

## Fonctionnalités

Ce module permet de :

- Créer une image
- Récupérer et modifier des pixels d'une image
- Sauvegarder une image dans un fichier au format ppm
- Charger une image depuis un fichier ppm
- Afficher une image dans une fenêtre SDL2
- Un zoom pour mieux voir l'image

## Arborescence

Le repo se divise en plusieurs dossiers correspondant aux différentes parties du projet :

- ``bin`` contient les fichiers binaires permettant de tester les différentes fonctionnalités du module :
    - ``affichage`` pour tester l'affichage d'une image dans une fenêtre SDL2
    - ``exemple`` pour tester la création, la modification, la sauvegarde et le chargement des images
    - ``test`` pour lancer les tests de régression
- ``build`` pour la compilation avec CMake
- ``data`` contient les images 
- ``doc`` contient la documentation du module
- ``src`` contient les fichiers sources du module

## Compilation

Le projet a été créé avec CMake pour faciliter la compilation.

### Sous Linux :

```bash
cd build
cmake ..
make
```

Les exécutables ``affichage``, ``exemple``  et ``./test`` seront créés dans le dossier ``bin`` du projet.

## Auteurs

Ce projet a été mené par 3 étudiants en 2e année d'études à Polytech Lyon

- Guillaume CALDERON (p2205143)
- Thibaut LARACINE (p2202485)
- Emmanuel LUQUIN (pXXXXXX)