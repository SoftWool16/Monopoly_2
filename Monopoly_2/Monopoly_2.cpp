#include <iostream>
#include <fstream>
#include <string>

#include "ReadWriteBase.h"
#include "LogFile.h"

int main() {
	// создание и открытие текстового файла
	
	RWFile h("filename.txt", true);
	h.WrileLine("1line");
	h.WrileLine("2line");
	h.WrileLine("3line");

	h.Save();

	std::cout << h.ReadLine() << h.ReadLine() << h.ReadLine() << h.ReadLine() << std::endl;

}
