#include <stdio.h>
#include <string.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/dict.h>

#include "id3reader.h"

struct tags read_file_info(char *filename, struct tags mp3){
  AVFormatContext* content = NULL;
  AVDictionaryEntry *tag = NULL;
  int i = 0;
  int test = avformat_open_input(&content, filename, NULL, NULL);
  if (test){
      printf("Error opening file: %s\n", filename);
      exit(1);
  }
  test = avformat_find_stream_info(content, NULL);
  mp3.duration = content -> duration/1000000;
  while ((tag = av_dict_get(content -> metadata, "", tag, AV_DICT_IGNORE_SUFFIX))){
    if (!strcmp("title", tag -> key)){
      strcpy(mp3.title, tag -> value);
    }
    else if (!strcmp("album", tag -> key)){
      strcpy(mp3.album, tag -> value);
    }
    else if (!strcmp("artist", tag -> key)){
      strcpy(mp3.artist, tag -> value);
    }
    else if (!strcmp("date", tag -> key)){
      strcpy(mp3.date, tag -> value);
    }
    else if (!strcmp("genre", tag -> key)){
      strcpy(mp3.genre, tag -> value);
    }
  }
  return mp3;
}

int main(int argc, char *argv[]){
  struct tags mp3;
  mp3 = read_file_info(argv[1], mp3);
  printf("Title: %s\n", mp3.title);
  printf("Artist: %s\n", mp3.artist);
  printf("Album: %s\n", mp3.album);
  printf("Date: %s\n", mp3.date);
  printf("Duration: %lus\n", mp3.duration);
  printf("Genre: %s\n", mp3.genre);
}
