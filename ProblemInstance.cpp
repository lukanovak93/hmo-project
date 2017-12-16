#include "ProblemInstance.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

ProblemInstance ProblemInstance::readFromFile(std::string path)
{
    std::ifstream file;
    file.open(path);
    std::string line;

    int stopsCount, busCapacity, studentsCount;
    float maxWalk;

    getline(file, line);
    std::sscanf(line.c_str(), "%d stops, %d students, %f maximum walk, %d capacity", &stopsCount, &studentsCount, &maxWalk, &busCapacity);

    getline(file, line); // Skip empty line line
    std::vector<std::pair<float, float> > stops;
    for (int i = 0; i < stopsCount; i++)
    {
        getline(file, line);
        float x, y;
        std::sscanf(line.c_str(), "%d %f %f", &i, &x, &y);
        stops.push_back(std::make_pair(x, y));
    }

    getline(file, line); // Skip empty line line
    getline(file, line); // Skip empty line line
    std::vector<std::pair<float, float> > students;
    for (int i = 0; i < studentsCount; i++)
    {
        getline(file, line);
        float x, y;
        int j;
        std::sscanf(line.c_str(), "%d %f %f", &j, &x, &y);
        students.push_back(std::make_pair(x, y));
    }
    
    file.close();
    return ProblemInstance(stopsCount, studentsCount, maxWalk, busCapacity, stops, students);
}

std::vector<std::vector<int> > calculateAvailableStops(int stopsCount, int studentsCount, std::vector<std::pair<float, float> > stops, std::vector<std::pair<float, float> > students, float maxWalkingDistance)
{
    std::vector<std::vector<int> > studentStops;
    for (int i = 0; i < studentsCount; i++)
    {
        float student_x = students[i].first;
        float student_y = students[i].second;
        std::vector<int> available;
        
        for (int j = 0; j < stopsCount; j++)
        {
            float stop_x = stops[j].first;
            float stop_y = stops[j].second;
            float distance = std::sqrt(std::pow(student_x - stop_x, 2) + std::pow(student_y - stop_y, 2));
            
            if (distance <= maxWalkingDistance)
            {
                available.push_back(j);
            }
        }
        studentStops.push_back(available);
    }
    return studentStops;   
}

std::vector<std::vector<float> > calculateStopDistances(int stopsCount, std::vector<std::pair<float, float> > stops)
{
    std::vector<std::vector<float> > distances;
    for (int i = 0; i < stopsCount; i++)
    {
        std::vector<float> currentStopDistances;
        for (int j = 0; j < stopsCount; j++)
        {
            float x1 = stops[i].first;
            float y1 = stops[i].second;
            float x2 = stops[j].first;
            float y2 = stops[j].second;
            float distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
            currentStopDistances.push_back(distance);
        }
        distances.push_back(currentStopDistances);
    }
    return distances;
}

ProblemInstance::ProblemInstance(int stopsCount, int studentsCount, float maxWalkingDistance, int busCapacity, std::vector<std::pair<float, float> > stops, std::vector<std::pair<float, float> > students)
{
    ProblemInstance::_stopsCount = stopsCount;
    ProblemInstance::_studentsCount = studentsCount;
    ProblemInstance::_busCapacity = busCapacity;
    ProblemInstance::_stops = stops;
    ProblemInstance::_students = students;
    ProblemInstance::_availableStops = calculateAvailableStops(stopsCount, studentsCount, stops, students, maxWalkingDistance);
    ProblemInstance::_stopDistances = calculateStopDistances(stopsCount, stops);
}

ProblemInstance::~ProblemInstance()
{
}

std::vector<int> ProblemInstance::getAvailableStops(int studentIndex)
{
    return ProblemInstance::_availableStops[studentIndex];
}

float ProblemInstance::getStopsDistance(int fromStopIndex, int toStopIndex)
{
    return ProblemInstance::_stopDistances[fromStopIndex][toStopIndex];
}