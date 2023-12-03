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
        std::cout << "\nM���:\n1. ������� 1 - ��������\n2. ������� 2 - �����, ������������ � ������� �����\n3. �����\n";
        std::cout << "������� �������: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
           // std::cout << "Dobro pojalovat v Menedzher po deloproizvodstvu Aeroporta!\n" << std::endl;

            RecordsManager recordsManager;

            // ������������ ������������� � �����������
            AEROFLOT testRecord("TestDestination", 123, "TestAircraft");
            RecordsManager testManager;
            testManager.addRecord(testRecord);
            int choice;
            do {
                std::cout << "\nM���:\n1. ������ ������\n2. ����������� ������\n3. ������� ������ �� ����� ����������\n"
                    "4. ��������� � ����\n5. ��������� �� �����\n6. �����\n";
                std::cout << "������� �������: ";
                std::cin >> choice;

                switch (choice) {
                case 1: {
                    std::string destination;
                    int flightNumber;
                    std::string aircraftType;

                    std::cout << "������� ���� ����������: ";
                    std::cin >> destination;

                    std::cout << "������� ����� �����: ";
                    std::cin >> flightNumber;

                    std::cout << "������� ��� ��������: ";
                    std::cin >> aircraftType;

                    AEROFLOT newRecord(destination, flightNumber, aircraftType);
                    recordsManager.addRecord(newRecord);
                    break;
                }
                case 2:
                    recordsManager.sortRecords();
                    std::cout << "������ ������������ �� ������ �����." << std::endl;
                    break;
                case 3: {
                    std::string searchDestination;
                    std::cout << "������� ���� ���������� ��� ������: ";
                    std::cin >> searchDestination;
                    recordsManager.displayRecordsByDestination(searchDestination);
                    break;
                }
                case 4:
                    FileManager::writeToFile(recordsManager, "records.txt");
                    std::cout << "������ ��������� � ���� 'records.txt'." << std::endl;
                    break;
                case 5:
                    recordsManager = RecordsManager(); // ������� ������� ������
                    FileManager::readFromFile(recordsManager, "records.txt");
                    std::cout << "������ ��������� �� ����� 'records.txt'." << std::endl;
                    break;
                case 6:
                    std::cout << "�����!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                    break;
                }
            } while (choice != 6);

            break;
        }
        case 2: {
            // ������ ����������� ������ �� �����
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
            // ������������� ���������� ������ ��� ������ ����, ������������ � ������� ����
                std::stringstream ss(englishText);
            std::string word;
            std::vector<std::string> vowelWords;
            while (ss >> word) {
                // �������� �� ���������� ����� � �����
                if (std::all_of(word.begin(), word.end(), [](char c) { return
                    std::isalpha(c) || std::ispunct(c); })) {
                    // �������� ������ ����� ����� � ������� �������� ����� ��������� �� ���������
                        char firstChar = std::tolower(word[0]);
                    if (std::isalpha(firstChar) && (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u')) {
                        vowelWords.push_back(word);
                    }
                }
            }
            // ����� ����, ������������ � ������� ����
            std::cout << "�����, ������������ � ������� �����:\n";
            for (const auto& w : vowelWords) {
                std::cout << w << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "�����!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
