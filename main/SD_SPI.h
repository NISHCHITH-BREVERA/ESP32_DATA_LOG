/*
 * SD_SPI.h
 *
 *  Created on: 24-May-2023
 *      Author: nishc
 */

#ifndef MAIN_SD_SPI_H_
#define MAIN_SD_SPI_H_


static const char *TAG = "ESP";

#define MOUNT_POINT "/sdcard"

// Pin assignments can be set in menuconfig, see "SD SPI Example Configuration" menu.
// You can also change the pin assignments here by changing the following 4 lines.
#define PIN_NUM_MISO  19
#define PIN_NUM_MOSI  23
#define PIN_NUM_CLK   18
#define PIN_NUM_CS    5

void SdCard_init(void);


#endif /* MAIN_SD_SPI_H_ */
