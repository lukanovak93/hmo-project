#include "Clonalg.h"
#include <algorithm>

Antibody Clonalg::run(int maxIterations)
{
    std::vector<Antibody> population;
    for (int i = 0; i < _populationSize; i++)
    {
        population.push_back(Antibody(_problem, _random));
    }

    for (int iteration = 1; iteration <= maxIterations; iteration++)
    {
        _antigen.evaluate(population, _problem);
        std::vector<Antibody> clones = _cloneOperator.clone(population);
        _hypermutation.mutate(clones);
        _antigen.evaluate(clones, _problem);

        // Generate new antibodies
        std::vector<Antibody> newPopulation;
        for (int i = 0; i < _generateNew; i++)
        {
            newPopulation.push_back(Antibody(_problem, _random));
        }

        // Fill the rest of the population with the best antibodies
        population.insert(population.end(), clones.begin(), clones.end());
        std::sort(population.begin(), population.end());
        for (int i = 0; i < _populationSize - _generateNew; i++)
        {
            newPopulation.push_back(population[i]);
        }

        population = newPopulation;
    }

    return *std::min_element(population.begin(), population.end());

}