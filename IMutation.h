#pragma once
#include "Antibody.h"

class IMutation
{
    public:
        virtual void mutate(Antibody &) = 0;
        virtual ~IMutation() { }
};