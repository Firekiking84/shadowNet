#include		"gui.hh"

void			ef::Gui::listen()
{
  int			fd;

  fd = network.can(ef::NetworkUDP::Mode::READ, -1, 0);
  if (fd != -1 && fd != -3)
    {
      std::string	divName;
      t_bunny_position	pos;
      t_bunny_size	size;

      divName = "receiveSoft";
      rmDiv(divName);
      pos.x = 0;
      pos.y = 135; // see main.cpp:79
      size.x = 200;
      size.y = 500 - pos.y;
      addDiv(divName, pos, size, nullptr);

      std::string	buffer;
      t_bunny_color	colFont;

      colFont.full = WHITE;
      network.recvFromSoft(buffer);
      addTextArea(divName, pos, 14, nullptr, colFont, buffer);
    }
  std::string		refreshInfo;

  refreshInfo = "logs";
  network.sendSoft(refreshInfo);
}
