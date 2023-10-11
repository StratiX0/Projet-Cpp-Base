// Jour 3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>



// Classe ennemi

class Ennemi {

public:
    int id;
    char nom[30];
    int vie;
    int attack1;
    int attack2;

};

// Classe Allié

class Allie {

public:
    int id;
    char nom[30];
    int vie;
    int attack1;
    int attack2;

};

// Fonction pour créer des alliés

void create_allie() {

    for (int i = 0; i < 2; i++) {

        Allie compagnon;

        std::cout << "Creer votre pokemon n " << i+1 << "! :\n";
        std::cout << "Donner un nom : ";

        compagnon.id = i;
        std::cin >> compagnon.nom;

        std::cout << "Donner un nombre de points de vie : ";
        std::cin >> compagnon.vie;

        std::cout << "Donner un nombre de degats de l'attaque 1 : ";
        std::cin >> compagnon.attack1;

        std::cout << "Donner un nombre de degats de l'attaque 2 : ";
        std::cin >> compagnon.attack2;
        
        std::cout << compagnon.id << "\n" << compagnon.nom << "\n" << compagnon.vie << "\n" << compagnon.attack1 << "\n" << compagnon.attack2 << "\n";

    }

}

int main()
{
    std::cout << "Bonjour jeune aventurier !\n";

    create_allie();

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
