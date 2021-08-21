
#include "StateManager.h"

StateBase* StateManager::CurrentState = nullptr;

void StateManager::Init()
{
	CurrentState = new StateGame();
	CurrentState->Init();
}

void StateManager::CleanUp() {
	CurrentState->CleanUp();
}

//void StateManager::ChangeState(GameState* state)
//{
//	//remove previous game state
//	if (!states.empty()) {
//		states.back()->CleanUp();
//		states.pop_back();
//	}
//
//	states.push_back(state);
//	states.back()->Init();
//}
//
//void StateManager::PushState(GameState* state)
//{
//	//pause the previous game state
//	if (!states.empty()) {
//		states.back()->Pause();
//	}
//	states.push_back(state);
//	states.back()->Init();
//}
//
//void StateManager::PopState()
//{
//	if (!states.empty()) {
//		states.back()->CleanUp();
//		states.pop_back();
//	}
//
//	// resume previous state
//	if (!states.empty()) {
//		states.back()->Resume();
//	}
//}
