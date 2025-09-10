#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>

void saveStopsToFile(const std::string& filename);
void loadStopsFromFile(const std::string& filename);

void saveTransportsToFile(const std::string& filename);
void loadTransportsFromFile(const std::string& filename);

void saveRoutesToFile(const std::string& filename);
void loadRoutesFromFile(const std::string& filename);

void saveSchedulesToFile(const std::string& filename);
void loadSchedulesFromFile(const std::string& filename);

void saveAllData();
void loadAllData();

#endif
