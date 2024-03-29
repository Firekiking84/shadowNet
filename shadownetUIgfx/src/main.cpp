#include		"shadownetUIgfx.hh"
#include		"gui.hh"

#include		<lapin.h>

int			main(int		ac,
			     char		**av)
{
  if (ac < 4)
    {
      std::cerr << "Not enough argument !" << std::endl;
      std::cerr << "Pattern : ./UI [portUI] [ipSoftware] [portSoftware]" << std::endl;
      return(-1);
    }
  std::string		tmpStr;
  int			portUI;
  int			portSoft;
  std::string		ip;

  tmpStr = av[1];
  portUI = stoi(tmpStr);
  ip = av[2];
  tmpStr = av[3];
  portSoft = stoi(tmpStr);

  t_bunny_window	*win;
  ef::s_data		data;

  data.px = bunny_new_pixelarray(500, 500);
  win = bunny_start(500, 500, false, "ShadowNet");
  bunny_set_loop_main_function(ef::loop);
  bunny_set_display_function(ef::display);
  ef::Gui		gui(data.px, portUI, ip, portSoft);
  t_bunny_position	pos;
  t_bunny_size		size;
  t_bunny_color		colCMD;
  t_bunny_color		colResult;
  t_bunny_color		colReceive;
  t_bunny_color		colFont;
  std::string		divName;
  std::string		text;
  std::function<void(std::string const &)>	output = std::bind(&ef::Gui::addFriend, &gui, std::placeholders::_1);

  pos.x = 0;
  pos.y = 0;
  size.x = 200;
  size.y = 500;
  colCMD.full = BLACK;
  divName = "cmdPanel";
  gui.addDiv(divName, pos, size, &colCMD);

  text = "Add friend :";
  colFont.full = WHITE;
  gui.addTextArea(divName, pos, 14, nullptr, colFont, text);

  pos.y = 15;
  gui.addTextEntry(divName, pos, 30, 1, 14, colFont, colCMD, output);

  pos.y += 20;
  text = "Remove Friend :";
  gui.addTextArea(divName, pos, 14, nullptr, colFont, text);

  pos.y += 15;
  output = std::bind(&ef::Gui::rmFriend, &gui, std::placeholders::_1);
  gui.addTextEntry(divName, pos, 30, 1, 14, colFont, colCMD, output);

  pos.y += 20;
  text = "Research :";
  gui.addTextArea(divName, pos, 14, nullptr, colFont, text);

  pos.y += 15;
  output = std::bind(&ef::Gui::startResearch, &gui, std::placeholders::_1);
  gui.addTextEntry(divName, pos, 30, 1, 14, colFont, colCMD, output);

  pos.y += 20;
  text = "Receive by \nSoftware : ";
  gui.addTextArea(divName, pos, 14, nullptr, colFont, text);

  pos.y = 135;
  pos.x = 0;
  size.x = 200;
  size.y = 500 - pos.y;
  divName = "receiveSoft";
  colReceive.full = BLUE;
  gui.addDiv(divName, pos, size, &colReceive);

  pos.x = 200;
  pos.y = 0;
  size.x = 300;
  size.y = 500;
  colResult.full = WHITE;
  divName = "resultPanel";
  gui.addDiv(divName, pos, size, &colResult);

  data.gui = &gui;
  data.win = win;
  pos.x = 0;
  pos.y = 0;
  data.origin = pos;
  bunny_loop(win, 60, &data);
  bunny_stop(win);
  bunny_delete_clipable(&data.px->clipable);
}
