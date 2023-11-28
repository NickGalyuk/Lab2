#pragma once
#ifndef RECORDSMANAGER_H
#define RECORDSMANAGER_H

#include "Aeroflot.h"

class RecordsManager {
public:
    RecordsManager();
    ~RecordsManager();

    void addRecord(const AEROFLOT& record);
    void sortRecords();
    void displayRecordsByDestination(const std::string& destination) const;
    int getSize() const;
    const AEROFLOT& getRecord(int index) const;

private:
    AEROFLOT* records;
    int size;
    int capacity;

    void resize();
};

#endif // RECORDSMANAGER_H

