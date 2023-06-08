![Bomberman Titre](https://upload.wikimedia.org/wikipedia/fr/thumb/a/a5/Bomberman_Logo.svg/1280px-Bomberman_Logo.svg.png)
# Bomberman C++
Jeu bomberman en C++ réalisé dans le cadre du cours de C++ de ROB4 de Polytech Sorbonne.

## Comment jouer
Le jeu se joue à deux joueurs, chacun contrôlant un bomberman. Le but est de tuer l'autre joueur en posant des bombes. Le joueur qui meurt en premier perd la partie.
Le jeu se joue en local, sur le même ordinateur.

Le jeu contient 4 types de powerups qui apparaissent en détruisant les blocs:
- Powerup de vitesse: augmente la vitesse de déplacement
- Powerup de ralentissement: ralentit la vitesse de déplacement 
- Powerup de portée: augmente la portée des bombes
- Powerup de bombe: augmente le nombre de bombes que le bomberman peut poser simultanément

Les contrôles sont les suivants:
- Joueur 1:
    - `Z` `Q` `S` `D` pour se déplacer
    - `Espace` pour poser une bombe
- Joueur 2:
    - `←` `↑` `→` `↓` pour se déplacer
    - `LeftControl` pour poser une bombe


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

Pour lancer le jeu, une fois le projet compilé, exécuter la commande suivante:
```bash
./build/src/bomberman
```

## Doxygen
Pour ouvrir la documentation doxygen depuis l'index de départ, ouvrir index.html dans le dossier `docs`
