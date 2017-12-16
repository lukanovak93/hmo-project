#include "Antibody.h"
#include "RandomNumberGenerator.h"
#include "ProblemInstance.h"
#include <vector>
#include <iostream>

Antibody::Antibody(std::vector<std::vector<int> > busRoutes, std::vector<std::vector<int> > stops)
{
    Antibody::busRoutes = busRoutes;
    Antibody::stops = stops;
}

Antibody::Antibody(ProblemInstance problem, RandomNumberGenerator &random)
{
    // Initialize stops
    for (int i = 0; i < problem.getStopsCount(); i++)
    {
        stops.push_back(std::vector<int>());
    }

    // Assign students to the stops
    for(int i = 0; i < problem.getStudentsCount(); i++)
    {
        std::vector<int> availableStops = problem.getAvailableStops(i);
        while (!availableStops.empty())
        {
            int n = availableStops.size();
            if (n == 0)
            {
                std::cout << "Cannot assign student to a stop" << std::endl;
                exit(1);
            }
            int j = random.integer(n);
            int stopIndex = availableStops[j];
            if (stops[j].size() < problem.getBusCapacity())
            {
                stops[stopIndex].push_back(i);
                break;
            }
            else
            {
                availableStops.erase(availableStops.begin() + j);
            }
        }
    }

    // Shuffle stops
    std::vector<int> stopsShuffled;
    int n = problem.getStopsCount();
    for (int i = 0; i < n; i++)
    {
        stopsShuffled.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int first = random.integer(n);
        int second = random.integer(n);
        std::swap(stopsShuffled[first], stopsShuffled[second]);
    }

    // Assign stops to the buses
    int capacity = problem.getBusCapacity();
    int passengers = 0;
    std::vector<int> route;
    for (int i = 0; i < stops.size(); i++)
    {
        if (passengers + stops[i].size() <= capacity)
        {
            passengers += stops[i].size();
            route.push_back(i);
        }
        else
        {
            busRoutes.push_back(route);
            route = std::vector<int>();
            route.push_back(i);
            passengers = stops[i].size();
        }
    }
    busRoutes.push_back(route);
}