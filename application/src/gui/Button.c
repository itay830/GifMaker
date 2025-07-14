#include "includeGui/Button.h"
#include <assert.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void Render(Button *this);

void Release(Button *this);

void SetOnClick(Button *this, void (*onClick)(Button *));

Button *NewButton(const Rectangle rect, char *text) {
  Button *btn = malloc(sizeof(Button));
  assert(btn != NULL);
  btn->rect = malloc(sizeof(Rectangle));
  assert(btn->rect != NULL);
  btn->rect->x = rect.x;
  btn->rect->y = rect.y;
  btn->rect->width = rect.width;
  btn->rect->height = rect.height;
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
