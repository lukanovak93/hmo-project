#pragma once
#include "Antibody.h"
#include "ProblemInstance.h"

class Antigen
{
    public:
        void evaluate(Antibody &, ProblemInstance);
        void evaluate(std::vector<Antibody> &, ProblemInstance);
};