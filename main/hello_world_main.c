/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <nvs.h>
#include <nvs_flash.h>

void app_main(void)
{
    nvs_flash_init();
    nvs_handle_t handle;
    nvs_open("test", NVS_READWRITE, &handle);
    nvs_erase_all(handle);
    for(;true;) {
        const uint8_t u8v = 7;
        const int8_t i8v = -1;
        uint8_t loadv = 10;
        esp_err_t err = ESP_FAIL;
        nvs_set_i8(handle, "notrigger", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "notrigger", &loadv);
        printf("err=%s loadv=%d\n", esp_err_to_name(err), (int)loadv);
        nvs_commit(handle);
        
        nvs_set_u8(handle, "trigger", u8v);
        nvs_commit(handle);
        nvs_set_i8(handle, "trigger", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "trigger", &loadv);
        printf("err=%s loadv=%d\n", esp_err_to_name(err), (int)loadv);
        nvs_commit(handle);

        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
