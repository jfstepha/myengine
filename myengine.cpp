//============================================================================
// Name        : myengine.cpp
// Author      : Jon Stephan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "defines.h"
#include "protos.h"
#include "extglobals.h"

using namespace std;

int main(void) {
	cout << PROG_VER << endl;
#ifdef WINGLET_DEBUG_PERFT
   std::cout << "WINGLET_DEBUG_PERFT defined" << std::endl;
#endif
#ifdef WINGLET_DEBUG_MOVES
   std::cout << "WINGLET_DEBUG_MOVES defined" << std::endl;
#endif
#ifdef WINGLET_VERBOSE_EVAL
   std::cout << "WINGLET_VERBOSE_EVAL defined" << std::endl;
#endif
#ifdef WINGLET_DEBUG_EVAL
   std::cout << "WINGLET_DEBUG_EVAL defined" << std::endl;
#endif
	dataInit();
	board.searchDepth = 2;
	readCommands();
	cout << "Done." << endl;
	return EXIT_SUCCESS;
}
