#pragma once
#include <vector>
#include "RandomNumberGenerator.h"
#include "ProblemInstance.h"

class Antibody
{
    public:
        std::vector<std::vector<int> > busRoutes;
        std::vector<std::vector<int> > stops;
        Antibody(ProblemInstance, RandomNumberGenerator);
        Antibody(std::vector<std::vector<int> >, std::vector<std::vector<int> >);
};