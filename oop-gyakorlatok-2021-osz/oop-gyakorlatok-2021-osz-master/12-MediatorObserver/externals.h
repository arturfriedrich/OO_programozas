#pragma once

#include <string>

// Auditor (revizor) - nevvel rendelkezik - ez egyfajta observer lesz

class Auditor : public Mediatee {
	const std::string name;
public:
	Auditor(const std::string& n) : name(n) {}
	void sendMessage(Mediator* mp, const std::string& msg);
	void receiveMessage(Mediatee* sender, const std::string& msg) {
		std::cout << "\tMessage received by " << name << " from sender " << sender->getName();
		std::cout << ":" << std::endl;
		std::cout << "\t\t" << msg << std::endl;
	}
	const std::string& getName() {
		return name;
	}
};