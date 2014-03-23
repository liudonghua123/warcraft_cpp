/*
 * WarriorsHelper.cpp
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#include "WarriorsHelper.h"

WarriorsHelper::WarriorsHelper() {
	// TODO Auto-generated constructor stub
	warriors = new map<WarriorProfession, Warrior*>;
	initWarriorData();
}

WarriorsHelper::~WarriorsHelper() {
	// TODO Auto-generated destructor stub
}

map<WarriorProfession, Warrior*>* WarriorsHelper::initWarriorData() {
	// dragon 、ninja、iceman、lion、wolf
	int healthPointArray[5] = { 0 };
	if (scanf("%d %d %d %d %d", &healthPointArray[0], &healthPointArray[1],
			&healthPointArray[2], &healthPointArray[3], &healthPointArray[4])
			!= 5) {
		healthPointArray[0] = 3;
		healthPointArray[1] = 4;
		healthPointArray[2] = 5;
		healthPointArray[3] = 6;
		healthPointArray[4] = 7;
	}
	(*warriors)[DRAGON] = new Warrior(healthPointArray[0], DRAGON);
	(*warriors)[NINJA] = new Warrior(healthPointArray[1], NINJA);
	(*warriors)[ICEMAN] = new Warrior(healthPointArray[2], ICEMAN);
	(*warriors)[LION] = new Warrior(healthPointArray[3], LION);
	(*warriors)[WOLF] = new Warrior(healthPointArray[4], WOLF);
	return warriors;
}

vector<WarriorProfession>* WarriorsHelper::getWarriorSequence(CommandType type) {
	vector<WarriorProfession>* warriorSequence = new vector<WarriorProfession>;
	switch (type) {
	// 红方司令部按照iceman、lion、wolf、ninja、dragon的顺序
	case RED:
		warriorSequence->push_back(ICEMAN);
		warriorSequence->push_back(LION);
		warriorSequence->push_back(WOLF);
		warriorSequence->push_back(NINJA);
		warriorSequence->push_back(DRAGON);
		break;
		// 蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序
	case BLUE:
		warriorSequence->push_back(LION);
		warriorSequence->push_back(DRAGON);
		warriorSequence->push_back(NINJA);
		warriorSequence->push_back(ICEMAN);
		warriorSequence->push_back(WOLF);
		break;
	}
	return warriorSequence;
}

int WarriorsHelper::getMaxHealthValue() {
	WarriorProfession maxHealthWarriorProfession =
			getMaxHealthWarriorProfession();
	auto it = warriors->find(maxHealthWarriorProfession);
	return it->second->getHealthPoint();
}

WarriorProfession WarriorsHelper::getMaxHealthWarriorProfession() {
	map<WarriorProfession, Warrior*>::iterator ii = warriors->begin();
	int maxHealth = -1;
	WarriorProfession maxHealthWarriorProfession = DRAGON;
	while (ii != warriors->end()) {
		WarriorProfession currentWarriorProfession = (*ii).first;
		Warrior currentWarrior = *((*ii).second);
		if (currentWarrior.getHealthPoint() > maxHealth) {
			maxHealth = currentWarrior.getHealthPoint();
			maxHealthWarriorProfession = currentWarriorProfession;
		}
		++ii;
	}
	return maxHealthWarriorProfession;
}

int WarriorsHelper::getMinHealthValue() {
	WarriorProfession minHealthWarriorProfession =
			getMinHealthWarriorProfession();
	auto it = warriors->find(minHealthWarriorProfession);
	return it->second->getHealthPoint();
}

WarriorProfession WarriorsHelper::getMinHealthWarriorProfession() {
	map<WarriorProfession, Warrior*>::iterator ii = warriors->begin();
	int minHealth = 10000;
	WarriorProfession minHealthWarriorProfession = DRAGON;
	while (ii != warriors->end()) {
		WarriorProfession currentWarriorProfession = (*ii).first;
		Warrior currentWarrior = *((*ii).second);
		if (currentWarrior.getHealthPoint() < minHealth) {
			minHealth = currentWarrior.getHealthPoint();
			minHealthWarriorProfession = currentWarriorProfession;
		}
		++ii;
	}
	return minHealthWarriorProfession;
}

