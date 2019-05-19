//
//  util.c
//  diff
//
//  Created by William McCarthy on 5/9/19.
//  Copyright © 2019 William McCarthy. All rights reserved.
//

#include "util.h"
#include "options.h"
#include <stdlib.h>
#include <string.h>

#define BUFLEN 256

char *yesorno(int condition) { return condition == 0 ? "no" : "YES"; }

FILE *openfile(const char *filename, const char *openflags) {
  FILE *f;
  if ((f = fopen(filename, openflags)) == NULL) {
    printf("can't open '%s'\n", filename);
    exit(1);
  }
  return f;
}

void printline(void) {
  if (showbrief) {
    return;
  }
  for (int i = 0; i < 10; ++i) {
    printf("==========");
  }
  printf("\n");
}

void printleft(const char *left) {
  if (showbrief) {
    return;
  }
  char buf[BUFLEN];

  strcpy(buf, left);
  if (showsidebyside) {
    int j = 0, len = (int)strlen(buf) - 1;
    for (j = 0; j <= 48 - len; ++j) {
      buf[len + j] = ' ';
    }
    buf[len + j++] = '<';
    buf[len + j++] = '\0';
    printf("%s\n", buf);
  } else {
    int j = 0, len = (int)strlen(buf) - 1;
    printf("< ");
    printf("%s", buf);
  }
}

void printright(const char *right) {
  if (showbrief) {
    return;
  }
  if (right == NULL) {
    return;
  }

  if (showsidebyside) {
    printf("%50s %s", ">", right);
  } else {
    printf("%s %s", ">", right);
  }
}

void printboth(const char *left_right) {
  if (showbrief) {
    return;
  }

  char buf[BUFLEN];
  size_t len = strlen(left_right);
  if (len > 0) {
    strncpy(buf, left_right, len);
  }
  buf[len - 1] = '\0';

  if (showleftcolumn) {
    char *lp = (char *)left_right;
    while (*lp != '\n') {
      lp++;
    }
    *lp = '\0';

    printf("%-50s)\n", left_right);
  } else {
    printf("%-50s %s", buf, left_right);
  }
}
