#include "pch.h"
#include "Player.h"

Player::Player(PlayerClass _playerclass) : Object(ObjectType::Player)
{
}


Player::~Player()
{
}

void Player::Update()
{
}

void Player::Init()
{
	Settingskill(make_unique<MeleeSkill>(5));
}


void Player::Settingskill(unique_ptr<ISkill> skill)
{
	_skill = move(skill);
}




