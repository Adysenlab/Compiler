#pragma once 
#include "SyntaxTree.hpp"
#include <iostream>
namespace compiler {
	class Statements : public SyntaxTree
	{
	public:
		Statements(SyntaxTree *tree, SyntaxTree *othertree){
			children.push_back(tree);
			children.push_back(othertree);
		}
	virtual ~Statements(){
	}
		
	virtual std::string toCode() const {
		std::string code;
		for(SyntaxTree *node : children){
			if (node != nullptr)
			{
				
			std::cout << "Statements child " <<node <<std::endl;
			code +=node->toCode();
			}
		}
		return code;
	}

	};
}