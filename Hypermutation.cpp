#include "Hypermutation.h"

Hypermutation::Hypermutation(std::vector<IMutation*> mutations) : _mutations(mutations)
{
}

void Hypermutation::mutate(Antibody &a)
{
    for (int i = 0; i < _mutations.size(); i++)
    {
        _mutations[i]->mutate(a);
    }
}