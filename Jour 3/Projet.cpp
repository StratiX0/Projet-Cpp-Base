// Jeu.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Character {
public:
    int id;
    char nom[30];
    int vie;
    int attack1;
    int attack2;

    void setVie(int degat_subi) {
        vie -= degat_subi;
    }
};

// Fonction pour créer des alliés
void create_allie(std::vector<Character>& allies) {
    Character allie;

    std::cout << "Créer votre personnage n " << 1 << " :" << std::endl;
    allie.id = 1;

    std::cout << "Donner un nom : ";
    std::cin >> allie.nom;

    std::cout << "Donner un nombre de points de vie : ";
    std::cin >> allie.vie;

    std::cout << "Donner une valeur de dégâts de l'attaque 1 : ";
    std::cin >> allie.attack1;

    std::cout << "Donner une valeur de dégâts de l'attaque 2 : ";
    std::cin >> allie.attack2;

    std::ofstream AllieFile("Allie.txt", std::ios::app);

    if (!AllieFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return;
    }

    AllieFile << "ID: " << allie.id << std::endl << "Nom: " << allie.nom << std::endl << "Vie: " << allie.vie << std::endl << "Attack1: " << allie.attack1 << std::endl << "Attack2: " << allie.attack2 << std::endl;
    AllieFile.close();

    allies.push_back(allie);
}

// Fonction pour charger les alliés à partir du fichier
void load_allies(std::vector<Character>& allies) {
    std::ifstream AllieFile("Allie.txt");
    if (!AllieFile.is_open()) {
        std::cerr << "Le fichier n'existe pas. Créez d'abord des alliés." << std::endl;
        return;
    }

    Character allie;
    while (AllieFile >> allie.id) {
        AllieFile.ignore();
        AllieFile.getline(allie.nom, 30);
        AllieFile >> allie.vie >> allie.attack1 >> allie.attack2;
        allies.push_back(allie);
    }

    AllieFile.close();
}

int main() {
    std::cout << "Bonjour jeune aventurier !" << std::endl;

    std::vector<Character> allies;
    create_allie(allies);
    load_allies(allies);

    if (allies.empty()) {
        std::cout << "Aucun allié n'a été chargé. Créez des alliés d'abord." << std::endl;
    }
    else {
        std::cout << "Nombre d'alliés chargés : " << allies.size() << std::endl;
        for (const Character& allie : allies) {
            std::cout << "Nom : " << allie.nom << ", Vie : " << allie.vie << std::endl;
        }
    }

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
