#pragma once

#define DECLARE_SINGLE(classname) \
private:														\
classname() {}												\
public:															\
static classname* GetInstance()					\
{																	\
	static classname instance;						\
	return &instance;										\
}																

#define	 GET_SINGLE(classname) classname::GetInstance()

#define SAFE_DELETE	(ptr) \
if (ptr)										\
{												\
	delete ptr;							\
	ptr = nullptr;						\
}			
