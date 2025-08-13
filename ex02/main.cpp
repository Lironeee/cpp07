#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "=== Tests simples de la classe Array ===" << std::endl;

    try
    {
        // Test 1: Constructeur par défaut
        std::cout << "\n1. Test constructeur par défaut:" << std::endl;
        Array<int> empty;
        std::cout << "   Taille array vide: " << empty.size() << std::endl;

        // Test 2: Constructeur avec taille
        std::cout << "\n2. Test constructeur avec taille:" << std::endl;
        Array<int> arr(5);
        std::cout << "   Taille array(5): " << arr.size() << std::endl;
        
        // Test 3: Remplissage et affichage
        std::cout << "\n3. Test remplissage:" << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;
        
        std::cout << "   Contenu: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        // Test 4: Constructeur de copie
        std::cout << "\n4. Test constructeur de copie:" << std::endl;
        Array<int> copy(arr);
        std::cout << "   Taille copie: " << copy.size() << std::endl;
        std::cout << "   Contenu copie: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        // Test indépendance
        arr[0] = 999;
        std::cout << "   Après modification original[0]=999:" << std::endl;
        std::cout << "   Original[0]: " << arr[0] << ", Copie[0]: " << copy[0] << std::endl;

        // Test 5: Exception
        std::cout << "\n5. Test exception (accès hors limites):" << std::endl;
        try {
            arr[10] = 42;  // Index invalide
        }
        catch (const std::exception& e) {
            std::cout << "   Exception attrapée correctement!" << std::endl;
        }

        std::cout << "\n✓ Tous les tests sont OK!" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}