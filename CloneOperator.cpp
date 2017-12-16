#include "CloneOperator.h"
#include "Antibody.h"
#include <cmath>

CloneOperator::CloneOperator(float beta) : _beta(beta)
{
}

std::vector<Antibody> CloneOperator::clone(std::vector<Antibody> population)
{
    std::sort(population.begin(), population.end());
    int populationSize = population.size();
    std::vector<Antibody> clones;

    for (int i = 0; i < populationSize; i++)
    {
        int numberOfClones = round(_beta * populationSize / (i + 1));
        for (int j = 0; j < numberOfClones; j++)
        {
            clones.push_back(Antibody(population[i]));
        }
    }
    return clones;
}