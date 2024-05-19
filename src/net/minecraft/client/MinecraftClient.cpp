#include "MinecraftClient.h"


jclass minecraft = NULL;
jobject minecraftObject = NULL;
jmethodID getInstanceMethod = NULL;

jclass C_Minecraft::getClass() {
	if (minecraft == NULL)
		minecraft = mci->env->FindClass("net/minecraft/class_310");

	return minecraft;
}

jobject C_Minecraft::getInstance() {

	if (getInstanceMethod == NULL)
		getInstanceMethod = mci->env->GetStaticMethodID(getClass(), "method_1551", "()Lnet/minecraft/class_310;");

	if (minecraftObject == NULL)
		minecraftObject = mci->env->CallStaticObjectMethod(getClass(), getInstanceMethod);

	return minecraftObject;
}