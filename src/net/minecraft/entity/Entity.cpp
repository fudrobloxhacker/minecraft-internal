#include "Entity.h"
#include "../client/MinecraftClient.h"

jclass playerClass = NULL;
jobject playerObject = NULL;
jfieldID getPlayerField = NULL;
jmethodID getAbilities = NULL;

jclass C_Entity::getClass()
{
    if (playerClass == NULL)
        playerClass = mci->env->FindClass("net/minecraft/class_746");

    return playerClass;
}

jobject C_Entity::getInstance()
{
    if (getPlayerField == NULL)
        getPlayerField = mci->env->GetFieldID(C_Minecraft::getClass(), "field_1724", "()Lnet/minecraft/class_310;");
    if (playerObject == NULL)
        playerObject = mci->env->GetObjectField(C_Minecraft::getInstance(), getPlayerField);

    return playerObject;
}