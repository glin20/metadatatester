#include <stdio.h>
#include <string.h>
#include <libavformat/avformat.h>
#include <libavutil/dict.h>

#include "id3reader.h"

struct tags *make_tag(){
  struct tags *mp3 = malloc(sizeof(struct tags));
  return mp3;
}

struct tags *read_file_info(struct tags *mp3, char *filename){
  AVFormatContext* content = NULL;
  AVDictionaryEntry *tag = NULL;
  int i = 0;
  int test = avformat_open_input(&content, filename, NULL, NULL);
  if (test){
      printf("Error opening file: %s\n", filename);
      exit(1);
  }
  test = avformat_find_stream_info(content, NULL);
  strcpy(mp3 -> path, filename);
  mp3 -> duration = content -> duration/1000000;
  while ((tag = av_dict_get(content -> metadata, "", tag, AV_DICT_IGNORE_SUFFIX))){
    if (!strcmp("title", tag -> key)){
      strcpy(mp3 -> title, tag -> value);
    }
    else if (!strcmp("album", tag -> key)){
      strcpy(mp3 -> album, tag -> value);
    }
    else if (!strcmp("artist", tag -> key)){
      strcpy(mp3 -> artist, tag -> value);
    }
    else if (!strcmp("date", tag -> key)){
      strcpy(mp3 -> date, tag -> value);
    }
    else if (!strcmp("genre", tag -> key)){
      strcpy(mp3 -> genre, tag -> value);
    }
  }
  return mp3;
}
