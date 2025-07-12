#pragma once

#include "raylib.h"

typedef struct Button Button;

struct Button {
  bool isEnabled;
  Rectangle *rect;
  char *text;

  void (*OnClick)();

  void (*Release)(Button *this);

  void (*Render)(const Button *this);

  void (*SetOnClick)(Button *this, void (*onClick)());
};

Button *NewButton(float x, float y, float width, float height, char *text);

void ButtonRender(const Button *this);

void ButtonRelease(Button *this);

void SetOnClick(Button *this, void (*onClick)());
