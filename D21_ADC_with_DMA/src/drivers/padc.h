#ifndef _PADC_H_
#define _PADC_H_

#include <asf.h>

void padc_init(void);
void padc_start(void);

float padc_get_voltage(void);

uint16_t padc_get_raw(void);
#endif