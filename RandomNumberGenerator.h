#include <random>
#include <ctime>
#pragma once

class RandomNumberGenerator
{
   public:
      RandomNumberGenerator(int seed = std::time(0));
      
      int integer(int);
      int integer(int, int);
   private:
      int seed_;
      std::default_random_engine defGen_;
      std::uniform_int_distribution<int> randInt_;
};