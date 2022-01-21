#include "album.h"

struct library{
  struct album *album;
  struct library *next;
};

struct library *make_library();
struct library *add_to_library(struct library *data, char *filename);
