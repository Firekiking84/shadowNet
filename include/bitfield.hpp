// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 14/03/2024 13:00:12 ******************************************************
// damdoshi <damdoshi@aldrin.efrits.fr>
// - Bitfield -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef				__BITFIELD_HPP__

# define			__BITFIELD_HPP__

# include			<stdexcept>
# include			<vector>
# include			<sstream>
# include			<string>
# include			<stdint.h>

namespace			ef
{
  class				Bitfield
  {
    std::vector<uint8_t>	data;
    size_t			blen;

  public:
    class			BitfieldOverflow : public std::exception
    {
      std::string		msg;

    public:
      const char		*what(void) const noexcept
      {
	return (msg.c_str());
      }
      BitfieldOverflow(size_t	bfsize,
		       size_t	access_size)
      {
	std::stringstream	ss;

	ss << "Trying to access a bitfield of size " << bfsize << " with an "
	   << "index of value " << access_size << ".";
	msg = ss.str();
      }
      ~BitfieldOverflow(void)
      {}
    };
    class			ConstBit
    {
    protected:
      const uint8_t		&data;
      int			bit;

    public:
      operator			bool (void) const
      {
	return ((data >> bit) & 1);
      }
      ConstBit(const uint8_t	&_data,
	       size_t		_bit)
	: data(_data),
	  bit(_bit)
      {}
      ~ConstBit(void)
      {}
    };
    class			Bit
    {
    protected:
      uint8_t			&data;
      int			bit;

    public:
      // ABCD EFGH >> 3 => 000A BCDE & 1 => 0000 000E
      operator			bool (void) const
      {
	return ((data >> bit) & 1);
      }
      bool			operator=(bool			v)
      {
	if (v)
	  data |= 1 << bit;
	else
	  data &= ~(1 << bit);
	return (v);
      }
      Bit(uint8_t		&_data,
	  size_t		_bit)
	: data(_data),
	  bit(_bit)
      {}
      ~Bit(void)
      {}
    };

    Bit				operator[](size_t		idx)
    {
      if (idx >= blen)
	throw BitfieldOverflow(blen, idx);
      return (Bit{data[idx >> 3], idx & 0b111});
    }

    ConstBit			operator[](size_t		idx) const
    {
      if (idx >= blen)
	throw BitfieldOverflow(blen, idx);
      return (ConstBit{data[idx >> 3], idx & 0b111});
    }

    Bitfield			&operator=(const Bitfield	&bf)
    {
      if (this == &bf)
	return (*this);
      data = bf.data;
      blen = bf.blen;
      return (*this);
    }

    size_t			Serialize(std::ostream		&os) const
    {
      size_t			i;

      for (i = 0; i < data.size(); ++i)
	os << data[i];
      return (i);
    }

    size_t			Unserialize(std::istream	&is) const
    {
      is.read((char *)data.data(), data.size());
      return(is.gcount());
    }

    size_t			Print(std::ostream		&os) const
    {
      ssize_t			i;

      for (i = blen - 1; i >= 0; --i)
	os << (bool)(*this)[i];
      return (i);
    }

    Bitfield(size_t		len)
      : data((len >> 3) + ((len & 0b111) != 0 ? 1 : 0)),
	blen(len)
    {}
    Bitfield(const Bitfield	&bf)
    {
      *this = bf;
    }
    ~Bitfield(void)
    {}
  };
}

std::ostream			&operator<<(std::ostream	&os,
					    const ef::Bitfield	&bf);

#endif	//			__BITFIELD_HPP__
