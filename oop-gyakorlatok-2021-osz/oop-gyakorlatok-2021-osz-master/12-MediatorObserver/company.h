#pragma once

#include <string>
#include <iostream>

// 3 osztaly:
// ososztaly: Employee - Ezek mediatorokon keresztul kommunikalnak
// Manager - neve, department (dept. legyen enum class!)
// Coworker - neve, department

enum class Department {
	IT,
	Marketing,
	Design,
	Accounting,
	None
};

class Employee : public Mediatee {
	const std::string name;
	Department dept;
public:
	Employee(const std::string& n, Department d) : name(n), dept(d) {}
	void receiveMessage(Mediatee* sender, const std::string& msg) {
		std::cout << "\tMessage received by " << name << " from sender " << sender->getName();
		std::cout << ":" << std::endl;
		std::cout << "\t\t" << msg << std::endl;
	}
	const std::string& getName() {
		return name;
	}
	void sendMessage(Mediator* mp, const std::string& msg);
};

class Manager : public Employee {
public:
	Manager(const std::string& n, Department d) : Employee(n, d) {}
};

class Coworker : public Employee {
public:
	Coworker(const std::string& n, Department d) : Employee(n, d) {}
};

