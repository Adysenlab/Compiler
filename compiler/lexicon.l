%option noyywrap
%{
    #include "parser.hh"
    #include "SyntaxTree/Includes.hpp"
    #include <memory>
%}
alpha       [a-zA-Z]
name        {alpha}([0-9]*{alpha}*)+
whitespace  [ \r\f\v\t]
linefeed    \n
%%
{name}          {return NAME;}
":"             {return COLON;}
";"				{return SEMICOLON;}
"->"            {return RIGHT_ARROW;}
"{"             {return LEFT_BRACE;}
"}"             {return RIGHT_BRACE;}

{whitespace}
{linefeed}      ++yylineno;

%%
