#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

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

class ImageView
{
private:
VkDevice& device;
VkImageView imageView;

    void createImageView(VkImage image, VkFormat format) {
        VkImageViewCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        createInfo.image = image;
        createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        createInfo.format = format;
        createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        createInfo.subresourceRange.baseMipLevel = 0;
        createInfo.subresourceRange.levelCount = 1;
        createInfo.subresourceRange.baseArrayLayer = 0;
        createInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(device, &createInfo, nullptr, &imageView) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create image view!");
        }
    }

    void cleanup() {
        if (imageView != VK_NULL_HANDLE) {
            vkDestroyImageView(device, imageView, nullptr);
            imageView = VK_NULL_HANDLE;
        }
    }
public:
    ImageView(VkDevice device, VkImage image, VkFormat format) : device(device) {
        createImageView(image, format);
    }
    ~ImageView() {
        cleanup();
    }
    VkDevice getDevice() const {return device;}
    VkImageView get() const { return imageView; }
};


#endif