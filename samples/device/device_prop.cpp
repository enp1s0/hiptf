#include <iostream>
#include <hiptf/device.hpp>

int main(){
	const auto device_props = hiptf::device::get_properties_vector();

	std::printf("# device names\n");
	for (const auto device_prop : device_props) {
		std::printf("%s\n", device_prop.name);
	}
}
