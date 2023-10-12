// test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>



class Vaisseau {
public:
    int id;
    std::string nom;
    int vie;
    int missiles;
    int plasma;
    int mc;
    int shieldPower;
    int fsdCldw;
    int reparation;

};

class Ennemie {
public:
    int id;
    std::string nom;
    int vie;
    int attack1;
    int attack2;
    int armure;
    int fuite;
    int regen;

};



// Fonction permettant de créer le vaisseau du joueur en fonction de la difficulté
int createVaisseau(int difficulte) {
    // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Définir des noms de vaisseau prédéfinis
    std::vector<std::string> vaisseauNom = { "Chieftain", "Kraken", "Kom'Rk" };
    int index = std::rand() % vaisseauNom.size();
    std::string value = vaisseauNom[index]; // un nom de vaisseau aléatoire pris de la liste

    int hp = 250;

    Vaisseau vaisseau;

    switch (difficulte) {
    case 1:
        vaisseau.id = 0;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 15;
        vaisseau.plasma = 45;
        vaisseau.mc = 300;
        vaisseau.shieldPower = 30;
        vaisseau.fsdCldw = 2;
        vaisseau.reparation = 15;
        break;

    case 2:
        vaisseau.id = 0;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 10;
        vaisseau.plasma = 30;
        vaisseau.mc = 200;
        vaisseau.shieldPower = 20;
        vaisseau.fsdCldw = 3;
        vaisseau.reparation = 10;
        break;

    case 3:
        vaisseau.id = 0;
        vaisseau.nom = value;
        vaisseau.vie = hp;
        vaisseau.missiles = 5;
        vaisseau.plasma = 20;
        vaisseau.mc = 150;
        vaisseau.shieldPower = 10;
        vaisseau.fsdCldw = 4;
        vaisseau.reparation = 5;
        break;

    default:
        // Gérer la valeur de difficulté par défaut ici
        break;
    }

    std::ofstream VaisseauFile("Vaisseau.txt", std::ios::trunc);

    if (!VaisseauFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return -1; // Retourner une valeur d'erreur
    }
    else {
        VaisseauFile << "ID: " << vaisseau.id << std::endl << "Nom: " << vaisseau.nom << std::endl << "Vie: " << vaisseau.vie << std::endl << "Missiles: " << vaisseau.missiles << std::endl << "Plasma: " << vaisseau.plasma << std::endl << "MC: " << vaisseau.mc << std::endl << "Shield-Power: " << vaisseau.shieldPower << std::endl << "FSDcldw: " << vaisseau.fsdCldw << std::endl << "Reparation: " << vaisseau.reparation << std::endl;
        VaisseauFile.close();
    }

    std::cout << "ID: " << vaisseau.id << std::endl << "Nom: " << vaisseau.nom << std::endl << "Vie: " << vaisseau.vie << std::endl << "Missiles: " << vaisseau.missiles << std::endl << "Plasma: " << vaisseau.plasma << std::endl << "MC: " << vaisseau.mc << std::endl << "Shield-Power: " << vaisseau.shieldPower << std::endl << "FSDcldw: " << vaisseau.fsdCldw << std::endl << "Reparation: " << vaisseau.reparation << std::endl;

    return 0; // Renvoyer 0 pour indiquer le succès
}




// Fonction permettant de créer un ennemi en fonction de la difficulté
int createEnnemie(int difficulte) {
    // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Définir des noms d'ennemis prédéfinis
    std::vector<std::string> ennemieNoms = { "Xenomorphe", "Predator", "Garry" };
    int index = std::rand() % ennemieNoms.size();
    std::string value = ennemieNoms[index]; // Un nom de vaisseau aléatoire pris de la liste

    Ennemie ennemie;
    ennemie.id = index + 1; // Utiliser l'index (0, 1, 2) comme ID (1, 2, 3)
    ennemie.nom = value;

    switch (difficulte) {

    case 1:

        switch (index) {

        case 0:

            ennemie.vie = 400;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 300;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 600;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;
        }

        break; // Ajoutez cette ligne pour sortir du premier switch

    case 2:

        switch (index) {

        case 0:

            ennemie.vie = 500;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 400;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 700;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        }

        break; // Ajoutez cette ligne pour sortir du deuxième switch

    case 3:

        switch (index) {

        case 0:

            ennemie.vie = 600;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 1:

            ennemie.vie = 500;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        case 2:

            ennemie.vie = 1000;
            ennemie.attack1 = 15;
            ennemie.attack2 = 45;
            ennemie.armure = 300;
            ennemie.fuite = 30;
            ennemie.regen = 2;
            break;

        }

        break; // Ajoutez cette ligne pour sortir du troisième switch

    default:

        break;
    }

    std::ofstream EnnemiFile("Ennemi.txt", std::ios::trunc);

    if (!EnnemiFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return -1; // Retourner une valeur d'erreur
    }
    else {
        EnnemiFile << "ID: " << ennemie.id << std::endl << "Nom: " << ennemie.nom << std::endl << "Vie: " << ennemie.vie << std::endl << "Attaque1: " << ennemie.attack1 << std::endl << "Attaque2: " << ennemie.attack2 << std::endl << "Armure: " << ennemie.armure << std::endl << "Fuite: " << ennemie.fuite << std::endl << "Regeneration: " << ennemie.regen << std::endl;
        EnnemiFile.close();
    }

    std::cout << "ID: " << ennemie.id << std::endl << "Nom: " << ennemie.nom << std::endl << "Vie: " << ennemie.vie << std::endl << "Attaque1: " << ennemie.attack1 << std::endl << "Attaque2: " << ennemie.attack2 << std::endl << "Armure: " << ennemie.armure << std::endl << "Fuite: " << ennemie.fuite << std::endl << "Regeneration: " << ennemie.regen << std::endl;

    return 0; // Renvoyer 0 pour indiquer le succès
}



int main() {

    std::cout << "Bonjour jeune Astronaute !" << std::endl;

    int difficulte;

    std::cout << "Choisissez votre niveau de difficulte : 1 - Facile    2 - Normal    3 - Difficile" << std::endl;

    std::cout << "Difficulte : ";

    std::cin >> difficulte;

    createVaisseau(difficulte);

    createEnnemie(difficulte);

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
