#pragma once
#include "../../../dependencies/include/JNI/jni.h"
#include "../../../javaclass.h"

class C_Entity
{
public:
	static jclass getClass();
	static jobject getInstance();
	static jmethodID getAbilities();
};