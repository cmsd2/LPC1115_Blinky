/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

#define TICKRATE_HZ (1000)

volatile bool led = false;
volatile int ticks = 0;

extern "C" void SysTick_Handler(void)
{
	ticks++;
}

static void Delay (uint32_t delay)
{
    uint32_t start = ticks;
    while((ticks - start) < delay) {
    	// loop
    }
}

int main(void) {
	uint32_t timerFreq;

	SystemCoreClockUpdate();

	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	/* LEDs toggle in interrupt handlers */
	while (1) {
		Delay(500);
		led ^= true;
		Board_LED_Set(0, led);
	}

	return 0;
}
