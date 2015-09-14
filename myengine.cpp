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
#include "globals.h"

using namespace std;

int main(void) {
	cout << PROG_VER << endl;
	readCommands();
	cout << "Done." << endl;
	return EXIT_SUCCESS;
}
