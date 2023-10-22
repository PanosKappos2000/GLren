#include "Memory.h"

CEArenaHolder<Model> CEMemoryArenaAllocator::s_ModelArena;

Entity* EAlloc(const Model& entity)
{
	Model* e = CEMemoryArenaAllocator::GetModelArena().currentAllocAddress;
	if (e == nullptr)
	{
		__debugbreak();
	}
	*e = entity;
	return e;
}

CEMemoryArenaAllocator::CEMemoryArenaAllocator()
{
	if (!s_ModelArena.arena)
	{
		char c[20000];
		s_ModelArena.arena = (Model*)c;
		s_ModelArena.currentAllocAddress = s_ModelArena.arena;
	}
}