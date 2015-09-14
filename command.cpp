/*
 * command.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */

#include <iostream>
#include <string>
#include "defines.h"
#include "protos.h"
#include "extglobals.h"
#include "board.h"
#include "globals.h"

using namespace std;
/*********************************************************************/
void listOptions() {
/*********************************************************************/
	cout << "option stupid type spin default 1 min 1 max 128" << endl;
}
/*********************************************************************/
void cmdUCI(){
/*********************************************************************/
	cout << "id " << PROG_VER << endl;
	cout << "id author Jon Stephan" << endl;
	listOptions();
	cout << "uciok" << endl;

}
/*********************************************************************/
void readCommands()
/*********************************************************************/
{
	string command;
	while(1){

		cin >> command;

		cout << "##Read: " << command << "." << endl;

		/* parse command */
		if( command == "help" ) {
			cout << "help:" << endl;
			cout << "  uci : tell the engine to switch to UCI mode." << endl;
			cout << "  d   : display the board" << endl ;
		}
		if( command == "uci" ) {
			cmdUCI();
		}
		if( command == "quit" ) {
			cout << "quitting" << endl;
			return;
		}
		if( command == "d") {
			cout << "board:" << endl;
			board.display();
		}
	}
}
