/**
 * EBC code with GNU as Code Composer Studio compiler
 */

#include "display.h"
#include "msp.h"

#define DISPLAY_WIDTH   128
#define DISPLAY_HEIGHT  128

display_t *display;

/**
 * Main program entry point
 */
int main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

	display = display_init(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 interrupt enabled
    TIMER_A0->CCR[0] = 50000;
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__CONTINUOUS;

    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk; // Enable sleep on exit from ISR
    __DSB(); // Ensures SLEEPONEXIT takes effect immediately

    // Enable global interrupt
    __enable_irq();

    NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);

    while (1)
    {
        __sleep();
        __no_operation();
    }

	return (0);
}

void TA0_0_IRQHandler(void)
{
	display_swap_buffers(display);
}
