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
		if( !command.find( "help" ) ) {
			cout << "help:" << endl;
			cout << "  uci : tell the engine to switch to UCI mode.";
		}
		if( !command.find("uci")) {
			cmdUCI();
		}
		if( !command.find("quit")) {
			cout << "quitting" << endl;
			return;
		}
	}
}
