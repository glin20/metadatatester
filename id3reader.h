#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tags{
  char title[252];
  char artist[252];
  char album[252];
  char date[20];
  char genre[20];
  unsigned long duration;
  struct tags *next = NULL;
};
