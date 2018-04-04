#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "stringbuilder.h"

class GOL
{

public:
	static std::wstring boardToString(std::vector<std::vector<bool>> &board, int xsize, int ysize);

	static std::vector<std::vector<bool>> strToBoolMatrix(const std::wstring &str, int xsize, int ysize);

	static int mod(int x, int m);

	static int getNeighborCount(std::vector<std::vector<bool>> &board, int x, int y, int xsize, int ysize);



	static bool getDot(std::vector<std::vector<bool>> &board, int x, int y, int xsize, int ysize);


	static void main(std::vector<std::wstring> &args) throw(java::io::FileNotFoundException, java::io::IOException);
};
