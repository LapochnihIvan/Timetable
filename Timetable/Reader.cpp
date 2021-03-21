#include "Reader.h"

Reader::Reader()
{

}

void
Reader::read(std::vector<std::vector<u8string>> &strings)
{
	static std::vector<std::string> files = {
		"data\\days.txt",
		"data\\times.txt",
		"data\\numCabinet.txt",
		"data\\names.txt"
	};
	for (unsigned short numFile = 0; numFile < 4; numFile++)
	{
		u8ifstream input(files[numFile]);
		if (strings.empty())
		{
			static u8string value;
			while (input >> value)
			{
				strings.emplace_back(std::vector<u8string>(4));
				strings.back()[numFile] = value;
			}
		}
		else for (std::vector<u8string> &col : strings)
			input >> col[numFile];
	}
}