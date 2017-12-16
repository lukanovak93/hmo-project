#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(int seed)
   : seed_(seed),
     defGen_(seed_),
     randInt_()
{
}

int RandomNumberGenerator::integer(int upperBound)
{
    return randInt_(defGen_) % upperBound;
}

int RandomNumberGenerator::integer(int lowerBound, int upperBound)
{
    return randInt_(defGen_) % (upperBound - lowerBound) + lowerBound;
}