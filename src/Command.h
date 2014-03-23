/*
 * Command.h
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#ifndef COMMAND_H_
#define COMMAND_H_

enum CommandType {
	RED, BLUE
};


#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "Warrior.h"
#include "WarriorsHelper.h"

using namespace std;

class WarriorsHelper;

class Command {
public:
	//Command();
	Command(int totalHealthPoint, WarriorsHelper& warriorsHelper,
				CommandType commandType);
	virtual ~Command();
	bool operator==(const Command &command) const;
	Command &operator=(const Command &command);
	bool operator<(const Command &command) const;

	bool canCreateWarrior();
	void createWarrior();
	void createWarrior(Warrior warrior);
	void printCreatedWarrior();
	int getWarriorIndex(Warrior& providedWarrior);
	WarriorProfession getNextWarriorProfession(WarriorProfession currentWarriorProfession);

	CommandType getCommandType() const {
		return commandType;
	}

	vector<Warrior>& getCreatedWarrior() {
		return *createdWarrior;
	}

	vector<WarriorProfession>* getCreateWarriorSequence() const {
		return createWarriorSequence;
	}

	int getCurrentRemainingHealthPoint() const {
		return currentRemainingHealthPoint;
	}

	WarriorProfession getCurrentWarriorProfession() const {
		return currentWarriorProfession;
	}

	int getTotalHealthPoint() const {
		return totalHealthPoint;
	}

	WarriorsHelper& getWarriorsHelper() const {
		return warriorsHelper;
	}

private:
	int totalHealthPoint;
	int currentRemainingHealthPoint;
	WarriorsHelper& warriorsHelper;
	CommandType commandType;
	vector<WarriorProfession>* createWarriorSequence;
	// http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
	map<WarriorProfession, Warrior *>* warriorData;

	vector<Warrior> *createdWarrior;
	WarriorProfession currentWarriorProfession;

};

#endif /* COMMAND_H_ */
