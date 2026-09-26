#include <iostream>
#include <iomanip>

#define NOMINMAX
#include <windows.h>


#include <string>
#include <vector>
#include <limits>

struct Animal
{
    std::string nameOfAnimal;
    std::string typeOfAnimal;
    int animalIdentificationNumber = 0;
};

void startOutput()
{
    std::cout << "===== ZOO MANAGEMENT SYSTEM =====" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Додати тварину" << std::endl;
    std::cout << "2. Переглянути всіх тварин" << std::endl;
    std::cout << "3. Знайти тварину" << std::endl;
    std::cout << "4. Редагувати тварину" << std::endl;
    std::cout << "5. Видалити тварину" << std::endl;
    std::cout << "0. Вихід" << std::endl;
    std::cout << std::endl;
    std::cout << "| Оберіть дію: ";
}

void correctInputCheckerForInt(int& value)
{
    std::cin >> value;
    std::cout << std::endl;

    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некоректне значення! Введіть ціле число: ";
        std::cin >> value;
    }
}

void addNewAnimal(std::vector<Animal>& animals, int& lastAnimalIdentificationNumber)
{
    std::string newAnimalName;
    std::string typeOfNewAnimal;
    int newAnimalIdentificationNumber;
    Animal newAnimalData;

    std::cout << "Введіть ім'я нової тварини: ";
    std::cin >> newAnimalName;
    std::cout << "Введіть вид нової тварини: ";
    std::cin >> typeOfNewAnimal;

    lastAnimalIdentificationNumber++;
    newAnimalIdentificationNumber = lastAnimalIdentificationNumber;

    newAnimalData.nameOfAnimal = newAnimalName;
    newAnimalData.typeOfAnimal = typeOfNewAnimal;
    newAnimalData.animalIdentificationNumber = newAnimalIdentificationNumber;

    animals.push_back(newAnimalData);

    std::cout << "Тварину додано успішно!" << std::endl;
}

void showAnimalList(const std::vector<Animal>& animals)
{
    if (animals.empty())
    {
        std::cout << "Вивід пустого списку неможливий!" << std::endl;
        return;
    }

    std::cout << "===== СПИСОК ТВАРИН =====" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < animals.size(); i++)
    {
        std::cout << std::setw(5) << animals[i].animalIdentificationNumber
            << std::setw(10) << animals[i].nameOfAnimal
            << std::setw(15) << animals[i].typeOfAnimal << std::endl;
    }
}

int binaryCycleForNeededAnimalSearch(const std::vector<Animal>& animals, int identificatorOfAnimalToBeFound)
{
    if (animals.empty())
    {
        return -1;
    }

    int leftIndexOfTheVector = 0,
        rightIndexOfTheVector = animals.size() - 1,
        middlePartOfTheVector;

    while (leftIndexOfTheVector <= rightIndexOfTheVector)
    {
        middlePartOfTheVector = (leftIndexOfTheVector + rightIndexOfTheVector) / 2;

        if (animals[middlePartOfTheVector].animalIdentificationNumber == identificatorOfAnimalToBeFound)
        {
            return middlePartOfTheVector;
        }
        else if (animals[middlePartOfTheVector].animalIdentificationNumber < identificatorOfAnimalToBeFound)
        {
            leftIndexOfTheVector = middlePartOfTheVector + 1;
        }
        else
        {
            rightIndexOfTheVector = middlePartOfTheVector - 1;
        }
    }

    return -1;
}

void searchAnimalByIdentificationNumber(const std::vector<Animal>& animals)
{
    int identificatorOfAnimalToBeFound;

    if (animals.empty())
    {
        std::cout << "У списку немає даних для пошуку!" << std::endl;
        return;
    }

    std::cout << "Введіть ID тварини: ";
    correctInputCheckerForInt(identificatorOfAnimalToBeFound);

    int vectorElementOfSearchedAnimal = binaryCycleForNeededAnimalSearch(animals, identificatorOfAnimalToBeFound);

    if (vectorElementOfSearchedAnimal < 0)
    {
        std::cout << "Тварину з ID "
            << identificatorOfAnimalToBeFound << " не вдалось знайти." << std::endl;
        return;
    }

    std::cout << std::setw(5) << animals[vectorElementOfSearchedAnimal].animalIdentificationNumber
        << std::setw(10) << animals[vectorElementOfSearchedAnimal].nameOfAnimal
        << std::setw(15) << animals[vectorElementOfSearchedAnimal].typeOfAnimal << std::endl;
}

