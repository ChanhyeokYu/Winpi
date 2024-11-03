#include "pch.h"
#include "Game.h"
#include "MainSequence.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Engine()
{
	GET_SINGLE(MainSequence)->Update();

}
