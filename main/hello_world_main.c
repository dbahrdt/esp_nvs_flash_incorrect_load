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
    printf("Hello world!\n");
    nvs_flash_init();
    nvs_handle_t handle;
    nvs_open("test", NVS_READWRITE, &handle);
    nvs_erase_all(handle);
    for(;true;) {
        const uint8_t u8v = 7;
        const int8_t i8v = -1;
        uint8_t loadv;
        char const * str = "test";
        esp_err_t err = ESP_FAIL;
//         nvs_set_u8(handle, "no_commit", u8v);
        nvs_commit(handle);
//         nvs_set_str(handle, "no_commit", str);
        nvs_set_i8(handle, "no_commit", i8v);
//         nvs_commit(handle);
        err = nvs_get_u8(handle, "no_commit", &loadv);
        printf("Loading u8 without commit: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        nvs_commit(handle);
        /*
        nvs_set_u8(handle, "commit_i8", u8v);
//         nvs_set_str(handle, "commit_i8", str);
        nvs_set_i8(handle, "commit_i8", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "commit_i8", &loadv);
        printf("Loading u8 with commit after set_i8: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        nvs_commit(handle);
        
        nvs_set_u8(handle, "commit_str", u8v);
//         nvs_set_str(handle, "commit_str", str);
        nvs_commit(handle);
        nvs_set_i8(handle, "commit_str", i8v);
        err = nvs_get_u8(handle, "commit_str", &loadv);
        printf("Loading u8 with commit after set_str: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        nvs_commit(handle);
        
        nvs_set_u8(handle, "commit_both", u8v);
//         nvs_set_str(handle, "commit_both", str);
        nvs_commit(handle);
        nvs_set_i8(handle, "commit_both", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "commit_both", &loadv);
        printf("Loading u8 with commit after set_str and set_i8: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        
        nvs_set_u8(handle, "commit_all", u8v);
        nvs_commit(handle);
//         nvs_set_str(handle, "commit_all", str);
        nvs_commit(handle);
        nvs_set_i8(handle, "commit_all", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "commit_all", &loadv);
        printf("Loading u8 with commit after set_u8, set_str, set_i8: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        
        nvs_set_i8(handle, "wrong load", i8v);
        nvs_commit(handle);
        err = nvs_get_u8(handle, "commit_all", &loadv);
        printf("Loading u8 without prior set_u8: %s value=%d\n", esp_err_to_name(err), (int)loadv);
        */
        nvs_commit(handle);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    while(true) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
