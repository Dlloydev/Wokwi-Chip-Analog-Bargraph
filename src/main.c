/* Analog Bargraph Chip by Dlloydev*/

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_A0;
  pin_t pin_D0;
  pin_t pin_D1;
  pin_t pin_D2;
  pin_t pin_D3;
  pin_t pin_D4;
  pin_t pin_D5;
  pin_t pin_D6;
  pin_t pin_D7;
  pin_t pin_D8;
  pin_t pin_D9;
  uint32_t mode_attr;
  uint32_t mode;
  uint32_t adcValue;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_A0 = pin_init("A0", ANALOG);
  chip->pin_D0 = pin_init("D0", OUTPUT);
  chip->pin_D1 = pin_init("D1", OUTPUT);
  chip->pin_D2 = pin_init("D2", OUTPUT);
  chip->pin_D3 = pin_init("D3", OUTPUT);
  chip->pin_D4 = pin_init("D4", OUTPUT);
  chip->pin_D5 = pin_init("D5", OUTPUT);
  chip->pin_D6 = pin_init("D6", OUTPUT);
  chip->pin_D7 = pin_init("D7", OUTPUT);
  chip->pin_D8 = pin_init("D8", OUTPUT);
  chip->pin_D9 = pin_init("D9", OUTPUT);
  chip->mode_attr = attr_init("mode", 0);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 5000, true);
}

static void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  chip->mode = attr_read(chip->mode_attr);
  chip->adcValue = (uint32_t)(pin_adc_read(chip->pin_A0) * 1024.0 * 0.2);
  if(chip->mode == 0) {
pin_write(chip->pin_D9, (chip->adcValue > 1022) ? 1 : 0);
pin_write(chip->pin_D8, (chip->adcValue > 909) ? 1 : 0);
pin_write(chip->pin_D7, (chip->adcValue > 796) ? 1 : 0);
pin_write(chip->pin_D6, (chip->adcValue > 667) ? 1 : 0);
pin_write(chip->pin_D5, (chip->adcValue > 568) ? 1 : 0);
pin_write(chip->pin_D4, (chip->adcValue > 455) ? 1 : 0);
pin_write(chip->pin_D3, (chip->adcValue > 341) ? 1 : 0);
pin_write(chip->pin_D2, (chip->adcValue > 227) ? 1 : 0);
pin_write(chip->pin_D1, (chip->adcValue > 114) ? 1 : 0);
pin_write(chip->pin_D0, (chip->adcValue > 0) ? 1 : 0);
  } else {
pin_write(chip->pin_D9, (chip->adcValue >> 9) & 1);
pin_write(chip->pin_D8, (chip->adcValue >> 8) & 1);
pin_write(chip->pin_D7, (chip->adcValue >> 7) & 1);
pin_write(chip->pin_D6, (chip->adcValue >> 6) & 1);
pin_write(chip->pin_D5, (chip->adcValue >> 5) & 1);
pin_write(chip->pin_D4, (chip->adcValue >> 4) & 1);
pin_write(chip->pin_D3, (chip->adcValue >> 3) & 1);
pin_write(chip->pin_D2, (chip->adcValue >> 2) & 1);
pin_write(chip->pin_D1, (chip->adcValue >> 1) & 1);
pin_write(chip->pin_D0, (chip->adcValue >> 0) & 1);
 }
 //printf("A1 Value: %f\n", chip->adcValue);
}
