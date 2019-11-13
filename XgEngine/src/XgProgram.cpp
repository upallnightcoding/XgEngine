#include "XglProgram.h"



XglProgram::XglProgram()
{
	program = "";
}


XglProgram::~XglProgram()
{
}

/*****************************************************************************
addProgramLine() -
*****************************************************************************/
void XglProgram::addProgramLine(string code)
{
	program = program + SPACE_CHAR + code;
}

/*****************************************************************************
skipBlanks() - Skips white space between tokens.  If a '#' is detected, then
it is taken as a comment.  All characters between the '#' are skipped.  The
ending '#' is also skipped and the skipping of blanks then continues.
*****************************************************************************/
void XglProgram::skipBlanks()
{
	bool skipping = true;

	while (skipping) {
		while ((!isEop()) && (isspace(getCurrentChar()))) {
			moveToNextChar();
		}

		if ((!eop) && (getCurrentChar() == POUND_CHAR)) {
			moveToNextChar();

			while ((!eop) && (getCurrentChar() != POUND_CHAR)) {
				moveToNextChar();
			}

			if (!eop) {
				moveToNextChar();
			}
		}
		else {
			skipping = false;
		}
	}

}

/*****************************************************************************
isChar() - Returns true if the current active program character is the
same as the parameter passed.  It returns false otherwise.
*****************************************************************************/
bool XglProgram::isChar(char character)
{
	return(character == getCurrentChar());
}

/*****************************************************************************
nextChar() - Skips to the next character in the source code.
*****************************************************************************/
void XglProgram::moveToNextChar()
{
	if (!eop) {
		currentChar++;

		if (currentChar >= program.length()) {
			eop = true;
		}
	}
}

/*****************************************************************************
getCurrentChar() - Returns the current active character in the source code.
*****************************************************************************/
char XglProgram::getCurrentChar()
{
	return(program.at(currentChar));
}

/*****************************************************************************
isEop() - Returns the value of the end-of-program pointer.  
*****************************************************************************/
bool XglProgram::isEop()
{
	return(eop);
}
