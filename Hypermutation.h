#pragma once
#include "Antibody.h"
#include "IMutation.h"
#include <vector>

class Hypermutation
{
    public:
        Hypermutation(std::vector<IMutation*>);
        void mutate(Antibody &);
        void mutate(std::vector<Antibody> &);
    private:
        std::vector<IMutation*> _mutations;
};