#include "RecordsManager.h"

RecordsManager::RecordsManager() : records(nullptr), size(0), capacity(0) {
    std::cout << "Default constructor called for RecordsManager." << std::endl;
}

RecordsManager::~RecordsManager() {
    delete[] records;
    std::cout << "Destructor called for RecordsManager." << std::endl;
}

void RecordsManager::addRecord(const AEROFLOT& record) {
    if (size == capacity) {
        resize();
    }
    records[size++] = record;
}

void RecordsManager::sortRecords() {
    // Используем сортировку пузырьком
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (records[j].getFlightNumber() > records[j + 1].getFlightNumber()) {
                std::swap(records[j], records[j + 1]);
            }
        }
    }
}

void RecordsManager::displayRecordsByDestination(const std::string& destination) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (records[i].getDestination() == destination) {
            std::cout << "Flight Number: " << records[i].getFlightNumber()
                << ", Aircraft Type: " << records[i].getAircraftType() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No flights found to destination: " << destination << std::endl;
    }
}

void RecordsManager::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    AEROFLOT* newRecords = new AEROFLOT[capacity];
    for (int i = 0; i < size; ++i) {
        newRecords[i] = records[i];
    }
    delete[] records;
    records = newRecords;
}

int RecordsManager::getSize() const {
    return size;
}

const AEROFLOT& RecordsManager::getRecord(int index) const {
    if (index >= 0 && index < size) {
        return records[index];
    }
    else {
        // Обработка ошибки, например, бросок исключения или возврат значения по умолчанию
        throw std::out_of_range("Index out of bounds");
    }
}