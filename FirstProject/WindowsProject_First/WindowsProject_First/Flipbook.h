#pragma once
#include "ResourceBase.h"

class Texture;

struct FlipbookInfo
{
	Texture* texture = nullptr;
	wstring name;
	VectorInt size = {};
	int32 start = 0;
	int32 end = 0;
	int32 line= 0;
	float duration = 1.f;
	bool loop = true;

};

class Flipbook : public ResourceBase
{
public:
	Flipbook();
	virtual ~Flipbook();

	void SetInfo(FlipbookInfo info) { _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }

public:
	FlipbookInfo _info;

};

