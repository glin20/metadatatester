#include "library.h"

struct library *make_library(){
  struct library *library = calloc(1, sizeof(struct library));
  library -> album = NULL;
  library -> next = NULL;
  return library;
}

struct library *add_to_library(struct library *data, char *filename){
  struct tags *new_mp3 = make_tag();
  new_mp3 = read_file_info(new_mp3, filename);
  struct library *head = data;
  if(data -> album == NULL){
    struct album *new_album = make_album();
    strcpy(new_album -> name, new_mp3 -> album);
    new_album -> data = new_mp3;
    data -> album = new_album;
  }
  else{
    while(data != NULL){
      if (!strcasecmp(data -> album -> name, new_mp3 -> album)){
        add_to_album(data -> album, new_mp3);
        return head;
      }
      data = data -> next;
    }
    struct album *new_album = make_album();
    strcpy(new_album -> name, new_mp3 -> album);
    new_album -> data = new_mp3;
    data = make_library();
    data -> album = new_album;
    struct library *temp = head;
    while(temp -> next != NULL){
      temp = temp -> next;
    }
    temp -> next = data;
  }
  return head;
}
