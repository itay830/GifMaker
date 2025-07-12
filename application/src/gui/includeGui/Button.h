#pragma once

#include "raylib.h"




typedef struct Button Button;

struct Button {
  bool isEnabled;
  Rectangle *rect;
  char *text;

  void (*Release)(Button *btn);

  int (*Render)(Button *btn);
};

Button *NewButton(float x, float y, float width, float height, char *text);

int ButtonRender(Button *btn);

void ButtonRelease(Button *btn);
