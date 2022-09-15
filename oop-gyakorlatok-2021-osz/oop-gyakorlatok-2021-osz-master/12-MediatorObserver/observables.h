#pragma once


class ObservableMediator : public Mediator {
	std::vector<Auditor*> observers;
public:
	void registerAuditor(Auditor* ap) {
		observers.push_back(ap);
	}
	void distributeMessage(Mediatee* sender, std::string msg) override {
		Mediator::distributeMessage(sender, msg);

		// es meg raadasul a regisztralt observerek megkapjak az infot...
		for (auto obs : observers) {
			obs->receiveMessage(sender, msg);
		}
	}
};