#include "monome_cache.h"
#include <lo/lo.h>
#include <stdlib.h>

int candor_has_monome_focus = 1;
int monome_serialosc_port = 0;
int grid_128_y_offset = 0;
static lo_address a;

int g[256] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int grid_xy_idx (int x, int y) {
  return x + y * 16;
}
void candor_monome_cache_set(int val) {
  int i;
  for(i=0; i < 256; i++) {
    g[i] = val;
  }
}

void refresh_address () {
  char addr[64];
  sprintf(addr, "%d", monome_serialosc_port);
  a = lo_address_new(NULL, addr);
}

int candor_osc_port = 0;
void transmit_cached() {
    int i, j;
  for(i=0; i < 16; i++) {
    for(j=0; j < 8; j++) {
      lo_send(a, "/monome/grid/led/set", "iii",
	      i, j,
	      g[grid_xy_idx(i, j+grid_128_y_offset)]);
    }
  }
}
void candor_toggle_128(void) {
  if(grid_128_y_offset == 0) {
    grid_128_y_offset = 8;
  }
  else {
    grid_128_y_offset = 0;
  }
  transmit_cached();
}

void candor_grab_focus(void) {
  if(monome_serialosc_port) {
    refresh_address();
    lo_send(a, "/sys/port", "i", candor_osc_port);
    printf("grabbing focus %d %d...\n", candor_osc_port, monome_serialosc_port);
  }
  transmit_cached();
}

int candor_led_on(int x, int y) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_on(monome, x, y); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y-grid_128_y_offset, 1);
    g[grid_xy_idx(x, y)] = 1;
  }
}

int candor_led_off(int x, int y) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_off(monome, x, y); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y-grid_128_y_offset, 0);
    g[grid_xy_idx(x, y)] = 0;
  }
}

int candor_led_all(int status) {
  if(candor_has_monome_focus && monome_serialosc_port) {
      /* monome_led_all(monome, status); */
    refresh_address();
    lo_send(a, "/monome/grid/led/all", "i", status);
    candor_monome_cache_set(status);
  }
}

int candor_led_set(int x, int y, int on) {
  if(candor_has_monome_focus && monome_serialosc_port) {
    /* monome_led_set(monome, x, y, on); */
    refresh_address();
    lo_send(a, "/monome/grid/led/set", "iii", x, y-grid_128_y_offset, on);
    g[grid_xy_idx(x, y)] = on;
  }
}
