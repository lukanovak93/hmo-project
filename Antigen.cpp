#include "Antigen.h"

void Antigen::evaluate(Antibody &a, ProblemInstance problem)
{
    float totalCost = 0;
    int school = 0;
    for (int bus = 0; bus < a.busRoutes.size(); bus++)
    {
        std::vector<int> route = a.busRoutes[bus];
        int currentStop = route[0];
        totalCost += problem.getStopsDistance(school, currentStop);
        int lastStop;
        for (int i = 1; i < route.size(); i++)
        {
            lastStop = currentStop;
            currentStop = route[i];
            totalCost += problem.getStopsDistance(lastStop, currentStop);
        }
        totalCost += problem.getStopsDistance(currentStop, school);
    }
    a.cost = totalCost;
}