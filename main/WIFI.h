/*
 * WIFI.h
 *
 *  Created on: 23-May-2023
 *      Author: nishc
 */

#ifndef MAIN_WIFI_H_
#define MAIN_WIFI_H_

#define EXAMPLE_ESP_WIFI_SSID      "Brevera Technologies"
#define EXAMPLE_ESP_WIFI_PASS      "Production@22"
#define EXAMPLE_ESP_MAXIMUM_RETRY  1

#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

void wifi_init_sta(void);
//unsigned char is_internet_connected();


#endif /* MAIN_WIFI_H_ */
