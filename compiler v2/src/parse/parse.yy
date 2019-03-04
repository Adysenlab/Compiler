%{     /* PARSER */

#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex
%}

%code requires
{
  #include <iostream>
  #include "driver.hh"
  #include "location.hh"
  #include "position.hh"
}

%code provides
{
  namespace parse
  {
    // Forward declaration of the Driver class
    class Driver;

    inline void
    yyerror (const char* msg)
    {
      std::cerr << msg << std::endl;
    }
  }
}



%require "2.4"
%language "C++"
%locations
%defines
%debug
%define api.namespace {parse}
%define parser_class_name {Parser}
%parse-param {Driver &driver}
%lex-param {Driver &driver}
%error-verbose

%union
{
 /* YYLTYPE */
}

/* Tokens */

%token NAME COLON RIGHT_ARROW LEFT_BRACE RIGHT_BRACE SEMICOLON

/* Entry point of grammar */
%start input

%%

input:
    function function_list          {   }

function_list:
    function function_list          {    }
    |%empty                         {      } 
function:
	listset list                   {   }
listset:
	list
list:
    NAME COLON RIGHT_ARROW LEFT_BRACE statements RIGHT_BRACE    {
      
    }
    |%empty                 {    }
statements:
    statements statement    {
            
                            }
    |%empty                     {      }
statement:
    name SEMICOLON      {
       
                        }
name:
    NAME   {
     
            }



%%

namespace parse
{
    void Parser::error(const location&, const std::string& m)
    {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
    }
}
