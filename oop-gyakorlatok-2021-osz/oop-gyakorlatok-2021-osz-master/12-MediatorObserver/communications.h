#pragma once

#include <vector>
#include <string>

class Mediatee {
public:
	virtual const std::string& getName() = 0;
	virtual void receiveMessage(Mediatee* sender, const std::string& msg) = 0;
};

class Mediator {
	std::vector<Mediatee*> mediatees;
public:
	Mediator& addEntity(Mediatee* ep) { mediatees.push_back(ep); return *this; }
	virtual void distributeMessage(Mediatee* sender, std::string msg) {
		for (auto med : mediatees) {
			if (med != sender) {
				med->receiveMessage(sender, msg);
			}
		}
	}
};