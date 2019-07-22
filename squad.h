#include "fraction.h"

#pragma once

class Squad
{
public:
    Squad();

    Fraction::Type fraction() const { return m_fraction; }
    int number() const { return m_number; }
    int warfare() const { return m_warfare; }
    int equipment() const { return m_equipment; }
    int idea() const { return m_idea; }
    int player() const { return m_player; }

    void setNumber(const int value) { m_number = value; }
    void increaseWarfare(const int value = 1) { m_warfare += value; }
    void setEquipment(const int value) { m_equipment = value; }
    void increaseIdea(const int value = 1) { m_idea += value; }

    void addSquad(const Squad squad);

private:
    Fraction::Type m_fraction;
    int m_number;
    int m_warfare;
    int m_equipment;
    int m_idea;
    int m_player;
};

