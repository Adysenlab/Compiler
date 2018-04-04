#include <iostream>
#include <memory>
#include "SyntaxTree/SyntaxTree.hpp"

#include "../VersionConfig.h"
extern int yyparse();
extern int yylineno;
extern std::unique_ptr<compiler::SyntaxTree> root;
int main()
{
	int result =yyparse();
	if (result)
	{
		std::cout<< "the input is valid"<<std::endl;
	}else{
		std::cout<< "the input is valid"<<std::endl;
	}

	std::cout<< root -> toCode() <<std::endl;
	std::cout<< "coded -> " << yylineno <<" lines successfully" <<std::endl;

	std::cout << " Version: " << PARSE_VERSION_MAJOR << "." << PARSE_VERSION_MINOR <<std::endl; 
    std::cout << "Usage: plebiscite" << std::endl ;

	return result;
}