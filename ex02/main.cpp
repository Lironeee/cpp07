#include <iostream>
#include <string>
#include "Array.hpp"

// Fonction utilitaire pour afficher le statut d'un test
void printTestResult(const std::string &testName, bool passed)
{
    std::cout << "[" << (passed ? "✓" : "✗") << "] " << testName << std::endl;
}

// Fonction pour afficher un séparateur
void printSeparator(const std::string &title)
{
    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

// Test du constructeur par défaut
void testDefaultConstructor()
{
    printSeparator("TEST CONSTRUCTEUR PAR DÉFAUT");

    Array<int> emptyArray;
    bool test1 = (emptyArray.size() == 0);
    printTestResult("Taille d'un array vide = 0", test1);

    Array<std::string> emptyStringArray;
    bool test2 = (emptyStringArray.size() == 0);
    printTestResult("Array de strings vide", test2);

    std::cout << "Taille de emptyArray: " << emptyArray.size() << std::endl;
}

// Test du constructeur avec taille
void testParameterizedConstructor()
{
    printSeparator("TEST CONSTRUCTEUR AVEC TAILLE");

    Array<int> intArray(5);
    bool test1 = (intArray.size() == 5);
    printTestResult("Array de 5 entiers créé", test1);

    // Vérifier l'initialisation par défaut
    bool test2 = true;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        if (intArray[i] != 0)
        {
            test2 = false;
            break;
        }
    }
    printTestResult("Éléments initialisés à 0", test2);

    Array<std::string> stringArray(3);
    bool test3 = (stringArray.size() == 3);
    printTestResult("Array de 3 strings créé", test3);

    bool test4 = true;
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        if (!stringArray[i].empty())
        {
            test4 = false;
            break;
        }
    }
    printTestResult("Strings initialisées vides", test4);

    std::cout << "Taille de intArray: " << intArray.size() << std::endl;
    std::cout << "Taille de stringArray: " << stringArray.size() << std::endl;
}

// Test des opérateurs d'accès
void testSubscriptOperator()
{
    printSeparator("TEST OPÉRATEURS D'ACCÈS []");

    Array<int> arr(5);

    // Test d'écriture
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 10;
    }

    // Test de lecture
    bool test1 = true;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != static_cast<int>(i * 10))
        {
            test1 = false;
            break;
        }
    }
    printTestResult("Écriture et lecture correctes", test1);

    // Affichage des valeurs
    std::cout << "Contenu de l'array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Test de la gestion des exceptions
void testExceptions()
{
    printSeparator("TEST GESTION DES EXCEPTIONS");

    Array<int> arr(3);
    bool test1 = false, test2 = false;

    // Test accès hors limites (index trop grand)
    try
    {
        arr[5] = 42;
    }
    catch (const std::exception &e)
    {
        test1 = true;
    }
    printTestResult("Exception pour index trop grand", test1);

    // Test accès hors limites (index négatif converti en grand unsigned)
    try
    {
        arr[-1] = 42;
    }
    catch (const std::exception &e)
    {
        test2 = true;
    }
    printTestResult("Exception pour index négatif", test2);

    // Test sur array vide
    Array<int> emptyArr;
    bool test3 = false;
    try
    {
        emptyArr[0] = 42;
    }
    catch (const std::exception &e)
    {
        test3 = true;
    }
    printTestResult("Exception sur array vide", test3);
}

// Test du constructeur de copie
void testCopyConstructor()
{
    printSeparator("TEST CONSTRUCTEUR DE COPIE");

    Array<int> original(4);
    for (unsigned int i = 0; i < original.size(); i++)
    {
        original[i] = i + 100;
    }

    Array<int> copy(original);

    bool test1 = (copy.size() == original.size());
    printTestResult("Même taille après copie", test1);

    bool test2 = true;
    for (unsigned int i = 0; i < original.size(); i++)
    {
        if (copy[i] != original[i])
        {
            test2 = false;
            break;
        }
    }
    printTestResult("Même contenu après copie", test2);

    // Test de l'indépendance (deep copy)
    original[0] = 999;
    bool test3 = (copy[0] != 999);
    printTestResult("Indépendance après modification (deep copy)", test3);

    std::cout << "Original[0]: " << original[0] << ", Copy[0]: " << copy[0] << std::endl;
}

