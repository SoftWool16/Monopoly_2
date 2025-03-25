#pragma once
//ReadWriteBase.h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "LogFile.h"

extern LogFile Log;

class RWFile
{
public:
	RWFile(std::string name, bool log_debug_ = false) : log_debug(log_debug_)
	{
		while (!this_file.is_open())
		{
			this->file_name = name;
			if (log_debug) Log.AddLine("open \"" + file_name + "\"", Try);
			this_file = std::fstream(file_name);
			if (!this_file.is_open())
			{
				if(log_debug) Log.AddLine("forcibly create \"" + file_name + "\"", Warn);
				std::ofstream DebugFile(file_name);
				DebugFile.close();
			}
		}
		if (log_debug) Log.AddLine("open \"" + file_name + "\" - success", Luck);
		this_file.close();
	}

	void WrileLine(std::string line)
	{
		buff.push_back(line);
		if (log_debug) Log.AddLine("write to file\"" + file_name + "\"", Info);

	}
	std::string ReadLine()
	{		
		if(!this_file.is_open())
		this_file = std::fstream(file_name, std::ios::in);
		

		std::string tmp("<none>");
		if (log_debug) Log.AddLine("read from file \"" + file_name + "\"", Info);
		//this_file >> tmp;
		if (getline(this_file, tmp))
		{
			if (log_debug) Log.AddLine("read - success", Luck);
			//std::cout << tmp << "\n";
		} else {
			if (log_debug) Log.AddLine("cant read", Warn);
		}
		return tmp;
		
		
	}
	void Save()
	{
		if (this_file.is_open())
		{
			this_file.close();
		}
		this_file = std::fstream(file_name, std::ios::out);
		if (log_debug) Log.AddLine("save \"" + file_name + "\"", Info);
		for (auto iter : buff)
		{
			this_file << iter << "\n";
			if (log_debug) Log.AddLine(std::string("save... {") + iter[0] + iter[1] + iter[2] + "...}", Info);
		}
		buff.clear();
		this_file.close();

		
	}
	~RWFile()
	{
		if (log_debug) Log.AddLine("close \"" + file_name + "\"", Info);
		this_file.close();
	}

private:
	std::vector<std::string> buff;
	std::string file_name;
	std::fstream this_file;
	const bool log_debug;
};







