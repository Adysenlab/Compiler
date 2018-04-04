#pragma once 
#include "SyntaxTree.hpp"
namespace compiler {
	class Statement : public SyntaxTree
	{
	public:
		Statement(SyntaxTree *tree){
			children.push_back(tree);
		}
	virtual ~Statement()= default;
		
	virtual std::string toCode() const {
		return children[0]->toCode();
	}

	};
}