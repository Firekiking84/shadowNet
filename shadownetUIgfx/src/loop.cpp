#include		"shadownetUIgfx.hh"

t_bunny_response	ef::loop(void		*data2)
{
  s_data		*data;

  data = (s_data *)data2;
  data->gui->draw();
  bunny_blit(&data->win->buffer, &data->px->clipable, &data->origin);
  bunny_display(data->win);
  return(GO_ON);
}
