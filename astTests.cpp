#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ast.h"

TEST_CASE( "BuildAST builds proper tree", "[ast]")
{
	AST tree = AST();
	SECTION ("Build brah") 
	{
	tree.buildAST("(+ (+ 2 1)(+ 3(+ 1 1)))");
	REQUIRE(tree.toString() == "2 1 + 3 1 1 + + +");
	}

	SECTION( "BuildAST builds proper tree2")
	{
		tree.buildAST("(+ (+ 1 2) (+ 3 4) )");
		REQUIRE(tree.toString() == "1 2 + 3 4 + +");
	}

	SECTION( "BuildAST builds proper tree3")
	{
		tree.buildAST("(begin (define a 1) (define b 88) (if (< a b) b a) )");
		REQUIRE(tree.toString() == "a 1 define b 88 define a b < b a if begin");
	}
}



	SECTION( "BuildAST builds proper tree1")
	{
		tree.buildAST("(- ( + 3 (- 6 9 ) ) ( - 4 5 ) )");
		REQUIRE(tree.toString() == "3 6 9 - + 4 5 - -");
	}




