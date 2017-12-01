#include "monome_cache.h"
int candor_has_monome_focus = 1;

int candor_led_on(int x, int y) {
  if(candor_has_monome_focus) {
    /* monome_led_on(monome, x, y); */
  }
}

int candor_led_off(int x, int y) {
  if(candor_has_monome_focus) {
    /* monome_led_off(monome, x, y); */
  }
}

int candor_led_all(int status) {
  if(candor_has_monome_focus) {
      /* monome_led_all(monome, status); */
  }
}

int candor_led_set(int x, int y, int on) {
  if(candor_has_monome_focus) {
    /* monome_led_set(monome, x, y, on); */
  }
};
