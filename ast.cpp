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

// tokenize
// inString - String to be tokenized
//
// 'tokenize' parses string and removes whitespace and returns vector of strings
std::vector<std::string> tokenize(string inString)
{

	std::vector<std::string> myVector;
	size_t i = 0;
	//tokenize

	while (i < inString.length() ) //parse through expression
	{
		if (inString[i] == ' ') //skip over whitespace
		{
			++i;
		}
		else
		{
			// character is a left/right parentheses, plus, minus, mult, div, equal, 
			if (inString[i] == '(' || inString[i] == ')' || inString[i] == '+' || inString[i] == '*' || inString[i] == '=')
			{
				myVector.push_back(std::string(1, inString[i]));
				++i;
			}
			// < , > , <= , >=
			else if (inString[i] == '>' || inString[i] == '<')
			{
				if (inString[i + 1] == '=')
				{
					if (inString[i == '>'])		myVector.push_back(">=");
					else	myVector.push_back("<=");
					i = i + 2;  //advance two characters
				}
				else
				{
					myVector.push_back(std::string(1, inString[i]));
					++i;
				}
			}
			// < , > , <= , >=

			//  - - - - - - - - -
			else if (inString[i] == '-')
			{
				if (inString[i+1] == ' ')	myVector.push_back(std::string(1, inString[i])); //operator not number
				else
				{
					size_t x = 1;
					size_t y = i+1;
					//continue to parse until end of number
					while (isdigit(inString[y]) || inString[y] == '.' || inString[y] == 'e' || inString[y] == '-')
					{
						++x;
						++y;
					}
					std::string number = inString.substr(i, x); //remove number, possibly complex/decimal
					myVector.push_back(number);
					i = i + x;
				}
			}
			// begin numbers
			else if (isdigit(inString[i]))
			{
				size_t x = 1;
				size_t y = i + 1;
				//continue to parse until end of number
				while (isdigit(inString[y]) || inString[y] == '.' || inString[y] == 'e' || inString[y] == '-')
				{
					++x;
					++y;
				}
				std::string number = inString.substr(i, x); //substring is number, possibly complex/decimal
				myVector.push_back(number);
				i = i + x;
			}
			// end numbers
			else if (isalpha(inString[i]))
			{
				size_t x = 1;
				size_t y = i + 1;
				while (isalpha(inString[y]) && inString[y] != inString.length())
				{
					++y;
					++x;
				}
				std::string symbol = inString.substr(i, x); // substring is symbol
				myVector.push_back(symbol);
				i = i + x;
			}
			else
			{
				std::cout << "Error: Failed to tokenize at location: " << i << std::endl;
			}

		
		}

	} //while loop til end of expression
	return myVector;
} //end function

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