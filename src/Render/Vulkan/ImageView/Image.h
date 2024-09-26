#ifndef IMAGE_H
#define IMAGE_H

#ifdef _WIN32
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#endif

#ifdef __linux__
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#endif

#include <cstring>
#include <stdexcept>

class Image {
private:
    VkDevice& device;
    VkPhysicalDevice& physicalDevice;
    VkImage image;
    VkDeviceMemory imageMemory;
    VkFormat format;
    VkExtent2D extent;


    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);
    
    for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
        if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }
    throw std::runtime_error("Failed to find suitable memory type!");
    }

    void createImage(VkExtent2D imageExtent, VkFormat imageFormat) {
        format = imageFormat;
        extent = imageExtent;

        VkImageCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        createInfo.imageType = VK_IMAGE_TYPE_2D;
        createInfo.extent.width = extent.width;
        createInfo.extent.height = extent.height;
        createInfo.extent.depth = 1;
        createInfo.mipLevels = 1;
        createInfo.arrayLayers = 1;
        createInfo.format = format;
        createInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
        createInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        createInfo.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
        createInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

        if (vkCreateImage(device, &createInfo, nullptr, &image) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create image!");
        }

        VkMemoryRequirements memRequirements;
        vkGetImageMemoryRequirements(device, image, &memRequirements);

        VkMemoryAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
        if (vkAllocateMemory(device, &allocInfo, nullptr, &imageMemory) != VK_SUCCESS) {
            throw std::runtime_error("Failed to allocate image memory!");
        }

        vkBindImageMemory(device, image, imageMemory, 0);
    }

    void cleanup() {
        if (image != VK_NULL_HANDLE) {
            vkDestroyImage(device, image, nullptr);
            image = VK_NULL_HANDLE;
        }
        if (imageMemory != VK_NULL_HANDLE) {
            vkFreeMemory(device, imageMemory, nullptr);
            imageMemory = VK_NULL_HANDLE;
        }
    }

public:
    Image(VkDevice& device,VkPhysicalDevice& physicalDevice, VkExtent2D imageExtent, VkFormat imageFormat) 
        : device(device), image(VK_NULL_HANDLE), imageMemory(VK_NULL_HANDLE), physicalDevice(physicalDevice) {
        createImage(imageExtent, imageFormat);
    }

    ~Image() {
        cleanup();
    }

    VkDevice getDevice() const { return device; }
    VkImage get() const { return image; }
    VkDeviceMemory getMemory() const { return imageMemory; }
};


#endif