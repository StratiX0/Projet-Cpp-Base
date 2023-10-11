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

    for (int i = 0; i < 3; i++) {

        Allie compagnon;

        std::cout << "Creer votre pokemon n " << i+1 << " :" << std::endl;
        std::cout << "Donner un nom : ";

        compagnon.id = i+1;
        std::cin >> compagnon.nom;

        std::cout << "Donner un nombre de points de vie : ";
        std::cin >> compagnon.vie;

        std::cout << "Donner une valeur de degats de l'attaque 1 : ";
        std::cin >> compagnon.attack1;

        std::cout << "Donner une valeur de degats de l'attaque 2 : ";
        std::cin >> compagnon.attack2;


        // Créer un objet ofstream pour écrire dans le fichier
        std::ofstream AllieFile;

        // Ouvrir le fichier en mode append (ajout)
        AllieFile.open("Allie.txt", std::ios::app);

        // Vérifier si l'ouverture du fichier a réussi
        if (!AllieFile.is_open()) {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        }

        // Écrire le texte dans le fichier
        AllieFile << "ID: " << compagnon.id << std::endl << "Nom: " << compagnon.nom << std::endl << "Vie: " << compagnon.vie << std::endl << "Attack1: " << compagnon.attack1 << std::endl << "Attack2: " << compagnon.attack2 << std::endl;

        // Fermer le fichier
        AllieFile.close();
        
        std::cout << compagnon.id << std::endl << compagnon.nom << std::endl << compagnon.vie << std::endl << compagnon.attack1 << std::endl << compagnon.attack2 << std::endl;

    }

}

// Fonction pour créer des ennemies

//void create_ennemi() {
//
//    for (int i = 0; i < 3; i++) {
//
//        Ennemi adversaire;
//
//        std::cout << "Creer votre pokemon n " << i + 1 << " :" << std::endl;
//        std::cout << "Donner un nom : ";
//
//        compagnon.id = i + 1;
//        std::cin >> compagnon.nom;
//
//        std::cout << "Donner un nombre de points de vie : ";
//        std::cin >> compagnon.vie;
//
//        std::cout << "Donner une valeur de degats de l'attaque 1 : ";
//        std::cin >> compagnon.attack1;
//
//        std::cout << "Donner une valeur de degats de l'attaque 2 : ";
//        std::cin >> compagnon.attack2;
//
//
//        // Créer un objet ofstream pour écrire dans le fichier
//        std::ofstream AllieFile;
//
//        // Ouvrir le fichier en mode append (ajout)
//        AllieFile.open("Allie.txt", std::ios::app);
//
//        // Vérifier si l'ouverture du fichier a réussi
//        if (!AllieFile.is_open()) {
//            std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
//        }
//
//        // Texte à ajouter au fichier
//        std::string texteAAjouter = "Ceci est du texte ajouté au fichier.\n";
//
//        // Écrire le texte dans le fichier
//        AllieFile << "ID: " << compagnon.id << std::endl << "Nom: " << compagnon.nom << std::endl << "Vie: " << compagnon.vie << std::endl << "Attack1: " << compagnon.attack1 << std::endl << "Attack2: " << compagnon.attack2 << std::endl;
//
//        // Fermer le fichier
//        AllieFile.close();
//
//        std::cout << compagnon.id << std::endl << compagnon.nom << std::endl << compagnon.vie << std::endl << compagnon.attack1 << std::endl << compagnon.attack2 << std::endl;
//
//    }
//
//}



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
