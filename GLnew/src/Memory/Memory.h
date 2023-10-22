#pragma once

#include "Entities/Model.h"

Entity* EAlloc(const Model& entity);

template<typename T>
struct CEArenaHolder
{
	T* arena;
	T* currentAllocAddress;
};

class CEMemoryArenaAllocator
{
private:
	static CEArenaHolder<Model> s_ModelArena;
public:
	CEMemoryArenaAllocator();

	inline static CEArenaHolder<Model>& GetModelArena() { return s_ModelArena; }
};