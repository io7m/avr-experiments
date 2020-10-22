#ifndef UART_H
#define UART_H

#include <stdio.h>

void uart_init();
int uart_putchar(char, FILE *);
int uart_getchar(FILE *);

#endif // UART_H