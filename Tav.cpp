#include <iostream>
#include "Tav.h"

namespace huf
{
	Tav::Tav()
	{
		//Ctrl purposes and only for buld tree and array from file (in BSTree.cpp)
		_ch = -1;
		_freq = 0; 
	}


	Tav::Tav(char ch, int freq) : _ch(ch), _freq(freq) {}


	void Tav::set_char(char ch)
	{
		_ch = ch;
	}
	void Tav::set_freq(int freq)
	{
		_freq = freq;
	}
	int Tav::get_freq() const
	{
		return _freq;
	}
	int Tav::get_char() const
	{
		return _ch;
	}

	//Called from the BStree- used to add 1 appearances when key is already found
	void Tav::add_to_freq()
	{
		_freq++;
	}

	bool Tav::operator==(const Tav& other) const
	{
		return ((_ch == other._ch) && (_freq == other._freq));
	}
	bool Tav::operator!=(const Tav& other) const
	{
		return (_ch != other._ch) || (_freq != other._freq);
	}

	const Tav& Tav::operator=(const Tav& other)
	{
		if (this != &other)
		{
			_ch = other._ch;
			_freq = other._freq;
		}

		return *this;
	}


	//Print a tav - DEBUG purposes
	std::ostream& operator<<(std::ostream& os, const Tav& tav)
	{
		return os << "ch: " << tav._ch << " freq: " << tav._freq << std::endl;
	}

}

