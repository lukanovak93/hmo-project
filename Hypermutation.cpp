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

void Hypermutation::mutate(std::vector<Antibody> &population)
{
    for (int i = 0; i < population.size(); i++)
    {
        Hypermutation::mutate(population[i]);
    }
}