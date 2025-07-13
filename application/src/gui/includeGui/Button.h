#pragma once

#include "raylib.h"

typedef struct Button Button;

struct Button {
  bool isEnabled;
  Rectangle *rect;
  char *text;

  void (*OnClick)(Button *this);

  void (*Release)(Button *this);

  void (*Render)(Button *this);

  void (*SetOnClick)(Button *this, void (*onClick)(Button *this));

  void *ctx; // OnClick context to use
};

Button *NewButton(float x, float y, float width, float height, char *text);
