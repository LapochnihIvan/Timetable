#include "Writer.h"


void Writer::write(std::wstring value)
{
	static std::vector<std::wofstream> files;
	static std::string filesNames[] = {
		"data\\days.txt",
		"data\\times.txt",
		"data\\numCabinet.txt",
		"data\\names.txt"
	};
	if (files.empty())
	{
		for (unsigned short numFile = 0; numFile < 4; numFile++) {
			std::wifstream input(filesNames[numFile]);
			static std::vector<std::wstring> valsOfFiles;
			if (valsOfFiles.empty())
			{
				std::wstring val;
				while (input >> val) valsOfFiles.emplace_back(val);
			}
			else for (std::wstring &val : valsOfFiles)
				input >> val;
			files.emplace_back(std::wofstream(filesNames[numFile]));
			for (const std::wstring &val : valsOfFiles) 
				files.back() << val << '\n';
		}
		std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
		files.back().imbue(loc);
	}
	static unsigned short numFile = 0;
	files[numFile] << value << '\n';
	numFile++;
}