#ifndef SHADER_H
#define SHADER_H

#ifdef _WIN32
#define GLFW_INCLUDE_VULKAN
#include "glfw3.h"
#include <vulkan/vulkan.h>
#endif

#ifdef __linux__
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#endif


#endif