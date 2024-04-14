#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _program 1              // program
#define _id 2                   // id
#define _semicolon 3            // ;
#define _period 4               // .
#define _var 5                  // var
#define _colon 6                // :
#define _integer 7              // integer
#define _char 8                 // char   
#define _begin 9                // begin
#define _end 10                 // end
#define _comma 11               // ,
#define _assign 12              // :=
#define _if 13                  // if
#define _then 14                // then
#define _else 15                // else
#define _while 16               // while
#define _do 17                  // do
#define _read 18                // read
#define _readln 19              // readln
#define _write 20               // write
#define _writeln 21             // writeln
#define _opening_bracket 22     // (
#define _closing_bracket 23     // )
#define _opadd 24               // opadd
#define _oprel 25               // oprel
#define _opmul 26               // opmul
#define _nb 27                  // nb

typedef FILE file;

char current_char;
char buffer[8] = {0};
int buffer_length = 0;

void accept(int syntax_unit)
{
    printf("%i\n", syntax_unit);
    memset(buffer, 0, sizeof(buffer));
    buffer_length = 0;
}
void error(const char* string)
{
    printf(string);
    exit(1);
}

void main(int argc, char* argv[])
{
    if (argc == 1) error("Error: no file specified.");
    file* file = fopen(argv[1], "r");
    if (!file) error("Error: could not open file.");
    while (fread(&current_char, sizeof(char), 1, file)) {
        switch (current_char) {
            case (';'):
                if (!buffer_length) accept(_semicolon);
                else error("Error: invalid syntax.");
            break;
            case ('.'):
                if (!buffer_length) accept(_period);
                else error("Error: invalid syntax.");
            break;
            case (':'):
                if (!buffer_length) accept(_colon);
                else error("Error: invalid syntax.");
            break;
            case (','):
                if (!buffer_length) accept(_comma);
                else error("Error: invalid syntax.");
            break;
            case ('('):
                if (!buffer_length) accept(_opening_bracket);
                else error("Error: invalid syntax.");
            break;
            case (')'):
                if (!buffer_length) accept(_closing_bracket);
                else error("Error: invalid syntax.");
            break;
            case (' '):
                if (buffer_length) error("Error: invalid syntax.");
            break;
            case ('\n'):
                if (buffer_length) error("Error: invalid syntax.");
            break;
            default:
                buffer[buffer_length++] = current_char;
                if (buffer_length == 8) error("Error: invalid syntax.");
                else if (!strcmp(buffer, "program")) accept(_program);
                else if (!strcmp(buffer, "id")) accept(_id);
                else if (!strcmp(buffer, "var")) accept(_var);
                else if (!strcmp(buffer, "integer")) accept(_integer);
                else if (!strcmp(buffer, "char")) accept(_char);
                else if (!strcmp(buffer, "begin")) accept(_begin);
                else if (!strcmp(buffer, "end")) accept(_end);
                else if (!strcmp(buffer, ":=")) accept(_assign);
                else if (!strcmp(buffer, "if")) accept(_if);
                else if (!strcmp(buffer, "then")) accept(_then);
                else if (!strcmp(buffer, "else")) accept(_else);
                else if (!strcmp(buffer, "while")) accept(_while);
                else if (!strcmp(buffer, "do")) accept(_do);
                else if (!strcmp(buffer, "read")) accept(_read);
                else if (!strcmp(buffer, "readln")) accept(_readln);
                else if (!strcmp(buffer, "write")) accept(_write);
                else if (!strcmp(buffer, "writeln")) accept(_writeln);
                else if (!strcmp(buffer, "opadd")) accept(_opadd);
                else if (!strcmp(buffer, "oprel")) accept(_oprel);
                else if (!strcmp(buffer, "opmul")) accept(_opmul);
                else if (!strcmp(buffer, "nb")) accept(_nb);
            break;
        }
    }
    if (buffer_length) error("Error: invalid syntax.");
    else printf("Conversion successful.");
}
