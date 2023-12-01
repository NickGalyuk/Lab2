#include "FileManager.h"

void FileManager::writeToFile(const RecordsManager& recordsManager, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < recordsManager.getSize(); ++i) {
        outFile << recordsManager.getRecord(i).getDestination() << ' ' << recordsManager.getRecord(i).getFlightNumber() << ' ' << recordsManager.getRecord(i).getAircraftType() << std::endl;
    }

    outFile.close();
}

void FileManager::readFromFile(RecordsManager& recordsManager, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::string destination;
    int flightNumber;
    std::string aircraftType;

    while (inFile >> destination >> flightNumber >> aircraftType) {
        AEROFLOT newRecord(destination, flightNumber, aircraftType);
        recordsManager.addRecord(newRecord);
    }

    inFile.close();
}