#pragma once

#include <vector>

#include "State/BaseState.h"

/*
	Manager Class where it manages the process of the Current State (ie. event, render)
	Also responsible for transition between states and clean up and init inbetween.
*/
class StateManager {
public:
	static void Init();
	static void CleanUp();

	static BaseState* CurrentState;

	//void ChangeState(StateBase* state);
	//void PushState(StateBase* state);
	//void PopState();
};