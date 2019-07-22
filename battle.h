#include "location.h"
#include "fraction.h"

#include <QPair>

#pragma once

class Squad;

class Battle
{
public:
    Battle(Squad *first, Squad *second, const Location *location);

private:
    int fractionBonus(const Fraction::Type f, const Location *location, bool townOwner);
    int marauding(const int alive, const int equipAlive, const int dead, const qreal equipDead);
};

