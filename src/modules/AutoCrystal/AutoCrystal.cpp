#include "AutoCrystal.h"
#include <Windows.h>
#include <iostream>
#include "../../net/minecraft/entity/Entity.h"
#include "../../net/minecraft/world/World.h"
#include "../../net/minecraft/client/MinecraftClient.h"
#include <thread>

void AutoCrystal::runModule() {

    jclass mouse_class{ mci->env->FindClass("net/minecraft/class_3675") };

    if (mouse_class == 0)
    {
        printf("Failed to get Mouse class\n");
        MessageBoxA(0, "ERROR", "Check console", MB_ICONERROR);
    }

    jmethodID is_button_down_id{ mci->env->GetStaticMethodID(mouse_class, "method_15987", "(JI)Z") };

    jlong windowHandle = C_Minecraft::getHandle();
    jint button = 1;

    jboolean isButtonDown = mci->env->CallStaticBooleanMethod(mouse_class, is_button_down_id, windowHandle, button);
    if (isButtonDown) {
        std::cout << "Mouse clicked!" << std::endl;
    }
}
