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

void ButtonRelease(Button *btn) {
  free(btn->rect);
  free(btn);
}

void ButtonRender(const Button *btn) {
  const int isClicked = GuiButton(*(btn->rect), btn->text);
  if (btn->isEnabled && isClicked) {
    btn->OnClick();
  }
}

void SetOnClick(Button *btn, void (*onClick)()) {
  assert(btn->OnClick == nullptr);
  btn->OnClick = onClick;
}
