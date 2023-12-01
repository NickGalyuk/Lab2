#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Aeroflot.h"
#include "RecordsManager.h"
#include "FileManager.h"

int main() {
    int choice;
    do {
        std::cout << "\nMenu:\n1. Task 1 - Menedzher po deloproizvodstvu Aeroporta\n2. Task 2 - Clova, nachinaychie s glasnih\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Dobro pojalovat v Menedzher po deloproizvodstvu Aeroporta!\n" << std::endl;

            RecordsManager recordsManager;

            // Тестирование конструкторов и деструктора
            AEROFLOT testRecord("TestDestination", 123, "TestAircraft");
            RecordsManager testManager;
            testManager.addRecord(testRecord);
            int choice;
            do {
                std::cout << "\nMenu:\n1. Vvesti dannie\n2. Sortirovat dannie\n3. Vivesti zapisi po mestu naznachenia\n"
                    "4. Sohranit v fail\n5. Zagruzit iz faila\n6. Exit\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;

                switch (choice) {
                case 1: {
                    std::string destination;
                    int flightNumber;
                    std::string aircraftType;

                    std::cout << "Vvedite punkt naznachenia: ";
                    std::cin >> destination;

                    std::cout << "Vvedite nimer reisa: ";
                    std::cin >> flightNumber;

                    std::cout << "Vvedite tip samoleta: ";
                    std::cin >> aircraftType;

                    AEROFLOT newRecord(destination, flightNumber, aircraftType);
                    recordsManager.addRecord(newRecord);
                    break;
                }
                case 2:
                    recordsManager.sortRecords();
                    std::cout << "Dannie otsortirovani po nomeru reisa." << std::endl;
                    break;
                case 3: {
                    std::string searchDestination;
                    std::cout << "Vvedite punkt naznachenia dlya poiska: ";
                    std::cin >> searchDestination;
                    recordsManager.displayRecordsByDestination(searchDestination);
                    break;
                }
                case 4:
                    FileManager::writeToFile(recordsManager, "records.txt");
                    std::cout << "Dannie sohraneni v fail 'records.txt'." << std::endl;
                    break;
                case 5:
                    recordsManager = RecordsManager(); // Очищаем текущие записи
                    FileManager::readFromFile(recordsManager, "records.txt");
                    std::cout << "Dannie zagrujeni s faila 'records.txt'." << std::endl;
                    break;
                case 6:
                    std::cout << "Exiting the program. Goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                    break;
                }
            } while (choice != 6);

            break;
        }
        case 2: {
            // Чтение английского текста из файла
            std::ifstream inputFile("english_text.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening file for reading." << std::endl;
                return 1;
            }
            std::string englishText;
            std::string line;
            while (std::getline(inputFile, line)) {
                    englishText += line + "\n";
            }
            inputFile.close();
            // Использование строкового потока для чтения слов, начинающихся с гласных букв
                std::stringstream ss(englishText);
            std::string word;
            std::vector<std::string> vowelWords;
            while (ss >> word) {
                // Проверка на отсутствие чисел в слове
                if (std::all_of(word.begin(), word.end(), [](char c) { return
                    std::isalpha(c) || std::ispunct(c); })) {
                    // Приводим первую букву слова к нижнему регистру перед проверкой на гласность
                        char firstChar = std::tolower(word[0]);
                    if (std::isalpha(firstChar) && (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u')) {
                        vowelWords.push_back(word);
                    }
                }
            }
            // Вывод слов, начинающихся с гласных букв
            std::cout << "Slova, nachinayushchiesya s glasnih:\n";
            for (const auto& w : vowelWords) {
                std::cout << w << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
