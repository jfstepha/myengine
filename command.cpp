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
			cout << "  uci      : tell the engine to switch to UCI mode." << endl;
			cout << "  d        : display the board" << endl ;
			cout << "  r        : rotate the board" << endl;
			cout << "  black    : black to move" << endl;
			cout << "  white    : white to move" << endl;
			cout << "  info     : dump out some information" << endl;
			cout << "  new      : new" << endl;
		}
		else if( command == "uci" ) {
			cmdUCI();
		}
		else if( command == "quit" ) {
			cout << "quitting" << endl;
			return;
		}
		else if( command == "d") {
			cout << "board:" << endl;
			board.display();
		}
		else if( command == "black" ) {
			board.nextMove = BLACK_MOVE;
		}
		else if( command == "info" ) {
			info();
		}
		else if( command == "new" ) {
			dataInit();
			board.init();
			board.display();
		}
		else if( command == "r" ) {
			board.viewRotated = !board.viewRotated;
			board.display();
		}
		else if( command == "white" ) {
			board.nextMove = WHITE_MOVE;
		} else {
			cout << " command not implemented:" << command << ", type 'help' for more info" << endl;
		}
	}
}
