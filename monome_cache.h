#ifndef _MONOME_CACHE_H
#define _MONOME_CACHE_H
extern int candor_has_monome_focus;
extern int monome_serialosc_port;
extern int candor_osc_port;
int candor_led_on(int x, int y);
  
int candor_led_off(int x, int y);
int candor_led_all(int status);
int candor_led_set(int x, int y, int on);

#endif
