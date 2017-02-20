#include "ast.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	AST tree = AST();
	tree.buildAST("haha");
	//tree.root->children.push_back(new AST::ASTNode(tree.root, "1"));
	//tree.size++;
	//tree.root->children.push_back(new AST::ASTNode(tree.root, "2"));
	//tree.size++;
	//tree.root->children[0]->children.push_back(new AST::ASTNode(tree.root, "3"));
	
	cout << tree.toString() << endl;
	
	cout << "hello" << endl;
	return 0;
}