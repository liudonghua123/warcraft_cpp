/*
 * WarriorsHelper.h
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#ifndef WARRIORSHELPER_H_
#define WARRIORSHELPER_H_

#include <map>
#include <vector>
#include "Command.h"
#include "Warrior.h"

using namespace std;

// ISO C++ forbids forward references to 'enum' types
// enum CommandType;

class WarriorsHelper {
public:
	WarriorsHelper();
	virtual ~WarriorsHelper();
public:
	map<WarriorProfession, Warrior*>* initWarriorData();
	vector<WarriorProfession>* getWarriorSequence(CommandType type);
	int getMaxHealthValue();
	WarriorProfession getMaxHealthWarriorProfession();
	int getMinHealthValue();
	WarriorProfession getMinHealthWarriorProfession();

	map<WarriorProfession, Warrior*>* getWarriors() const {
		return warriors;
	}

private:
	map<WarriorProfession, Warrior *>* warriors;
};

#endif /* WARRIORSHELPER_H_ */
