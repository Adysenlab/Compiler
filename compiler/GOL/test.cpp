#include "test.h"

std::wstring GOL::boardToString(std::vector<std::vector<bool>> &board, int xsize, int ysize)
{
	StringBuilder *sb = new StringBuilder(); // used to print out the board at the end
	for (int i = 0;i < xsize;i++)
	{
		for (int j = 0;j < ysize;j++)
		{
			if (board [i][j])
			{
				sb->append(L'*');
			}
			else
			{
				sb->append(L' ');
			}
		}
	sb->append(L"\n");
	}
	return sb->toString();
}

std::vector<std::vector<bool>> GOL::strToBoolMatrix(const std::wstring &str, int xsize, int ysize)
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: boolean [][] board = new boolean[xsize][ysize];
	std::vector<std::vector<bool>> board = RectangularVectors::ReturnRectangularBoolVector(xsize, ysize); // converts an input string into the
	for (int i = 0;i < xsize; i++)
	{ // boolean[][] used internally
		for (int j = 0; j < ysize; j++)
		{
			board[i][j] = str[(i*xsize) + j] != L'0';
		}
	}
	return board;
}

int GOL::mod(int x, int m)
{ // deals with java's % returning negative vals for
	m = std::abs(m); // negative inputs
	return (x % m + m) % m;
}

int GOL::getNeighborCount(std::vector<std::vector<bool>> &board, int x, int y, int xsize, int ysize)
{
	int nc = 0; // this function rather messily counts up the neighbors

	if (board[mod(x + 1,xsize)][y])
	{
		nc++;
	}
	if (board[mod(x + 1,xsize)][mod(y + 1, ysize)])
	{
		nc++;
	}
	if (board[x][mod(y + 1,ysize)])
	{
		nc++;
	}
	if (board[x][mod(y - 1,ysize)])
	{
		nc++;
	}
	if (board[mod(x + 1,xsize)][mod(y - 1,ysize)])
	{
		nc++;
	}
	if (board[mod(x - 1,xsize)][y])
	{
		nc++;
	}
	if (board[mod(x - 1,xsize)][mod(y - 1,ysize)])
	{
		nc++;
	}
	if (board[mod(x - 1,xsize)][mod(y + 1,ysize)])
	{
		nc++;
	}
	return nc;
}

bool GOL::getDot(std::vector<std::vector<bool>> &board, int x, int y, int xsize, int ysize)
{
	// this function applies the rules of the game on one square

	return board[x][y] && getNeighborCount(board, x,y,xsize,ysize) == 2 || getNeighborCount(board,x,y,xsize,ysize) == 3;
}

void GOL::main(std::vector<std::wstring> &args) throw(java::io::FileNotFoundException, java::io::IOException)
{
	int xsize = std::stoi(args[0]); // takes board size off command line
	int ysize = std::stoi(args[1]);
	int gen = std::stoi(args[2]); // number of generations
	FileReader *fr = new FileReader(args[3]); // will read in board from a file
	BufferedReader *br = new BufferedReader(fr);
	StringBuilder *sb = new StringBuilder();
	std::wstring line = std::wstring(br->readLine());
	while (line != L"")
	{ // reading file
		sb->append(line);
		line = br->readLine();
	}
	std::wstring s = sb->toString();
	std::vector<std::vector<bool>> board = strToBoolMatrix(s,xsize,ysize); // this is the game board
	for (int i = 0; i < gen; i++)
	{ // loops through the generations
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: boolean[][] next = new boolean[xsize][ysize];
		std::vector<std::vector<bool>> next = RectangularVectors::ReturnRectangularBoolVector(xsize, ysize); // empty board
		for (int j = 0;j < xsize;j++)
		{ // loops through x-axis for computing the next generation
			for (int k = 0; k < ysize; k++)
			{ // loops through y-axis
				next[j][k] = getDot(board,j,k,xsize,ysize);
			}
		}
		board = next; // use the 'next' array as the new 'board' array
	}
	std::wcout << boardToString(board,xsize,ysize) << std::endl; // prints the board
}
