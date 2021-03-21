#ifndef READER_H
#define READER_H

#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

using u8string = std::basic_string<unsigned char>;
using u8ifstream = std::basic_ifstream<unsigned char>;

class Reader
{
public:
	Reader();
	void read(std::vector<std::vector<u8string>> &strings);

private:

};
#endif
