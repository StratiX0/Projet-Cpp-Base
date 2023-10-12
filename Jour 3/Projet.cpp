// test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

class Character {
public:
    int id;
    std::string nom;
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


// Définir des noms d'ennemis prédéfinis
std::vector<std::string> predefinedEnemyNames = { "Xenomorphe", "Predator", "Garry" };

// Fonction pour créer des ennemis avec des noms prédéfinis et des valeurs similaires aux alliés
void create_enemy(std::vector<Character>& enemies, const std::vector<Character>& allies) {
    Character enemy;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(0.8, 1.2);  // Variation de 20% autour de 1.0

    enemy.id = enemies.size() + 1;

    // Sélectionner un nom d'ennemi aléatoire parmi les noms prédéfinis
    int randomIndex = rand() % predefinedEnemyNames.size();
    enemy.nom = predefinedEnemyNames[randomIndex];

    // Génération de valeurs similaires aux alliés avec une variation de 20%
    const Character& randomAlly = allies[rand() % allies.size()];
    enemy.vie = static_cast<int>(randomAlly.vie * distribution(gen));
    enemy.attack1 = static_cast<int>(randomAlly.attack1 * distribution(gen));
    enemy.attack2 = static_cast<int>(randomAlly.attack2 * distribution(gen));

    std::ofstream EnemyFile("Enemy.txt", std::ios::app);

    if (!EnemyFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return;
    }

    EnemyFile << "ID: " << enemy.id << std::endl << "Nom: " << enemy.nom << std::endl << "Vie: " << enemy.vie << std::endl << "Attack1: " << enemy.attack1 << std::endl << "Attack2: " << enemy.attack2 << std::endl;
    EnemyFile.close();

    enemies.push_back(enemy);
}


//// Fonction pour créer des alliés
//void create_enemy(std::vector<Character>& enemies) {
//    Character enemy;
//
//    std::cout << "Créer votre personnage n " << 1 << " :" << std::endl;
//    enemy.id = 1;
//
//    std::cout << "Donner un nom : ";
//    std::cin >> enemy.nom;
//
//    std::cout << "Donner un nombre de points de vie : ";
//    std::cin >> enemy.vie;
//
//    std::cout << "Donner une valeur de dégâts de l'attaque 1 : ";
//    std::cin >> enemy.attack1;
//
//    std::cout << "Donner une valeur de dégâts de l'attaque 2 : ";
//    std::cin >> enemy.attack2;
//
//    std::ofstream EnemyFile("Enemy.txt", std::ios::app);
//
//    if (!EnemyFile.is_open()) {
//        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
//        return;
//    }
//
//    EnemyFile << "ID: " << enemy.id << std::endl << "Nom: " << enemy.nom << std::endl << "Vie: " << enemy.vie << std::endl << "Attack1: " << enemy.attack1 << std::endl << "Attack2: " << enemy.attack2 << std::endl;
//    EnemyFile.close();
//
//    enemies.push_back(enemy);
//}



// Fonction pour charger les alliés à partir du fichier
void load_allies(std::vector<Character>& allies) {
    std::ifstream AllieFile("Allie.txt");
    if (!AllieFile.is_open()) {
        std::cerr << "Le fichier n'existe pas. Créez d'abord des alliés." << std::endl;
        return;
    }

    Character allie;
    std::string line;
    while (std::getline(AllieFile, line)) {
        if (line.find("ID: ") == 0) {
            // Lire l'ID
            allie.id = std::stoi(line.substr(4));
        }
        else if (line.find("Nom: ") == 0) {
            // Lire le nom
            allie.nom = line.substr(5);
        }
        else if (line.find("Vie: ") == 0) {
            // Lire la vie
            allie.vie = std::stoi(line.substr(5));
        }
        else if (line.find("Attack1: ") == 0) {
            // Lire attack1
            allie.attack1 = std::stoi(line.substr(8));
        }
        else if (line.find("Attack2: ") == 0) {
            // Lire attack2
            allie.attack2 = std::stoi(line.substr(8));
            allies.push_back(allie);
        }
    }

    AllieFile.close();
}

// Fonction pour charger les alliés à partir du fichier
void load_enemies(std::vector<Character>& enemies) {
    std::ifstream EnemyFile("Enemy.txt");
    if (!EnemyFile.is_open()) {
        std::cerr << "Le fichier n'existe pas. Créez d'abord des alliés." << std::endl;
        return;
    }

    Character enemy;
    std::string line;
    while (std::getline(EnemyFile, line)) {
        if (line.find("ID: ") == 0) {
            // Lire l'ID
            enemy.id = std::stoi(line.substr(4));
        }
        else if (line.find("Nom: ") == 0) {
            // Lire le nom
            enemy.nom = line.substr(5);
        }
        else if (line.find("Vie: ") == 0) {
            // Lire la vie
            enemy.vie = std::stoi(line.substr(5));
        }
        else if (line.find("Attack1: ") == 0) {
            // Lire attack1
            enemy.attack1 = std::stoi(line.substr(8));
        }
        else if (line.find("Attack2: ") == 0) {
            // Lire attack2
            enemy.attack2 = std::stoi(line.substr(8));
            enemies.push_back(enemy);
        }
    }

    EnemyFile.close();
}


int main() {
    std::cout << "Bonjour jeune aventurier !" << std::endl;

    std::vector<Character> allies;
    create_allie(allies);
    std::vector<Character> enemies;
    create_enemy(enemies, allies);
    load_allies(allies);
    load_enemies(enemies);

    if (allies.empty()) {
        std::cout << "Aucun allié n'a été chargé. Créez des alliés d'abord." << std::endl;
    }
    else {
        std::cout << "Nombre d'alliés chargés : " << allies.size() << std::endl;
        for (const Character& allie : allies) {
            std::cout << "Nom : " << allie.nom << ", Vie : " << allie.vie << ", Attaque 1 : " << allie.attack1 << ", Attaque 2 : " << allie.attack2 << std::endl;
        }
    }

    if (enemies.empty()) {
        std::cout << "Aucun ennemie n'a été chargé. Créez des ennemies d'abord." << std::endl;
    }
    else {
        std::cout << "Nombre d'ennemies chargés : " << allies.size() << std::endl;
        for (const Character& enemy : enemies) {
            std::cout << "Nom : " << enemy.nom << ", Vie : " << enemy.vie << ", Attaque 1 : " << enemy.attack1 << ", Attaque 2 : " << enemy.attack2 << std::endl;
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
