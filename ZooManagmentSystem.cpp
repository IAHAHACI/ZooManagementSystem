#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <vector>

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

void addNewAnimal(std::vector<Animal>& animals)
{
    std::string newAnimalName;
    std::string typeOfNewAnimal;
    int newAnimalIdentificationNumber;
    Animal newAnimalData;

    std::cout << "Введіть ім'я нової тварини: ";
    std::cin >> newAnimalName;
    std::cout << "Введіть вид нової тварини: ";
    std::cin >> typeOfNewAnimal;
    std::cout << "Введіть ідентифікаційний номер нової тварини: ";
    std::cin >> newAnimalIdentificationNumber;

    newAnimalData.nameOfAnimal = newAnimalName;
    newAnimalData.typeOfAnimal = typeOfNewAnimal;
    newAnimalData.animalIdentificationNumber = newAnimalIdentificationNumber;

    animals.push_back(newAnimalData);

    std::cout << "Тварину додано успішно!" << std::endl;
}

void showAnimalList(const std::vector<Animal>& animals)
{
    std::cout << "===== СПИСОК ТВАРИН =====" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < animals.size(); i++)
    {
        std::cout << std::setw(5) << animals[i].animalIdentificationNumber
            << std::setw(5) << animals[i].nameOfAnimal
            << std::setw(15) << animals[i].typeOfAnimal << std::endl;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::vector<Animal> animals;

    while (true)
    {   
        int choice;
        startOutput();
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
                addNewAnimal(animals);
                break;
            case 2:
                showAnimalList(animals);
                break;
            case 3:
                //case 3
                break;
            case 4:
                // case 4
                break;
            case 5:
                // case 5
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
