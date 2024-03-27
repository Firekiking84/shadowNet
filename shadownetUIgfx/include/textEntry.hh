#ifndef			__TEXT_ENTRY_HH__

#define			__TEXT_ENTRY_HH__

namespace		ef
{
  class			TextEntry
  {
  public:
    TextEntry(t_bunny_position				_pos,
	      int					_nbCharMax,
	      int					_nbLinesMax,
	      int					_sizeLetters,
	      t_bunny_pixelarray			*_px,
	      t_bunny_color				_bg,
	      t_bunny_color				_colLetter,
	      std::function<void(const char *)>		_output);
    ~TextEntry();
    void		draw();
    void		mouseClickEvent(t_bunny_mouse_button_event	mouseButton,
					bool				isReleased);
    void		keyEvent(t_bunny_key_event			key);
    void		textEvent(t_bunny_text_event			_text);
    void		reset();
    void		unfocus();
  private:
    t_bunny_position					pos;
    t_bunny_position					posEnd;
    int							nbCharMax;
    int							nbLinesMax;
    t_bunny_size					sizeLetter;
    t_bunny_pixelarray					*px;
    t_bunny_pixelarray					*font;
    t_bunny_color					bg;
    t_bunny_color					colLetter;
    std::function<void(const char *)>			output;
    bool						focus;
    bool						pullIn;
    std::string						text;
    int							sizeTextDisplay;

    bool		inBox(int			x,
			      int			y) const;
  }
}

#endif //		__TEXT_ENTRY_HH__
