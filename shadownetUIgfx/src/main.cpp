#include		"shadownetUIgfx.hh"
#include		"gui.hh"

void			print_test()
{
  std::cout << "Le test se passe bien" << std::endl;
}

int			main(void)
{
  t_bunny_window	*win;
  ef::s_data		data;

  data.px = bunny_new_pixelarray(500, 500);
  win = bunny_start(500, 500, false, "ShadowNet");
  bunny_set_loop_main_function(ef::loop);
  ef::Gui		gui(data.px);
  t_bunny_position	pos;
  t_bunny_size		size;
  t_bunny_color		col[3];
  std::function<void()>	trigger = []() { print_test(); };
  std::string		divName;

  pos.x = 0;
  pos.y = 0;
  size.x = 250;
  size.y = 250;
  divName = "div1";
  gui.addDiv(divName, pos, size, nullptr);

  pos.x = 10;
  pos.y = 10;
  size.x = 50;
  size.y = 50;
  col[0].full = RED;
  col[1].full = WHITE;
  col[2].full = BLUE;

  gui.addButton(divName, pos, size, col, 3, trigger);

  data.gui = &gui;
  data.win = win;
  pos.x = 0;
  pos.y = 0;
  data.origin = pos;
  bunny_loop(win, 60, &data);
  bunny_stop(win);
  bunny_delete_clipable(&data.px->clipable);
}
