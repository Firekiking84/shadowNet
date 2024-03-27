#ifndef			__TEXT_ENTRY_HH__

#define			__TEXT_ENTRY_HH__

namespace		ef
{
  class			textEntry
  {
  public:
    textEntry(t_bunny_position				_pos,
	      int					_nbCharMax,
	      int					_nbLinesMax,
	      int					_sizeLetters,
	      t_bunny_color				_bg,
	      bool const				*_keyboard,
	      bool const				*_mouseButtons,
	      t_bunny_position const			*_mousePos,
	      std::function<void(const char *)>		output);
    ~textEntry();
    void		run(t_bunny_pixelarray	*px);
  private:
    
  }
}

#endif //		__TEXT_ENTRY_HH__
