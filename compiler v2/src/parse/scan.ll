%{                                                            /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"

/*  Defines some macros to update locations */


#define STEP()                                      \
  do {                                              \
    driver.location_->step ();                      \
  } while (0)

#define COL(Col)				                    \
  driver.location_->columns (Col)

#define LINE(Line)				                    \
  do{						                        \
    driver.location_->lines (Line);		            \
 } while (0)

#define YY_USER_ACTION				                \
  COL(yyleng);


typedef parse::Parser::token token;
typedef parse::Parser::token_type token_type;



%}

/*

`yywrap'
if unset (i.e., `%option noyywrap'), makes the scanner not call `yywrap()' 
upon an end-of-file, but simply assume that there are no more files to scan 
(until the user points yyin at a new file and calls `yylex()' again).

`yylineno'
directs flex to generate a scanner that maintains the 
number of the current line read from its input in the global 
variable yylineno. This option is implied by `%option lex-compat'.

`stack'
enables the use of start condition stacks (see Start Conditions above).

`never-interactive'
instructs flex to generate a scanner which never considers 
its input "interactive" (again, no call made to `isatty())'. 
This is the opposite of `always-' interactive.

Three options take string-delimited values, offset with '=':

%option outfile="ABC"
is equivalent to `-oABC', and

%option prefix="XYZ"
is equivalent to `-PXYZ'.

A number of options are available for lint purists who want to suppress the appearance of unneeded routines in the generated scanner. Each of the following, if unset, results in the corresponding routine not appearing in the generated scanner:

input, unput
yy_push_state, yy_pop_state, yy_top_state
yy_scan_buffer, yy_scan_bytes, yy_scan_string
(though `yy_push_state()' and friends won't appear anyway unless you use `%option stack').


*/
%option debug
%option c++
%option noyywrap 
%option never-interactive
%option yylineno
%option nounput
%option batch
%option prefix="parse"

/*
%option stack
*/

/* Abbreviations.  */


alpha       [a-zA-Z]
name        {alpha}([0-9]*{alpha}*)+
blank   [ \r\f\v\t]
eol     \n
%%

 /* The rules.  */
%{
  STEP();
%}



{name}          { std::cout <<*driver.location_ << "variable named: " << yytext << std::endl; return parse::Parser::token::NAME;}
":"             {return token::COLON;}
";"				{return parse::Parser::token::SEMICOLON;}
"->"            {return token::RIGHT_ARROW;}
"{"             {return token::LEFT_BRACE;}
"}"             {return token::RIGHT_BRACE;}

{blank}       STEP();

{eol}         LINE(yyleng);

.             {
                std::cerr << *driver.location_ << " Unexpected token : "
                                              << *yytext << std::endl;
                driver.error_ = (driver.error_ == 127 ? 127
                                : driver.error_ + 1);
                STEP ();
              }

%%


/*

   CUSTOM C++ CODE

*/

namespace parse
{

    Scanner::Scanner()
    : parseFlexLexer()
    {
    }

    Scanner::~Scanner()
    {
    }

    void Scanner::set_debug(bool b)
    {
        yy_flex_debug = b;
    }
}

#ifdef yylex
# undef yylex
#endif

int parseFlexLexer::yylex()
{
  std::cerr << "call parsepitFlexLexer::yylex()!" << std::endl;
  return 0;
}
