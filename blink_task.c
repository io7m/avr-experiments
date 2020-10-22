#include <avr/io.h>
#include <stdio.h>
#include "blink_task.h"

static uint8_t blink_on = 0;
static int blink_rate = 500;

#define LED ((1 << 7))

static void
blink_task_init(void)
{
  DDRB |= LED;
}

static void
blink_task_run(const uint32_t time)
{
  if (time % blink_rate == 0) {
    blink_on = !blink_on;
    if (blink_on) {
      puts("Blink!");
    }
  }

  if (blink_on) {
    PORTB |= LED;
  } else {
    PORTB &= ~LED;
  }
}

void blink_set_rate(int time)
{
  blink_rate = time;
}

const struct task_t blink_task = {
  &blink_task_init,
  &blink_task_run
};
