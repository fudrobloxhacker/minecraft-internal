#pragma once
#include "../../../dependencies/include/JNI/jni.h"
#include "../../../javaclass.h"

class C_World
{
public:
	static jclass getClass();
	static jobject getInstance();
};