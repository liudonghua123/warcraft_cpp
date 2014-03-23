/*
 * Command.cpp
 *
 *  Created on: 2014-3-11
 *      Author: liudonghua
 */

#include "Command.h"

template <class T1,class T2>
ostream & operator <<( ostream & o,const pair<T1,T2> & p) {
	o << "(" << p.first  << "," << p.second << ")";
	return o;
}

template<class T>
void printCollection( T first,T last) {
	for( ; first != last; ++ first)
		std::cout <<  * first << " ";
	std::cout << std::endl;
}

template<typename T, typename R>
int indexOf(const T& list, const R& value) {
	int index = 0;
	for (typename T::const_iterator it = list.begin(); it != list.end();
			it++, index++)
		//cout << &value << ", " << it << endl;
		if ((*it) == value)
			return index;
	return -1;
}

//Command::Command() {
//	// may not being used
//}

Command::Command(int totalHealthPoint, WarriorsHelper& warriorsHelper,
		CommandType commandType) :
		warriorsHelper(warriorsHelper), commandType(commandType) {
	this->totalHealthPoint = totalHealthPoint;
	this->currentRemainingHealthPoint = totalHealthPoint;
	this->createWarriorSequence = warriorsHelper.getWarriorSequence(
			commandType);
	this->warriorData = warriorsHelper.getWarriors();
	this->currentWarriorProfession = -1;
	this->createdWarrior = new vector<Warrior>;
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}
bool Command::operator==(const Command &command) const {

	return this->totalHealthPoint == command.totalHealthPoint;
}
Command &Command::operator=(const Command &command) {
	if(this != &command) {
		this->totalHealthPoint == command.totalHealthPoint;
	}
	return *this;

}
bool Command::operator<(const Command &command) const {
	return this->totalHealthPoint == command.totalHealthPoint;
}

bool Command::canCreateWarrior() {
	return currentRemainingHealthPoint >= warriorsHelper.getMinHealthValue();
}

void Command::createWarrior() {
	if (currentWarriorProfession == -1) {
		currentWarriorProfession = (*createWarriorSequence)[0];
	}
	int currentWarriorProfessionIndex = indexOf(*createWarriorSequence,
			currentWarriorProfession);
	vector<WarriorProfession> iteratorWarriorSequence;
	vector<WarriorProfession>::iterator iteratorBegin =
			iteratorWarriorSequence.begin();
	vector<WarriorProfession>::iterator createWarriorSequenceIteratorBegin =
			createWarriorSequence->begin();
	// http://www.cplusplus.com/reference/vector/vector/insert/
	iteratorWarriorSequence.insert(iteratorBegin,
			createWarriorSequenceIteratorBegin + currentWarriorProfessionIndex,
			createWarriorSequence->end());
	if (currentWarriorProfessionIndex > 0) {
		iteratorWarriorSequence.insert(
				iteratorWarriorSequence.end(), createWarriorSequenceIteratorBegin,
				createWarriorSequenceIteratorBegin + currentWarriorProfessionIndex);
	}
	for (WarriorProfession profession : iteratorWarriorSequence) {
		map<WarriorProfession, Warrior*>::const_iterator search = warriorData->find(profession);
		const Warrior& warrior = *(search->second);
		if (warrior.getHealthPoint() <= currentRemainingHealthPoint) {
			currentWarriorProfession = getNextWarriorProfession(currentWarriorProfession);
			createWarrior(warrior);
			break;
		}
	}
}

WarriorProfession Command::getNextWarriorProfession(WarriorProfession currentWarriorProfession) {
	int currentWarriorProfessionIndex = indexOf(*createWarriorSequence,
				currentWarriorProfession);
	return (*createWarriorSequence)[(currentWarriorProfessionIndex + 1) % createWarriorSequence->size()];
}


void Command::createWarrior(Warrior warrior) {
	// copy
	Warrior needCreateWarrior = warrior;
	this->createdWarrior->push_back(needCreateWarrior);
	currentRemainingHealthPoint -= needCreateWarrior.getHealthPoint();
}

void Command::printCreatedWarrior() {
	for (int i = 0; i < createdWarrior->size(); i++) {
		Warrior warrior = (*createdWarrior)[i];
		printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
				i, commandType, warrior.getWarriorProfession(), i,
				warrior.getHealthPoint(), 1, warrior.getWarriorProfession(),
				commandType);
	}
	printf("%03d %s headquarter stops making warriors\n", createdWarrior->size(),
			commandType);
}

int Command::getWarriorIndex(Warrior& providedWarrior) {
	vector<Warrior*> specifyProfessionWarrior;
	for (Warrior& warrior : *createdWarrior) {
		if (warrior.getWarriorProfession()
				== providedWarrior.getWarriorProfession()) {
			specifyProfessionWarrior.push_back(&warrior);
		}
	}
	for(int i = 0; i < specifyProfessionWarrior.size(); ++i) {
		Warrior * sWarrior = specifyProfessionWarrior[i];
		if(sWarrior == &providedWarrior) {
			return i;
		}
	}
	return -1;
}
