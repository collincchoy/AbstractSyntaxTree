#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ast.h"

TEST_CASE( "BuildAST builds proper tree", "[ast]")
{
	AST tree = AST();
	tree.buildAST("(+ (+ 2 1)(+ 3(+ 1 1)))");
	REQUIRE(tree.toString() == "2 1 + 3 1 1 + + +");
}
