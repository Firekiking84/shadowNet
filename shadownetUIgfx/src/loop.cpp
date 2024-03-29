#include		"shadownetUIgfx.hh"

t_bunny_response	ef::loop(void		*data2)
{
  s_data		*data;

  data = (s_data *)data2;
  data->gui->listen();
  return(GO_ON);
}
