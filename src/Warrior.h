/*
 * Warrior.h
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_
#include <iostream>

// stl vector or map can not store enum as key
typedef int WarriorProfession;

#define DRAGON 0
#define NINJA 1
#define ICEMAN 2
#define LION 3
#define WOLF 4

class Warrior {
public:
	Warrior();
	Warrior(int healthPoint, WarriorProfession warriorProfession);
	Warrior(int number, int healthPoint, int attackPoint, WarriorProfession warriorProfession);
	virtual ~Warrior();
	bool operator==(const Warrior &warrior) const;
	Warrior &operator=(const Warrior &warrior);
	bool operator<(const Warrior &warrior) const;
	friend std::ostream & operator << (std::ostream & os, const Warrior & w);

	int getAttackPoint() const {
		return attackPoint;
	}

	int getHealthPoint() const {
		return healthPoint;
	}

	int getNumber() const {
		return number;
	}

	WarriorProfession getWarriorProfession() const {
		return warriorProfession;
	}

private:
	int number;
	int healthPoint;
	int attackPoint;
	WarriorProfession warriorProfession;
};

#endif /* WARRIOR_H_ */
