#ifndef _MONOME_CACHE_H
#define _MONOME_CACHE_H
#include <monome.h>
extern int candor_has_monome_focus;
int candor_led_on(monome_t *monome, uint x, uint y);
  
int candor_led_off(monome_t *monome, uint x, uint y);
int candor_led_all(monome_t *monome, uint status);
int candor_led_set(monome_t *monome, uint x, uint y, uint on);

#endif
