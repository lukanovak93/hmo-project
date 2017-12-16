#include "Antibody.h"
#include "ProblemInstance.h"
#include "CloneOperator.h"
#include "Hypermutation.h"
#include "Antigen.h"

class Clonalg
{
    public:
        Clonalg(ProblemInstance, Antigen, CloneOperator, Hypermutation, int, int, RandomNumberGenerator);
        Antibody run(int);
    private:
        ProblemInstance _problem;
        Antigen _antigen;
        CloneOperator _cloneOperator;
        Hypermutation _hypermutation;
        int _populationSize;
        int _generateNew;
        RandomNumberGenerator _random;
};