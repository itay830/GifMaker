#include "includeGui/Button.h"
#include <assert.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


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
  btn->Render = &ButtonRender;
  btn->Release = &ButtonRelease;
  btn->SetOnClick = &SetOnClick;
  btn->OnClick = nullptr;
  return btn;
}

void ButtonRelease(Button *this) {
  free(this->rect);
  free(this);
}

void ButtonRender(const Button *this) {
  const int isClicked = GuiButton(*(this->rect), this->text);
  if (this->isEnabled && isClicked) {
    this->OnClick();
  }
}

void SetOnClick(Button *this, void (*onClick)()) {
  assert(this->OnClick == nullptr);
  this->OnClick = onClick;
}
