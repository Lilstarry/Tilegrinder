#include "location.h"

#pragma once

class Town : public Location
{
public:
    Town();

    int idea() const { return m_idea; }
    void setIdea(const int idea) { m_idea = idea; }

    int population() { return m_population; }
    void setPopulation(const int value) { m_population = value; }

    void conviction(const int enemyIdea);

private:
    int m_idea;

    int m_population;
    int m_growth;

    int m_gold;
    int m_income;
};

