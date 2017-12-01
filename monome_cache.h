#ifndef _MONOME_CACHE_H
#define _MONOME_CACHE_H
extern int candor_has_monome_focus;
int candor_led_on(int x, int y);
  
int candor_led_off(int x, int y);
int candor_led_all(int status);
int candor_led_set(int x, int y, int on);

#endif
