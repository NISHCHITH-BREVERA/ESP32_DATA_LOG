#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include "esp_log.h"
#include "MONGODB.h"

static const char *TAG = "MONGODB";

void send_data_to_mongodb(const char* data)
{
    esp_http_client_config_t config = {
        .url = "https://ap-south-1.aws.data.mongodb-api.com/app/brevera-qhwno/endpoint/BREVERA",
		.crt_bundle_attach = esp_crt_bundle_attach,
		    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, data, strlen(data));
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "Data sent to MongoDB successfully");
    } else {
        ESP_LOGE(TAG, "Failed to send data to MongoDB, error code: %d", err);
    }
    esp_http_client_cleanup(client);
}



