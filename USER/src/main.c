#include "main.h"

#define F_APB1               42000000UL

uint32_t TimingDelay = 0;

void delay_ms(uint16_t delay);
	
/* ========================================================================== */
int main(void)
{
	uint8_t data = 0x01;
	
	InitRCC();
	InitLED();
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
	
	reg_74hc959_init();
	
	while (1)
	{
		reg_74hc595_byte(data);
		delay_ms(500);
		data = data << 1;
		if (data == 0x00) data = 0x01;
	}	
}

void delay_ms(uint16_t delay) 
{ 
	TimingDelay	= delay;
	while(TimingDelay);
}

void SysTick_Handler() {
   TimingDelay--;
}
