#pragma once
#include "Actor.h"

class Tilemap;

class TilemapActor : public actor
{
	using Super = actor;
public:
	TilemapActor();
	virtual ~TilemapActor();

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;
	
	void TilePicking();

	void SetTilemap(Tilemap* tilemap) { _tilemap = tilemap; }
	Tilemap* GetTilemap() { return _tilemap; }

	void SetShowDebug(bool showDebug) { _showDebug = showDebug; }


protected:
	Tilemap* _tilemap = nullptr;
	bool _showDebug = false;

};