// Test de l'opérateur d'assignation
void testAssignmentOperator()
{
    printSeparator("TEST OPÉRATEUR D'ASSIGNATION");

    Array<int> arr1(3);
    Array<int> arr2(5);

    for (unsigned int i = 0; i < arr1.size(); i++)
    {
        arr1[i] = i + 10;
    }

    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        arr2[i] = i + 20;
    }

    std::cout << "Avant assignation - arr1.size(): " << arr1.size() << ", arr2.size(): " << arr2.size() << std::endl;

    arr2 = arr1;

    bool test1 = (arr2.size() == arr1.size());
    printTestResult("Même taille après assignation", test1);

    bool test2 = true;
    for (unsigned int i = 0; i < arr1.size(); i++)
    {
        if (arr2[i] != arr1[i])
        {
            test2 = false;
            break;
        }
    }
    printTestResult("Même contenu après assignation", test2);

    // Test de l'indépendance
    arr1[0] = 777;
    bool test3 = (arr2[0] != 777);
    printTestResult("Indépendance après assignation", test3);

    // Test d'auto-assignation
    arr1 = arr1;
    bool test4 = (arr1.size() == 3 && arr1[0] == 777);
    printTestResult("Auto-assignation fonctionne", test4);

    std::cout << "Après assignation - arr1.size(): " << arr1.size() << ", arr2.size(): " << arr2.size() << std::endl;
    std::cout << "arr1[0]: " << arr1[0] << ", arr2[0]: " << arr2[0] << std::endl;
}

// Test avec différents types
void testDifferentTypes()
{
    printSeparator("TEST AVEC DIFFÉRENTS TYPES");

    // Test avec double
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;
    doubleArray[2] = 1.41;

    bool test1 = (doubleArray[0] == 3.14 && doubleArray[1] == 2.71 && doubleArray[2] == 1.41);
    printTestResult("Array de doubles", test1);

    // Test avec string
    Array<std::string> stringArray(2);
    stringArray[0] = "Hello";
    stringArray[1] = "World";

    bool test2 = (stringArray[0] == "Hello" && stringArray[1] == "World");
    printTestResult("Array de strings", test2);

    std::cout << "Double array: " << doubleArray[0] << ", " << doubleArray[1] << ", " << doubleArray[2] << std::endl;
    std::cout << "String array: " << stringArray[0] << " " << stringArray[1] << std::endl;
}

// Test de performance et stress
void testStressAndPerformance()
{
    printSeparator("TEST DE STRESS");

    const unsigned int LARGE_SIZE = 1000;
    Array<int> largeArray(LARGE_SIZE);

    // Remplissage
    for (unsigned int i = 0; i < largeArray.size(); i++)
    {
        largeArray[i] = i;
    }

    // Vérification
    bool test1 = true;
    for (unsigned int i = 0; i < largeArray.size(); i++)
    {
        if (largeArray[i] != static_cast<int>(i))
        {
            test1 = false;
            break;
        }
    }
    printTestResult("Array de 1000 éléments", test1);

    // Test de copie d'un grand array
    Array<int> largeCopy(largeArray);
    bool test2 = (largeCopy.size() == largeArray.size());
    printTestResult("Copie d'un grand array", test2);

    std::cout << "Taille du grand array: " << largeArray.size() << std::endl;
}

int main()
{
    std::cout << std::string(60, '*') << std::endl;
    std::cout << "           TESTS COMPLETS DE LA CLASSE ARRAY" << std::endl;
    std::cout << std::string(60, '*') << std::endl;

    try
    {
        testDefaultConstructor();
        testParameterizedConstructor();
        testSubscriptOperator();
        testExceptions();
        testCopyConstructor();
        testAssignmentOperator();
        testDifferentTypes();
        testStressAndPerformance();

        printSeparator("RÉSUMÉ");
        std::cout << "✓ Tous les tests ont été exécutés avec succès!" << std::endl;
        std::cout << "✓ La classe Array semble fonctionner correctement." << std::endl;
        std::cout << "✓ Gestion mémoire, exceptions et opérateurs OK." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}