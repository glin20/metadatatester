#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tags{
  char title[252];
  char artist[252];
  char album[252];
  char date[20];
  char genre[20];
  char path[100];
  int duration;
};

struct tags *make_tag();
struct tags *read_file_info(struct tags *mp3, char *filename);
