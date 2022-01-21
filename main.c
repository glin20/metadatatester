#include "library.h"

int main(int argc, char *argv[]){
  struct library *lib = make_library();
  lib = add_to_library(lib, argv[1]);
  lib = add_to_library(lib, argv[2]);
  lib = add_to_library(lib, argv[3]);
  printf("%s\n", lib -> album -> next -> data -> title);
}
