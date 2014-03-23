/*
 * Warrior.cpp
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#include "Warrior.h"

Warrior::Warrior() :
		number(0), healthPoint(0), attackPoint(0), warriorProfession(DRAGON) {
}
Warrior::Warrior(int healthPoint, WarriorProfession warriorProfession) :
		number(0), healthPoint(healthPoint), attackPoint(0), warriorProfession(
				warriorProfession) {
}
Warrior::Warrior(int number, int healthPoint, int attackPoint,
		WarriorProfession warriorProfession) :
		number(number), healthPoint(healthPoint), attackPoint(attackPoint), warriorProfession(
				warriorProfession) {

}

Warrior::~Warrior() {
	// TODO Auto-generated destructor stub
}

bool Warrior::operator==(const Warrior &warrior) const {
	return this->attackPoint == warrior.attackPoint
			&& this->healthPoint == warrior.healthPoint
			&& this->number == warrior.number;
}

Warrior &Warrior::operator=(const Warrior &warrior) {
	// Check for self-assignment!
	if (this != &warrior) {
		this->attackPoint == warrior.attackPoint;
		this->healthPoint == warrior.healthPoint;
		this->number == warrior.number;
	}
	return *this;
}

bool Warrior::operator<(const Warrior &warrior) const {
	if (this->attackPoint == warrior.attackPoint
			&& this->healthPoint == warrior.healthPoint
			&& this->number < warrior.number)
		return true;
	if (this->attackPoint == warrior.attackPoint
			&& this->healthPoint < warrior.healthPoint)
		return true;
	if (this->attackPoint < warrior.attackPoint)
		return true;
	return false;
}

std::ostream & operator << (std::ostream & os, const Warrior & w) {
	 os << "attackPoint: " << w.attackPoint << ", warriorProfession" << w.warriorProfession;
 }
