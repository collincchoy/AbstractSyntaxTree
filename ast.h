#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class AST {
	public:
		typedef struct ASTNode {
			double val;
			string str_val;

			ASTNode* parent;
			vector<ASTNode*> children;
			
			ASTNode();
			ASTNode(ASTNode* newParent, double newVal);
			ASTNode(ASTNode* newParent, string newStr_val);
		} ASTNode;
	
		AST();
		int buildAST(string expression);
		string toString();
		
		ASTNode* root;
		int size;
		ASTNode* current_ptr;
		
	private:
		void insert(ASTNode* newVal);
		string toString(ASTNode* node);
		vector<string> tokenize(string expression);
};