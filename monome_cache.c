#include "monome_cache.h"
#include <lo/lo.h>
#include <stdlib.h>

int candor_has_monome_focus = 1;
int monome_serialosc_port = 0;
static lo_address a;
void refresh_address () {
  char addr[64];
  sprintf(addr, "%d", monome_serialosc_port);
  a = lo_address_new(NULL, addr);
}

int candor_osc_port = 0;

void candor_grab_focus(void) {
  if(monome_serialosc_port) {
    refresh_address();
    lo_send(a, "/sys/port", "i", candor_osc_port);
    printf("grabbing focus %d %d...\n", candor_osc_port, monome_serialosc_port);
  }
}

int candor_led_on(int x, int y) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_on(monome, x, y); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y, 1);
  }
}

int candor_led_off(int x, int y) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_off(monome, x, y); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y, 0);
  }
}

int candor_led_all(int status) {
  if(candor_has_monome_focus && monome_serialosc_port) {
      /* monome_led_all(monome, status); */
    refresh_address();
    lo_send(a, "/monome/grid/led/all", "i", status);
  }
}

int candor_led_set(int x, int y, int on) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_set(monome, x, y, on); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y, on);
  }
};
