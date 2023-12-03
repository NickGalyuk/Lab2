#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Aeroflot.h"
#include "RecordsManager.h"
#include "FileManager.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\nMеню:\n1. Задание 1 - Аэрофлот\n2. Задание 2 - Слова, начинающиеся с гласной буквы\n3. Выход\n";
        std::cout << "Введите команду: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
           // std::cout << "Dobro pojalovat v Menedzher po deloproizvodstvu Aeroporta!\n" << std::endl;

            RecordsManager recordsManager;

            // Тестирование конструкторов и деструктора
            AEROFLOT testRecord("TestDestination", 123, "TestAircraft");
            RecordsManager testManager;
            testManager.addRecord(testRecord);
            int choice;
            do {
                std::cout << "\nMеню:\n1. Ввести данные\n2. Сортировать данные\n3. Вывисти записи по месту назначения\n"
                    "4. Сохранить в фаил\n5. Загрузить из файла\n6. Выйти\n";
                std::cout << "Введите команду: ";
                std::cin >> choice;

                switch (choice) {
                case 1: {
                    std::string destination;
                    int flightNumber;
                    std::string aircraftType;

                    std::cout << "Введите пунк назначения: ";
                    std::cin >> destination;

                    std::cout << "Введите номер рейса: ";
                    std::cin >> flightNumber;

                    std::cout << "Введите тип самолета: ";
                    std::cin >> aircraftType;

                    AEROFLOT newRecord(destination, flightNumber, aircraftType);
                    recordsManager.addRecord(newRecord);
                    break;
                }
                case 2:
                    recordsManager.sortRecords();
                    std::cout << "Данные осортированы по номеру рейса." << std::endl;
                    break;
                case 3: {
                    std::string searchDestination;
                    std::cout << "Введите пунк назначения для поиска: ";
                    std::cin >> searchDestination;
                    recordsManager.displayRecordsByDestination(searchDestination);
                    break;
                }
                case 4:
                    FileManager::writeToFile(recordsManager, "records.txt");
                    std::cout << "Данные сохранены в фаил 'records.txt'." << std::endl;
                    break;
                case 5:
                    recordsManager = RecordsManager(); // Очищаем текущие записи
                    FileManager::readFromFile(recordsManager, "records.txt");
                    std::cout << "Данные загружены из файла 'records.txt'." << std::endl;
                    break;
                case 6:
                    std::cout << "Выход!" << std::endl;
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
            std::ifstream inputFile("task2.txt");
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
            std::cout << "Слова, начинающиеся с гласной буквы:\n";
            for (const auto& w : vowelWords) {
                std::cout << w << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Выход!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
