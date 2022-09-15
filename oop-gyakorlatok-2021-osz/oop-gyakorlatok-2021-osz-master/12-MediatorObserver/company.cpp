
#include "communications.h"
#include "company.h"
#include "externals.h"

void Employee::sendMessage(Mediator* mp, const std::string& msg) {
	mp->distributeMessage(this, msg);
}

void Auditor::sendMessage(Mediator* mp, const std::string& msg) {
	mp->distributeMessage(this, msg);
}