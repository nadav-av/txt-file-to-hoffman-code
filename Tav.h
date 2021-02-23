#pragma once

#include <iostream> 

namespace huf
{
	class Tav
	{
	private:
		char _ch;
		int _freq;

	public:
		friend std::ostream& operator<<(std::ostream& os, const Tav& tav);

		Tav();
		Tav(char ch, int freq);
		void set_char(char ch);
		void set_freq(int freq);
		int get_freq() const;
		int get_char() const;
		void add_to_freq();
		bool operator==(const Tav& other) const;
		bool operator!=(const Tav& other) const;
		const Tav& operator=(const Tav& other);
	};
}