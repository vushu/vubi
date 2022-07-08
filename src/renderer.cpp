#include <vulkan/vulkan_raii.hpp>

namespace vubi {


namespace {

vk::raii::Context context;

vk::ApplicationInfo application_info("VULAN APP", 1, "VULKAN ENGINE", 1,
                                     VK_API_VERSION_1_1);
vk::InstanceCreateInfo instance_create_info({}, &application_info);

vk::raii::Instance instance(context, instance_create_info);


}  // namespace

vk::raii::PhysicalDevice& select_physical_device(
    const vk::raii::Instance& instance) {
    vk::raii::PhysicalDevices physical_devices(instance);
    return physical_devices.front();
}

}  // namespace vubi
