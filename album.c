#include "album.h"

struct album *make_album(){
  struct album *album = calloc(1, sizeof(struct album));
  album -> data = NULL;
  album -> next = NULL;
  return album;
}


struct album *add_to_album(struct album *data, struct tags *new_mp3){
  struct album *head = data;
  struct album *new_data = make_album();
  new_data -> data = new_mp3;
  if (data -> data == NULL){
    data = new_data;
    return data;
  }
  else{
    while (data -> next != NULL){
      data = data -> next;
    }
    data -> next = new_data;
    return head;
  }
}

/*void save_album(struct album *data, char *filename){
  int i = open(filename, O_TRUNC | O_WRONLY | O_CREAT | O_APPEND, 0644);
  while(data -> next != NULL){
    write(i, data -> data, sizeof(struct tags));
    data = data -> next;
  }
  write(i, data -> data, sizeof(struct tags));
  close(i);
}*/
