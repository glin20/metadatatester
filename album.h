#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "id3reader.h"

struct album{
  char name[252];
  struct tags *data;
  struct album *next;
};

struct album *make_album();
struct album *add_to_album(struct album *data, struct tags *new_mp3);
void save_album(struct album *data, struct tags *new_mp3);
