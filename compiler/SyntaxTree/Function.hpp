#pragma once 
#include "SyntaxTree.hpp"
#include <iostream>
namespace compiler {
	class Function : public SyntaxTree
	{
	public:
		Function(SyntaxTree *name,SyntaxTree *statements){
			children.push_back(name);
			children.push_back(statements);
		}
	virtual ~Function()= default;
		
	virtual std::string toCode() const {
		std::string code;
		for(SyntaxTree *node : children){
			if (node != nullptr)
			{
				
			std::cout << "Function child " <<node <<std::endl;
			code +=node->toCode();
			}
		}
		return code;
	}

	};
}