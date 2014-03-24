//============================================================================
// Name        : Cpp_Foundation.cpp
// Author      : Liu.D.H
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Warrior.h"
#include "Command.h"
#include "WarriorsHelper.h"

using namespace std;

const char *WarriorProfessionTypes[] = {
    "dragon",
    "ninja",
    "iceman",
    "lion",
    "wolf"
};
const char *CommandTypes[] = { "red","blue" };

void initEnvironment(int totalHealthPoint, Command **redCommand_p, Command **blueCommand_p);
void makeWarriors(Command& redCommand, Command& blueCommand) ;
void printResult(Command& redCommand, Command& blueCommand);


int main() {
	int totalCase = 1, currentCase = 1;
	if (scanf("%d", &totalCase) != 1) {
		totalCase = 1;
	}
	while (currentCase <= totalCase) {
		int totalHealthPoint = 20;
		if (scanf("%d", &totalHealthPoint) != 1) {
			totalHealthPoint = 20;
		}
		Command *redCommand;
		Command *blueCommand;
		initEnvironment(totalHealthPoint, &redCommand, &blueCommand);
		makeWarriors(*redCommand, *blueCommand);
		printResult(*redCommand, *blueCommand);

		++currentCase;
	}
}

void initEnvironment(int totalHealthPoint, Command **redCommand_p,
		Command **blueCommand_p) {
	WarriorsHelper warriorsHelper;
	*redCommand_p = new Command(totalHealthPoint, warriorsHelper, RED);
	*blueCommand_p = new Command(totalHealthPoint, warriorsHelper, BLUE);
}
void makeWarriors(Command& redCommand, Command& blueCommand) {
	bool redCommandCanCreate, blueCommandCanCreate;
	while (true) {
		redCommandCanCreate = redCommand.canCreateWarrior();
		blueCommandCanCreate = blueCommand.canCreateWarrior();
		if (!redCommandCanCreate && !blueCommandCanCreate) {
			break;
		}
		if (redCommandCanCreate) {
			redCommand.createWarrior();
		}
		if (blueCommandCanCreate) {
			blueCommand.createWarrior();
		}
	}

}

void printResult(Command& redCommand, Command& blueCommand) {
	long maxCreatedWarriorsSize =
			redCommand.getCreatedWarrior().size()
					> blueCommand.getCreatedWarrior().size() ?
					redCommand.getCreatedWarrior().size() :
					blueCommand.getCreatedWarrior().size();
	bool printedRedStops = false, printedBlueStops = false;
	for (int i = 0; i < maxCreatedWarriorsSize + 1; i++) {
		if (i < redCommand.getCreatedWarrior().size()) {
			Warrior& warrior = redCommand.getCreatedWarrior()[i];
			printf(
					"%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
					i, CommandTypes[redCommand.getCommandType()],
					WarriorProfessionTypes[warrior.getWarriorProfession()],
					i + 1, warrior.getHealthPoint(),
					redCommand.getWarriorIndex(warrior) + 1,
					WarriorProfessionTypes[warrior.getWarriorProfession()],
					CommandTypes[redCommand.getCommandType()]);
		} else if (!printedRedStops) {
			printf("%03lu %s headquarter stops making warriors\n",
					redCommand.getCreatedWarrior().size(),
					CommandTypes[redCommand.getCommandType()]);
			printedRedStops = true;
		}

		if (i < blueCommand.getCreatedWarrior().size()) {
			Warrior& warrior = blueCommand.getCreatedWarrior()[i];
			printf(
					"%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
					i, CommandTypes[blueCommand.getCommandType()],
					WarriorProfessionTypes[warrior.getWarriorProfession()],
					i + 1, warrior.getHealthPoint(),
					blueCommand.getWarriorIndex(warrior) + 1,
					WarriorProfessionTypes[warrior.getWarriorProfession()],
					CommandTypes[blueCommand.getCommandType()]);
		} else if (!printedBlueStops) {
			printf("%03lu %s headquarter stops making warriors\n",
					blueCommand.getCreatedWarrior().size(),
					CommandTypes[blueCommand.getCommandType()]);
			printedBlueStops = true;
		}
	}

}