void editDataOfAnimal(std::vector<Animal>& animals)
{
    if (animals.empty())
    {
        std::cout << "У списку немає даних для редагування!" << std::endl;
        return;
    }

    int choiceOfActionsMenu;
    int identificatorOfAnimalToBeFound;
    std::string newNameOrTypeOfTheAnimal;

    std::cout << "Введіть ID тварини: ";
    correctInputCheckerForInt(identificatorOfAnimalToBeFound);

    int vectorElementOfSearchedAnimal = binaryCycleForNeededAnimalSearch(animals, identificatorOfAnimalToBeFound);

    if (vectorElementOfSearchedAnimal < 0)
    {
        std::cout << "Тварину з ID "
            << identificatorOfAnimalToBeFound << " не вдалось знайти." << std::endl;
        return;
    }

    std::cout << "1. Змінити ім'я тварини" << std::endl;
    std::cout << "2. Змінити вид тварини" << std::endl;
    std::cout << "0. Повернутись" << std::endl;
    std::cout << std::endl;

    std::cout << "Виберіть пункт меню: ";
    correctInputCheckerForInt(choiceOfActionsMenu);

    switch (choiceOfActionsMenu)
    {
        case 1:
            std::cout << "Введіть нове ім'я тварини: ";
            std::cin >> newNameOrTypeOfTheAnimal;

            animals[vectorElementOfSearchedAnimal].nameOfAnimal = newNameOrTypeOfTheAnimal;
            std::cout << "Ім'я тварини змінено успішно!" << std::endl;
            break;
        case 2:
            std::cout << "Введіть новий тип тварини: ";
            std::cin >> newNameOrTypeOfTheAnimal;

            animals[vectorElementOfSearchedAnimal].typeOfAnimal = newNameOrTypeOfTheAnimal;

            std::cout << "Тип тварини змінено успішно!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Помилка! Введіть корректне значення! " << std::endl;
            break;
    }
}

void deleteAnimalFromVector(std::vector<Animal>& animals)
{
    int identificatorOfAnimalToBeDeleted;

    if (animals.empty())
    {
        std::cout << "У списку немає даних для видалення!" << std::endl;
        return;
    }

    std::cout << "Введіть ID тварини: ";
    correctInputCheckerForInt(identificatorOfAnimalToBeDeleted);

    int vectorElementOfSearchedAnimal = binaryCycleForNeededAnimalSearch(animals, identificatorOfAnimalToBeDeleted);

    if (vectorElementOfSearchedAnimal < 0)
    {
        std::cout << "Тварину з ID "
            << identificatorOfAnimalToBeDeleted << " не вдалось знайти." << std::endl;
        return;
    }
    
    int confirmationOfDelete;
    std::cout << "Ви підтверджуєте видалення тварини? (1 - так / 0 - ні): ";
    correctInputCheckerForInt(confirmationOfDelete);

    while (confirmationOfDelete != 1 && confirmationOfDelete != 0)
    {
        std::cout << "Введіть коректне значення!: ";
        correctInputCheckerForInt(confirmationOfDelete);
    }

    if (confirmationOfDelete == 0)
    {
        return;
    }
    if (confirmationOfDelete == 1)
    {
        animals.erase(animals.begin() + vectorElementOfSearchedAnimal);
        std::cout << "Тварину видалено успішно!" << std::endl;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::vector<Animal> animals;
    int lastAnimalIdentificationNumber = 10000000;

    while (true)
    {   
        int choice;
        startOutput();
        correctInputCheckerForInt(choice);

        switch (choice)
        {
            case 1:
                addNewAnimal(animals, lastAnimalIdentificationNumber);
                break;
            case 2:
                showAnimalList(animals);
                break;
            case 3:
                searchAnimalByIdentificationNumber(animals);
                break;
            case 4:
                editDataOfAnimal(animals);
                break;
            case 5:
                deleteAnimalFromVector(animals);
                break;
            case 0:
                exit(0);
            default:
                std::cout << "Введіть корректне значення! " << std::endl;
                break;
        }
        std::cout << std::endl;
    }
}