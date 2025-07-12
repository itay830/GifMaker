#pragma once

#include "raylib.h"

typedef struct Button Button;

struct Button {
  bool isEnabled;
  Rectangle *rect;
  char *text;

  void (*OnClick)();

  void (*Release)(Button *btn);

  void (*Render)(const Button *btn);

  void (*SetOnClick)(Button *btn, void (*onClick)());
};

Button *NewButton(float x, float y, float width, float height, char *text);

void ButtonRender(const Button *btn);

void ButtonRelease(Button *btn);

void SetOnClick(Button *btn, void (*onClick)());
