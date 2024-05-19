#include "Cheat.h"
#include "../net/minecraft/client/MinecraftClient.h"
#include "../net/minecraft/world/World.h"
#include "../net/minecraft/entity/Entity.h"
#include <chrono>
#include <thread>

void runModules() 
{
	while (true)
	{
		if (!C_Minecraft::getInstance()) continue;
		if (!C_World::getInstance());
		if (!C_Entity::getInstance()) continue;

		AutoSprint::runModule();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}