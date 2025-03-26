#include <iostream>
#include <fstream>
#include <string>

#include "ReadWriteFile.h"
#include "LogFile.h"
#include "DataBase.h"

LogFile Log;

int main() {
	// создание и открытие текстового файла

	RWFile h("filename.txt", true);
	std::vector<std::pair<_value_type, _percent_type>> deposit_params = { {11, 1}, {12, 2}, {13, 3} };
	std::vector<std::pair<_value_type, _percent_type>> credit_params = { {21, 4}, {22, 5}, {23, 6} };
	{
		bank b(deposit_params, credit_params, &h);
		std::cout << "create bank\n";
	}

	h.Save();

	//std::cout << h.ReadLine() << h.ReadLine() << h.ReadLine() << h.ReadLine() << std::endl;

}
