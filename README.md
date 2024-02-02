# Module Image

Ce module à été créé à but éducatif en vue de s'exercer et 
apprendre à implementer un programme avec la librairie graphique qu'est SDL2

## Fonctionnalités

Ce module nous permet :
 
- L'affichage d'une image avec SDL2
- Un zoomer pour mieux voir l'image
- De changer la couleur d'un pixel ou d'une zone carré dans l'image
- Sauvegarder l'image dans un fichier .ppm
- Charger une image à partir d'un fichier.ppm

## Arborescence

Le repo se divise en plusieurs dossiers correspondant aux différentes parties du projet :

- ``bin`` contient les fichiers binaires, ce sont avec eux que le module peut être executé :
    - ``affichage'``, qui affiche avec SDL2 l'image préchargée
    - ``exemple``, qui crée une image, la modifie, la sauvegarde et la charge dans une deuxième image qui est elle aussi sauvegardé
    - ``test``, qui vérifie que les fonctions de la classe Image fonctionne bel et bien.
- ``build`` /todo
- ``data`` contient les fichiers de sauvegarde en .ppm créés à partir de ce merveilleux module.
- ``doc`` contient le DOXYFIlE /todo
- ``src`` contient les fichiers sources essentiels au bon fonctionnement du module

## Compilation

Le projet a été créé avec CMake pour faciliter la compilation.

### Sous Linux :

```bash
cmake -B cmake-build-release
cd cmake-build-release
make
```

Et ``./affichage``, ``./exemple``  ou ``./test`` pour lancer un des programmes

## Auteurs

Ce projet a été mené par 3 étudiants en 2e année d'études à Polytech Lyon

- Guillaume CALDERON (p2205143)
- Thibaut LARACINE (p2202485)
- Emmanuel LUQUIN (pXXXXXX)