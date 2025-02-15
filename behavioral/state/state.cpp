#include <iostream>
#include <string>

#include "state.hpp"

void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// ======== Mood ========
Mood::Mood(Boss * boss) :
	boss(boss)
{ }

// ======== Boss ========
Boss::Boss(Mood * mood) :
	mood(nullptr)
{
	// makes boss in a default mood
	this->TransitionMood(mood);
}

Boss::~Boss() {
	delete mood;
}

void Boss::helpMe() {
	getMood()->helpMe();
}

void Boss::directMe() {
	getMood()->directMe();
}

void Boss::TransitionMood(Mood * mood) {
	// protects the default constructor to change the class
	if (this->getMood() != nullptr) {
		// deletes the old heap "state"
		delete this->mood;
	}

	setMood(mood);
}

// ======== BadMood ========
void BadMood::helpMe() {
	printToConsole("BadMood - Help Me!");
}

void BadMood::directMe() {
	printToConsole("BadMood - Direct Me!");
}

// ======== OkMood ========
void OkMood::helpMe() {
	printToConsole("OkMood - Help Me!");
}

void OkMood::directMe() {
	printToConsole("OkMood - Direct Me!");
}

// ======== GoodMood ========
void GoodMood::helpMe() {
	printToConsole("GoodMood - Help Me!");
}

void GoodMood::directMe() {
	printToConsole("GoodMood - Direct Me!");
}

// ======== Main ========
int main() {
	Boss * boss = new Boss(new OkMood());
	boss->helpMe();
	boss->directMe();

	boss->TransitionMood(new BadMood());
	boss->helpMe();
	boss->directMe();

	boss->TransitionMood(new GoodMood());
	boss->helpMe();
	boss->directMe();

	return 0;
}