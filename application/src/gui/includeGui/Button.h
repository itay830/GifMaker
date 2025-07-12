#pragma once

#include "raylib.h"

typedef struct Button Button;

struct Button {
  bool isEnabled;
  Rectangle *rect;
  char *text;

  void (*OnClick)(Button *this);

  void (*Release)(Button *this);

  void (*Render)(const Button *this);

  void (*SetOnClick)(Button *this, void (*onClick)(Button *this));

  // Experiment
  void *object;

};

Button *NewButton(float x, float y, float width, float height, char *text);

void ButtonRender(Button *this);

void ButtonRelease(Button *this);

void SetOnClick(Button *this, void (*onClick)(Button *));
