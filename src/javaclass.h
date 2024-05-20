#pragma once
#include "dependencies/include/JNI/jni.h"
#include <memory>

class cheat
{
public:
    JavaVM* jvm{ nullptr };
    jint result = JNI_GetCreatedJavaVMs(&jvm, 1, nullptr);

    JNIEnv* env{ nullptr }; // JNI interface pointer
};

inline auto mci = std::make_unique<cheat>();