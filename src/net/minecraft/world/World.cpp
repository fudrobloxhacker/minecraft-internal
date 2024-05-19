#include "World.h"
#include "../client/MinecraftClient.h"

jclass worldClass = NULL;

jfieldID getWorldField = NULL;
jobject worldObject = NULL;

jclass C_World::getClass()
{
	if (worldClass == NULL)
		worldClass = mci->env->FindClass("net/minecraft/class_638");

	return worldClass;
}

jobject C_World::getInstance()
{
	if (getWorldField == NULL)
		getWorldField = mci->env->GetFieldID(C_World::getClass(), "field_1687", "()Lnet/minecraft/class_638;");
	if (worldObject == NULL)
		worldObject = mci->env->GetObjectField(C_Minecraft::getInstance(), getWorldField);

	return worldObject;
}