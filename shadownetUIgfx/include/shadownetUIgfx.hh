#ifndef				__SHADOW_NET_UI_GFX_HH__

#define				__SHADOW_NET_UI_GFX_HH__

#include			"gui.hh"

#include			<iostream>

namespace			ef
{
  struct			s_data
  {
    ef::Gui			*gui;
    t_bunny_pixelarray		*px;
    t_bunny_window		*win;
    t_bunny_position		origin;
  };
  t_bunny_response		mouseMoveResponse(t_bunny_position const	*relative,
						  void				*data2);
  t_bunny_response		mouseClickResponse(t_bunny_event_state		state,
						   t_bunny_mouse_button		button,
						   void				*data2);
  t_bunny_response		loop(void					*data2);
  t_bunny_response		display(void					*data2);
  t_bunny_response		key_event_response(t_bunny_event_state		state,
						   t_bunny_keysym		sym,
						   void				*data2);
}

#endif	//			__SHADOW_NET_UI_GFX_HH__
