#pragma once
#include "Antibody.h"

class IMutation
{
    public:
        virtual void mutate(Antibody &, RandomNumberGenerator &, ProblemInstance) = 0;
        virtual ~IMutation() { }
};