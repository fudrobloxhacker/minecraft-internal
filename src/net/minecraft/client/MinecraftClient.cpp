#include "MinecraftClient.h"
#include <iostream>

jclass minecraft = NULL;
jobject minecraftObject = NULL;
jmethodID getInstanceMethod = NULL;
jfieldID crosshairTarget = NULL;
jmethodID getWindowMethodI = NULL;
jmethodID getHandleID = NULL;
jlong getHandleLong = NULL;

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

jfieldID C_Minecraft::getCrosshairTarget() {

	if (crosshairTarget == NULL)
		crosshairTarget = mci->env->GetFieldID(getClass(), "field_4350", "()Lnet/minecraft/class_239;");

	return crosshairTarget;
}

jmethodID C_Minecraft::getWindowMethod() {
    if (getWindowMethodI == NULL) {
        getWindowMethodI = mci->env->GetMethodID(getClass(), "method_22683", "()Lnet/minecraft/class_1041;");
        if (getWindowMethodI == NULL) {
            std::cerr << "Failed to get method ID for method_22683" << std::endl;
        }
    }
    return getWindowMethodI;
}

jobject C_Minecraft::getWindow() {
    if (getWindowMethodI == NULL) {
        getWindowMethod();
    }
    return mci->env->CallObjectMethod(getClass(), getWindowMethod());
}

jmethodID C_Minecraft::getHandleMethod() {
    if (getHandleID == NULL) {
        jclass windowClass = mci->env->FindClass("net/minecraft/class_1041"); 
        if (windowClass == NULL) {
            std::cerr << "Failed to find class net/minecraft/class_1041" << std::endl;
            return NULL;
        }
        getHandleID = mci->env->GetMethodID(windowClass, "method_22683", "()J");
        if (getHandleID == NULL) {
            std::cerr << "Failed to get method ID for getHandleMethodName" << std::endl;
        }
    }
    return getHandleID;
}

jlong C_Minecraft::getHandle() {
    jobject window = getWindow();
    if (window == NULL) {
        std::cerr << "Failed to get window object" << std::endl;
        return 0;
    }

    if (getHandleID == NULL) {
        getHandleMethod();
    }

    return mci->env->CallLongMethod(window, getHandleMethod());
}