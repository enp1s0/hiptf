#include <iostream>
#include <hiptf/rsmi.hpp>

int main(){
	HIPTF_CHECK_ERROR(rsmi_init(0));
	int64_t temperature;
	HIPTF_CHECK_ERROR(rsmi_dev_temp_metric_get(0, 0, RSMI_TEMP_CURRENT, &temperature));

	std::printf("temperature = %.1f\n", temperature / 1000.0);
}
