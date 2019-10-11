#include "battle.h"
#include "squad.h"

Battle::Battle(Squad *first, Squad *second, const Location *location)
{
    int f_number = first->number();
    int s_number = second->number();

    int f_bonus = fractionBonus(first->fraction(), location, first->player() == location->player());
    int s_bonus = fractionBonus(second->fraction(), location, first->player() == location->player());

    if (first->idea() > second->idea())
        f_bonus++;
    else if (first->idea() < second->idea())
        s_bonus++;

    int f_power, s_power;
    while (!f_number || !s_number)
    {
        f_power = first->warfare() + first->equipment() + f_bonus;
        s_power = second->warfare() + second->equipment() + s_bonus;

        f_number -= s_power;
        s_number -= f_power;

        first->increaseWarfare();
        second->increaseWarfare();
    }

    if (f_number < 0)
        f_number = 0;
    if (s_number < 0)
        s_number = 0;

    //    //  Resurrect one lucky unit to not draw the battle
    //    if(!f_number && !s_number) {
    //        //  Compare army forces
    //        f_power = first.warfare() + first.equipment() + f_bonus;
    //        s_power = second.warfare() + second.equipment() + s_bonus;
    //        int f_force = f_power * first.number();
    //        int s_force = s_power * second.number();

    //        if(f_force < s_force) s_number = 1;
    //        else f_number = 1;
    //    }

    //  Marodeur
    int dead = first->number() + second->number() - f_number - s_number;

    qreal equipDead = 0;
    equipDead += (first->number() - f_number) * first->equipment();
    equipDead += (second->number() - s_number) * second->equipment();
    equipDead /= dead;

    if (f_number > 0)
        first->setEquipment(marauding(f_number, first->equipment(), dead, equipDead));
    else // if(s_number > 0)
        second->setEquipment(marauding(s_number, second->equipment(), dead, equipDead));

    first->setNumber(f_number);
    second->setNumber(s_number);
}

int Battle::fractionBonus(const Fraction::Type f, const Location *location, bool townOwner)
{
    int bonus = 0;

    if (location->type() == Location::Type::Road)
    {
        bonus += (f == Fraction::Type::Barbarian);
        bonus += (f == Fraction::Type::Romen);
    }
    else if (townOwner && (location->type() == Location::Type::Town || location->type() == Location::Type::Capital))
    {
        bonus += (f == Fraction::Type::Romen);
        bonus += (f == Fraction::Type::Tan);
        bonus += (f == Fraction::Type::Northern);
    }

    return bonus;
}

//  Returns new equip level
int Battle::marauding(const int alive, const int equipAlive, const int dead, const qreal equipDead)
{
    qreal result;
    if (alive > dead)
        result = equipAlive + dead * (equipDead - equipAlive) / alive;
    else if (equipDead > equipAlive)
        result = equipDead;
    else
        result = equipAlive;

    return static_cast<int>(result);
}
