// Jeu.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>



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

    for (int i = 0; i < 1; i++) {

        Allie compagnon;

        std::cout << "Creer votre pokemon n " << i+1 << " :" << std::endl;
        std::cout << "Donner un nom : ";

        compagnon.id = i;
        std::cin >> compagnon.nom;

        std::cout << "Donner un nombre de points de vie : ";
        std::cin >> compagnon.vie;

        std::cout << "Donner une valeur de degats de l'attaque 1 : ";
        std::cin >> compagnon.attack1;

        std::cout << "Donner une valeur de degats de l'attaque 2 : ";
        std::cin >> compagnon.attack2;

        //std::ofstream allieFile;
        //allieFile.open("Allie.txt", std::ios::in);

        std::ofstream AllieFile("Allie.txt", std::ios::in);
        AllieFile << "ID: " << compagnon.id << std::endl << "Nom: " << compagnon.nom << std::endl << "Vie: " << compagnon.vie << std::endl << "Attack1: " << compagnon.attack1 << std::endl << "Attack2: " << compagnon.attack2 << std::endl;

        
        std::cout << compagnon.id << std::endl << compagnon.nom << std::endl << compagnon.vie << std::endl << compagnon.attack1 << std::endl << compagnon.attack2 << std::endl;

    }

}

// Fonction pour créer des ennemies

void create_ennemi() {

}



int main()
{
    std::cout << "Bonjour jeune aventurier !" << std::endl;

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
