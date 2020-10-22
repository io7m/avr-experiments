#ifndef TASK_H
#define TASK_H

#include "stdint.h"

struct task_t {
  void (*init)(void);
  void (*run)(uint32_t);
};

#endif // TASK_H
