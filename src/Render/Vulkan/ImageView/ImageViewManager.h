#ifndef IMAGEVIEW_MANAGER_H
#define IMAGEVIEW_MANAGER_H
#include <vector>

#ifdef _WIN32
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#endif

#ifdef __linux__
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#endif
#include "ImageView.h"
#include "Image.h"
class ImageViewManager
{
private:
VkDevice& device;
std::vector<ImageView> swapChainImageViews;
std::vector<Image> swapChainImages;
public:
    ImageViewManager(VkDevice& device) : device(device) {}
    ~ImageViewManager(){
        cleanUp();
    }

    void cleanUp() {
        for (auto imageView : swapChainImageViews) {
            vkDestroyImageView(imageView.getDevice(), imageView.get(), nullptr);
        }
        for (auto image : swapChainImages) {
            vkDestroyImage(image.getDevice(), image.get(), nullptr);
        }
    }
    void addImage(VkImage image, VkFormat format) {
        swapChainImages.emplace_back(device, image, format);
        
        swapChainImageViews.emplace_back(device, image, format);
    }

    const std::vector<ImageView>& getImageViews() const {
        return swapChainImageViews;
    }

    const std::vector<Image>& getImages() const {
        return swapChainImages;
    }
    
};


#endif