#ifndef _74HC595_H
#define _74HC595_H

#include "main.h"

// Линии порта
#define R74HC595_SHIFT_PORT     GPIOA
#define R74HC595_CLK_PORT       GPIOA
#define R74HC595_DATA_PORT      GPIOA

// Линии пинов
#define R74HC595_DATA_PIN       PIN1
#define R74HC595_SHIFT_PIN      PIN3
#define R74HC595_CLK_PIN        PIN5


// Защелка
#define R74HC595_SHIFT_0()      (GPIOPinReset(R74HC595_SHIFT_PORT, R74HC595_SHIFT_PIN))
#define R74HC595_SHIFT_1()      (GPIOPinSet(R74HC595_SHIFT_PORT, R74HC595_SHIFT_PIN))

// Строб
#define R74HC595_CLK_0()        (GPIOPinReset(R74HC595_CLK_PORT, R74HC595_CLK_PIN))
#define R74HC595_CLK_1()        (GPIOPinSet(R74HC595_CLK_PORT, R74HC595_CLK_PIN))

// Данные
#define R74HC595_DATA_0()       (GPIOPinReset(R74HC595_DATA_PORT, R74HC595_DATA_PIN))
#define R74HC595_DATA_1()       (GPIOPinSet(R74HC595_DATA_PORT, R74HC595_DATA_PIN))

// Функция вывода байта
// В качестве аргумента получает выводимый байт
void reg_74hc595_byte(uint8_t data);

// Функция вывода двух байт
// В качестве аргумента получает выводимое 2-х байтовое число
void reg_74hc595_word(uint16_t data);

void reg_74hc959_init(void);

#endif /* _74HC595_H */
