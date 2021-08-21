#pragma once

#include "player.h"
#include "Setting.h"

Player::Player():Character(),Camera(Setting::FOV,Setting::WIDTH, Setting::HEIGHT){
	CSetPosition({ 0.0f,2.0f,0.0f });
}

void Player::MoveForward()
{
	Character::MoveForward();
	CMoveForward(speed_forward);
}

void Player::MoveBackward()
{
	Character::MoveBackward();
	CMoveForward(-speed_forward);
}

void Player::MoveLeft()
{
	Character::MoveLeft();
	CMoveSideways(-speed_sideways);
}

void Player::MoveRight()
{
	Character::MoveRight();
	CMoveSideways(speed_sideways);
}
