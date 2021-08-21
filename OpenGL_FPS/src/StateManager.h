#pragma once

#include <vector>

#include "StateBase.h"
#include "StateGame.h"

class StateManager {
public:
	static void Init();
	static void CleanUp();

	static StateBase* CurrentState;

	//void ChangeState(StateBase* state);
	//void PushState(StateBase* state);
	//void PopState();
};