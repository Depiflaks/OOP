//
// Created by smmm on 19.03.2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H
#include <functional>
#include <map>
#include <string>

#include "../actor/Actor.h"

class Scenario
{
public:
	using ActorsMap = std::map<std::string, Actor>;
	using CallbackType = std::function<void(ActorsMap&)>;

	explicit Scenario(CallbackType callback);

	void execute(ActorsMap& actors);

	void rollback(ActorsMap& actors);

private:
	CallbackType m_callback;
	ActorsMap m_backup;
};

#endif // SCENARIO_H
