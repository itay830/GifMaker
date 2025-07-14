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

  void (*SetOnClick)(Button *this, void (*onClick)(Button *btn));

  void *ctx; // OnClick context to use
};


Button *NewButton(Rectangle rect, char *text);
