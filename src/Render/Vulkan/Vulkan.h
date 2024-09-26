#ifndef VULKAN_H
#define VULKAN_H
#include  "vulkan/vulkan.h"
#include "RenderAPI.h"

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
#include <cstring>
#include <optional>
#include <set>
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};
class Vulkan : public RenderAPI {
public:
    Vulkan();
    ~Vulkan();
    void init() override;
    void createWindow(const std::string& name, const int& width, const int& height) override;
    void destroyWindow();
    void mainLoop(std::function<void()> callback) override;
    void setScreenFrames(bool frames) override;
    void setWindowsIcon(std::string path);
    void setCallBackMouseMove(std::function<void(double, double)>) override;
    void setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) override; 
    void setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) override;
    void setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) override;
    void setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackCharacter(std::function<void(const std::string ch)> ch) override;
    void setBackgroundColor(Color color) override;
    void setMaxFPS(int max) override;
    void setVSync(bool action) override;
    void enableLimitFPS(bool action) override;
    int getWidth() override;
    int getHeight() override;
    double getFPS() override;
    int getMaxFPS() override;
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    std::vector<const char*> getRequiredExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    bool checkValidationLayerSupport();
    void createInstance(std::string name);
    void pickPhysicalDevice();
    void setupDebugMessenger();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
        return VK_FALSE;
    }
    void createLogicalDevice();
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
private:
GLFWwindow* window;
VkInstance instance;
VkDebugUtilsMessengerEXT debugMessenger;
VkSurfaceKHR surface;
VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
VkDevice device;

VkQueue graphicsQueue;
VkQueue presentQueue;
const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};
#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

};


#endif