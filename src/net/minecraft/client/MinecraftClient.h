#pragma once
#include "../../../dependencies/include/JNI/jni.h"
#include "../../../javaclass.h"

class C_Minecraft
{
public:
	static jclass getClass();
	static jobject getInstance();
	static jfieldID getCrosshairTarget();
	static jmethodID getWindowMethod();
	static jobject getWindow();
	static jmethodID getHandleMethod();
	static jlong getHandle();
};