#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init(char val, float d) {
  struct stack *t = malloc(sizeof(struct stack));
  t->data = val;
  t->num = d;
  t->next = NULL;
  return t;
}

struct stack *push(struct stack *h, char val) {
  printf("NOW PUSH %c\n", val);
  if (h != NULL) {
    struct stack *new_el = init(val, 0);
    new_el->next = h;
    h = new_el;
  } else {
    h = init(val, 0);
  }
  return h;
}

struct stack *push_num(struct stack *h, float val) {
  printf("\n\nNOW PUSH %f\n", val);
  if (h != NULL) {
    struct stack *new_el = init('\0', val);
    new_el->next = h;
    h = new_el;
  } else {
    h = init('\0', val);
  }
  return h;
}

struct stack *pop(struct stack *h) {
  if (h != NULL) {
    struct stack *del = h;
    h = h->next;
    free(del);
  }
  return h;
}
void destroy(struct stack *h) {
  struct stack *destroyer = h;

  while (destroyer != NULL) {
    h = h->next;
    free(destroyer);
    destroyer = h;
  }
}

void stack_output(struct stack *h) {
  if (h == NULL) {
    printf("Stack is empty");
  } else {
    struct stack *runner = h;
    while (runner != NULL) {
      if (runner->data != '\0')
        printf("%c ", runner->data);
      else
        printf("%.2f ", runner->num);
      runner = runner->next;
    }
  }
}

int stack_len(struct stack *h) {
  struct stack *runner = h;
  int count = 0;
  while (runner != NULL) {
    count++;
    runner = runner->next;
  }
  return count;
}

char pick(struct stack *h) { return h->data; }