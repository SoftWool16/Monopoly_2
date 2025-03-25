#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


enum ErrTag
{
	Try,
	Luck,
	Info,
	Warn,
	Error,
	Fatal
};

class LogFile
{
public:
	LogFile()
	{
		log_file_name = "log";
		log_file_name += std::to_string(time(NULL)) + ".txt";

		log_file = std::ofstream(log_file_name, std::ios::out);
		log_file << "log_file - start\n";
		log_file.close();
		

	}
	void AddLine(std::string new_line, ErrTag tag_)
	{
		log_file = std::ofstream(log_file_name, std::ios::app);

		switch (tag_)
		{
		case Try:
			log_file << "[T] ";
			break;
		case Luck:
			log_file << "[L] ";
			break;
		case Info:
			log_file << "[I] ";
			break;
		case Warn:			 
			log_file << "[W] ";
			break;			 
		case Error:			 
			log_file << "[E] ";
			break;			 
		case Fatal:			 
			log_file << "[F] ";
			break;
		default:
			break;
		}

		if (F_AddTime)
			log_file << "(" << std::to_string(time(NULL)) << ")";

		log_file << new_line << "\n";
		log_file.close();
	}
	~LogFile()
	{
		log_file = std::ofstream(log_file_name, std::ios::app);
		log_file << "log_file - stop";
		log_file.close();
	}
	bool F_AddTime = false;
private:
	std::string log_file_name;
	std::ofstream log_file;
};

LogFile Log;