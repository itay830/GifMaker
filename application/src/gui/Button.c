#include "includeGui/Button.h"
#include <assert.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


void Render(Button *this);

void Release(Button *this);

void SetOnClick(Button *this, void (*onClick)(Button *));

Button *NewButton(const float x, const float y, const float width, const float height, char *text) {
  Button *btn = malloc(sizeof(Button));
  assert(btn != NULL);
  btn->rect = malloc(sizeof(Rectangle));
  assert(btn->rect != NULL);
  btn->rect->x = x;
  btn->rect->y = y;
  btn->rect->width = width;
  btn->rect->height = height;
  btn->text = text;
  btn->Render = &Render;
  btn->Release = &Release;
  btn->SetOnClick = &SetOnClick;
  btn->OnClick = nullptr;
  btn->ctx = nullptr;
  return btn;
}

void Release(Button *this) {
  free(this->rect);
  free(this);
}

void Render(Button *this) {
  const int isClicked = GuiButton(*(this->rect), this->text);
  if (this->isEnabled && isClicked) {
    this->OnClick(this);
  }
}

void SetOnClick(Button *this, void (*onClick)(Button *)) {
  assert(this->OnClick == nullptr);
  this->OnClick = onClick;
}
