#pragma once
#include "../../dependencies/include/JNI/jni.h"
#include <memory>

class cheat
{
public:
	JavaVM* jvm;
	JNIEnv* env;
};

inline auto mci = std::make_unique<cheat>();