#pragma once
#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>

class AEROFLOT {
public:
    AEROFLOT();
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType);
    AEROFLOT(const AEROFLOT& other);
    ~AEROFLOT();

    // Методы доступа
    const std::string& getDestination() const;
    int getFlightNumber() const;
    const std::string& getAircraftType() const;

    // Перегруженные операции извлечения и вставки
    friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& aeroflot);
    friend std::istream& operator>>(std::istream& is, AEROFLOT& aeroflot);

    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(const std::string& aircraftType);

    AEROFLOT& operator=(const AEROFLOT& other);
private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;
};

#endif // AEROFLOT_H

