#include		"div.hh"

ef::Div const		&ef::Div::operator=(Div const		&other)
{
  this->px = other.px;
  this->pos = other.pos;
  this->posEnd = other.posEnd;
  this->bg = other.bg;
  this->buttons = other.buttons;
  this->lastWasIn = other.lastWasIn;
  return(*this);
}
