#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include "RecordsManager.h"

class FileManager {
public:
    static void writeToFile(const RecordsManager& recordsManager, const std::string& filename);
    static void readFromFile(RecordsManager& recordsManager, const std::string& filename);
};

#endif // FILEMANAGER_H
