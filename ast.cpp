#include "ast.h"

AST::AST()
{
	root = new ASTNode();
	size = 1;
	
	current_ptr = root;
}

void AST::insert(ASTNode* newVal)
{
	
}

int AST::buildAST(string expression)
{
	vector<string> tokens = this->tokenize(expression);
	
	// Skip first element paranthesis
	// Set root of tree to the first atom
	root->str_val = tokens[1];
	
	int token_i = 2;
	int token_size = tokens.size();
	
	while (token_i < token_size)
	{
		if (isdigit(tokens[token_i][0]))// check if is a number
		{
			this->current_ptr->children.push_back(new ASTNode(this->current_ptr, tokens[token_i]));
		}
		else if (tokens[token_i] == "(")
		{
			token_i++;
			this->current_ptr->children.push_back(new ASTNode(this->current_ptr, tokens[token_i]));
			this->current_ptr = this->current_ptr->children[this->current_ptr->children.size() - 1];
		}
		else if (tokens[token_i] == ")")
		{
			this->current_ptr = this->current_ptr->parent;
		}
		else
		{
			this->current_ptr->children.push_back(new ASTNode(this->current_ptr, tokens[token_i]));
		}
		token_i++;
	}
	
	return 0;
}

vector<string> AST::tokenize(string expression)
{
	// TODO	return vector<string>(15);
	vector<string> ret = {"(", "+", "(", "+", "2", "1", ")", "(" , "+", "3", "(", "+", "1", "1", ")", ")", ")"};
	
	return ret;
}

string AST::toString()
{
	return this->toString(this->root);
}

string AST::toString(ASTNode* node)
{
	string str = "";
	ASTNode* temp = node;	
	
	if (temp->children.empty()) 
	{
		return temp->str_val;
	}
	else
	{
		for (int i = 0; i < (int)(temp->children.size()); i++) {
			str += this->toString(temp->children[i]) + " ";
		}
		str += temp->str_val;
		return str;
	}
}

AST::ASTNode::ASTNode()
{
	val = 0.0;
	str_val = "DEF";

	parent = NULL;
	children = vector<ASTNode*>();
}

AST::ASTNode::ASTNode(ASTNode* newParent, double newVal)
{
	val = newVal;
	str_val = "";

	parent = newParent;
	children = vector<ASTNode*>();
}

AST::ASTNode::ASTNode(ASTNode* newParent, string newStr_val)
{
	val = 0.0;
	str_val = newStr_val;

	parent = newParent;
	children = vector<ASTNode*>();
}