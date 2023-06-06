![Bomberman Titre](https://upload.wikimedia.org/wikipedia/fr/thumb/a/a5/Bomberman_Logo.svg/1280px-Bomberman_Logo.svg.png)
# Bomberman C++
Jeu bomberman en C++ réalisé dans le cadre du cours de C++ de ROB4 de Polytech Sorbonne.

## Dépendances
Linux only:
- CMake
- SFML

## Compilation du projet
Pour compiler le projet, exécuter les commandes suivantes à la racine du projet:
```bash
mkdir build  # Création du dossier build
cd build
cmake .. # Configuration du projet
cmake --build . # Compilation du projet
```
Pour lancer les tests, une fois le projet compilé, exécuter la commande suivante dans le dossier build:
```bash
ctest
```

Pour lancer le jeu, une fois le projet compilé, exécuter la commande suivante dans le dossier build:
```bash
./bomberman
```
