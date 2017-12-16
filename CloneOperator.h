#pragma once
#include "Antibody.h"

class CloneOperator
{
    public:
        std::vector<Antibody> clone(std::vector<Antibody>);
        CloneOperator(float);
    private:
        float _beta;
};