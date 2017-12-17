#include "Hypermutation.h"

Hypermutation::Hypermutation(std::vector<IMutation*> mutations, RandomNumberGenerator random, ProblemInstance problem) : 
    _mutations(mutations),
    _random(random),
    _problem(problem)
{
}

void Hypermutation::mutate(Antibody &a)
{
    for (int i = 0; i < _mutations.size(); i++)
    {
        _mutations[i]->mutate(a, _random, _problem);
    }
}

void Hypermutation::mutate(std::vector<Antibody> &population)
{
    for (int i = 0; i < population.size(); i++)
    {
        Hypermutation::mutate(population[i]);
    }
}