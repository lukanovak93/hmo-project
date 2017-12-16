#pragma once
#include <string>
#include <vector>
#include <vector>

class ProblemInstance
{
    private:
        int _stopsCount;
        int _studentsCount;
        int _busCapacity;
        std::vector<std::pair<float, float> > _stops;
        std::vector<std::pair<float, float> > _students;
        std::vector<std::vector<float> > _stopDistances;
        std::vector<std::vector<int> > _availableStops;
    public:
        ProblemInstance(int, int, float, int, std::vector<std::pair<float, float> >, std::vector<std::pair<float, float> >);
        ~ProblemInstance();
        static ProblemInstance readFromFile(std::string);
        std::vector<int> getAvailableStops(int);
        float getStopsDistance(int, int);
        int getStopsCount();
        int getStudentsCount();
        int getBusCapacity();
};