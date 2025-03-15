#include "easyrpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dispatch_command(rpn_calc *calc, char command) {
  switch (command) {
  case 'd':
    rpn_stack_drop(calc);
    break;
  case '+': {
    if (rpn_add(calc)) {
      printf("error adding");
    }
    break;
  }
  default:
    break;
  }
}

int main() {
  rpn_calc *calc = rpn_init();

  char buffer[128];

  for (;;) {
    printf("> ");
    scanf("%s", buffer);
    if (strncmp("exit", buffer, 128) == 0)
      break;
    size_t len = strnlen(buffer, 128);
    if (len == 0) {
      continue;
    } else if (len == 1) {
      dispatch_command(calc, buffer[0]);
    } else {
      double num = atof(buffer);
      rpn_stack_push(calc, num);
    }
    rpn_stacknode *ptr = calc->stack.bottom;
    while (ptr != NULL) {
      printf("%f\n", ptr->data);
      ptr = ptr->next;
    }
  }

  rpn_deinit(calc);
  return 0;
}
