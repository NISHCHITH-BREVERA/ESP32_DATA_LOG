#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "MONGODB.h"
#include "esp_https_ota.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "cJSON.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "WIFI.h"
#include "esp_ping.h"
#include "SD_SPI.h"


void NVS_INIT(void);

void app_main(void)
{
	SdCard_init();
	while(1);
	ESP_LOGI(TAG, "OTA example app_main start");
	NVS_INIT();
	wifi_init_sta();

   // while (true) {

    	cJSON *root = cJSON_CreateObject();
    	    cJSON_AddStringToObject(root, "key", "value");
    	    cJSON_AddStringToObject(root,"MODEL","ROUCV IPCB");
    	    char *json_data = cJSON_Print(root);
    	    send_data_to_mongodb(json_data);
    	    cJSON_Delete(root);
    	    free(json_data);

    	send_data_to_mongodb(json_data);
   // }
}








void NVS_INIT(void)
{

	    // Initialize NVS.
	    esp_err_t err = nvs_flash_init();
	    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
	        // 1.OTA app partition table has a smaller NVS partition size than the non-OTA
	        // partition table. This size mismatch may cause NVS initialization to fail.
	        // 2.NVS partition contains data in new format and cannot be recognized by this version of code.
	        // If this happens, we erase NVS partition and initialize NVS again.
	        ESP_ERROR_CHECK(nvs_flash_erase());
	        err = nvs_flash_init();
	    }
	    ESP_ERROR_CHECK( err );

//	    ESP_ERROR_CHECK(esp_netif_init());
//	    ESP_ERROR_CHECK(esp_event_loop_create_default());

	    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
	     * Read "Establishing Wi-Fi or Ethernet Connection" section in
	     * examples/protocols/README.md for more information about this function.
	    */

}

