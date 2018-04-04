%code requires {
    #include "SyntaxTree/SyntaxTree.hpp"
}

%{
    #include <iostream>
    #include <memory>
    #include "SyntaxTree/Includes.hpp"
    void yyerror(char *);
    extern char * yytext;
    int yylex(void);
    std::unique_ptr<compiler::SyntaxTree> root;

%}

%token NAME COLON RIGHT_ARROW LEFT_BRACE RIGHT_BRACE SEMICOLON

%define api.value.type {compiler::SyntaxTree *}

%start input 
%%

input:
    function function_list          {   root.reset(new compiler::Input($1, $2)); }

function_list:
    function function_list          {   $$ = $1 ; }
    |%empty                         {    $$ =nullptr;   } 
function:
	listset list                   {   $$ = $1 ; }
listset:
	list
list:
    NAME COLON RIGHT_ARROW LEFT_BRACE statements RIGHT_BRACE    {
            $$ =new compiler::Function($1, $5);
    }
    |%empty                 {    $$ =nullptr;   }
statements:
    statements statement    {
            $$ =new compiler::Statements($2, $1);
                            }
    |%empty                     {    $$ =nullptr;   }
statement:
    name SEMICOLON      {
        $$ = new compiler::Statement($1);
        std::cout << "Created Statement"<<std::endl;
                        }
name:
    NAME   {
      $$  = new compiler::Name (yytext); 
            }


%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


