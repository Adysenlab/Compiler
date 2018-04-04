#pragma once 
#include <iostream>
#include "SyntaxTree.hpp"
namespace compiler {
	class Input : public SyntaxTree
	{
	public:
		Input(SyntaxTree *function,SyntaxTree *functions){
			children.push_back(function);
			children.push_back(functions);
		}
	virtual ~Input()= default;
		
	virtual std::string toCode() const {
		std::string code;
		for(SyntaxTree *node : children)
		{
			if (node != nullptr)
			{
				
			std::cout << "Input child " <<node <<std::endl;
			code +=node->toCode();
			}
		}
		return code;
	}

	};
}