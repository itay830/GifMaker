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
  return btn;
}

void ButtonRelease(Button *btn) {
  free(btn->rect);
  free(btn);
}

int ButtonRender(Button *btn) {
  if (btn->isEnabled) {
    return GuiButton(*(btn->rect), btn->text);
  }
  return 0;
}
