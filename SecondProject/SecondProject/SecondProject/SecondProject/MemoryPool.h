#pragma once

struct MyStruct
{
	int x;
	double y;
};

class MemoryPool
{
public:

	MemoryPool(size_t blockSize, size_t poolSize) :
		_blockSize(blockSize), _poolSize(poolSize)
	{
		_pool = new char[_blockSize * _poolSize];
		for (size_t i = 0; i < _poolSize; i++)
		{
			_freeBlocks.push_back(_pool + i * _blockSize);
		}
	}
	~MemoryPool()
	{
		delete[] _pool;
	}

	void* Allocate()
	{
		if (_freeBlocks.empty())
		{
			throw ::bad_alloc();
		}
		void* block = _freeBlocks.back();
		_freeBlocks.pop_back();
		return block;
	}

	void Dellocate(void* block)
	{
		_freeBlocks.push_back(static_cast<char*>(block));
	}



private:
	size_t _blockSize;
	size_t _poolSize;
	char* _pool;
	vector<char*> _freeBlocks;

};
