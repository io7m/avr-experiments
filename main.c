#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>

#include "uart.h"
#include "blink_task.h"

static FILE uart_output =
  FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
static FILE uart_input =
  FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

static uint32_t time;

static const struct task_t *tasks[] = {
  &blink_task
};
static const int task_count = sizeof(tasks) / sizeof(const struct task *);

int
main (void)
{
  uart_init();
  stdout = &uart_output;
  stdin  = &uart_input;

  for (int index = 0; index < task_count; ++index) {
    tasks[index]->init();
  }

  blink_set_rate(500);

  while (1) {
    for (int index = 0; index < task_count; ++index) {
      tasks[index]->run(time);
    }

    _delay_ms(1);
    ++time;
  }
}
