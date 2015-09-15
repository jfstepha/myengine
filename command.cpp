/*
 * command.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */
#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE 1
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "defines.h"
#include "protos.h"
#include "extglobals.h"
#include "board.h"
#include "globals.h"
#include "timer.h"

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
    string userinput;
    int number;
    int i;
    Move move;
    Timer timer;
    U64 msStart;
    U64 msStop;
    U64 perftcount;

	while(1){

		cin >> command;

		cout << "##Read: " << command << "." << endl;

		/* parse command */
		if( command == "help" ) {
			cout << "help:" << endl;
			cout << "  uci       : tell the engine to switch to UCI mode." << endl;
			cout << "  d         : display the board" << endl ;
			cout << "  r         : rotate the board" << endl;
			cout << "  black     : black to move" << endl;
			cout << "  white     : white to move" << endl;
			cout << "  info      : dump out some information" << endl;
			cout << "  new       : new" << endl;
            cout << "  readfen   : input a fen position" << endl;
            cout << "  moves     : show all legal moves" << endl;
            cout << "  game      : show all game moves" << endl;
            cout << "  move      : do a move " << endl;
            cout << "  perft <n> : calculate raw number of nodes from here, depth n " << endl;
            cout << "  undo      : take back last move" << endl;
        /*---------------------------------------------------------*/
		} else if( command == "uci" ) {
			cmdUCI();
        /*---------------------------------------------------------*/
		} else if( command == "quit" ) {
			cout << "quitting" << endl;
			return;
        /*---------------------------------------------------------*/
		} else if( command == "d") {
			cout << "board:" << endl;
			board.display();
        /*---------------------------------------------------------*/
		} else if( command == "black" ) {
			board.nextMove = BLACK_MOVE;
        /*---------------------------------------------------------*/
		} else if( command == "info" ) {
			info();
        /*---------------------------------------------------------*/
		} else if( command == "new" ) {
			dataInit();
			board.init();
			board.display();
        /*---------------------------------------------------------*/
		} else if( command == "r" ) {
			board.viewRotated = !board.viewRotated;
			board.display();
        /*---------------------------------------------------------*/
		} else if( command == "white" ) {
			board.nextMove = WHITE_MOVE;
        /*---------------------------------------------------------*/
		} else if( !command.find("readfen") ) {
			cout << "reading fen..." << endl;
			cin >> userinput;
			cin >> number;
			cout << "  filename: " << userinput << endl;
			cout << "  number: " << number << endl;
			board.init();
			readFen(userinput.c_str(), 1);
        /*---------------------------------------------------------*/
		} else if ( command == "moves" ) {
			  board.moveBufLen[0] = 0;
			  board.moveBufLen[1] = movegen(board.moveBufLen[0]);
			  cout << endl << "moves from this position:" << endl;
              for (i = board.moveBufLen[0]; i < board.moveBufLen[1]; i++) {
                  makeMove(board.moveBuffer[i]);
	              if (isOtherKingAttacked())             {
                      unmakeMove(board.moveBuffer[i]);
                  } else {
                      cout << i+1 << ". " ;
		              displayMove(board.moveBuffer[i]);
		              cout << endl;
		              unmakeMove(board.moveBuffer[i]);
		          }
		      }
			  for (i = board.moveBufLen[0]; i < board.moveBufLen[1]; i++) {
				   cout << i+1 << ". " ;
				   displayMove(board.moveBuffer[i]);
				   cout << std::endl;
			  }
        /*---------------------------------------------------------*/
		} else if (command == "move") {
			cin >> userinput;

            // generate the pseudo-legal move list
            board.moveBufLen[0] = 0;
            board.moveBufLen[1] = movegen(board.moveBufLen[0]);

            if (isValidTextMove(userinput.c_str(), move)) {      // check to see if the user move is also found in the pseudo-legal move list
                makeMove(move);

                if (isOtherKingAttacked()){             // post-move check to see if we are leaving our king in check
                    unmakeMove(move);
                    cout << "    invalid move, leaving king in check: " << userinput << std::endl;
                } else {
                    board.endOfGame++;
                    board.endOfSearch = board.endOfGame;
                    board.display();
                }
            } else {
		        cout << "    move is invalid or not recognized: " << userinput << endl;
		    }
        /*---------------------------------------------------------*/
		} else if (command == "perft") {
                   cin >> number;
                   cout << "    starting perft " << number << "..." << endl;
                   timer.init();
                   board.moveBufLen[0] = 0;

     #ifdef WINGLET_DEBUG_PERFT
                   ICAPT = 0;
                   IEP = 0;
                   IPROM = 0;
                   ICASTLOO = 0;
                   ICASTLOOO = 0;
                   ICHECK = 0;
     #endif

                   msStart = timer.getms();
                   perftcount = perft(0, number);
                   msStop = timer.getms();

                   cout << "nodes        = " << perftcount << ", " << msStop - msStart << " ms, ";
                   if ((msStop - msStart) > 0)
                          cout << (perftcount/(msStop - msStart)) << " knods/s";
                   cout << endl;

     #ifdef WINGLET_DEBUG_PERFT
                   std::cout << "captures     = " << ICAPT << std::endl;
                   std::cout << "en-passant   = " << IEP << std::endl;
                   std::cout << "castlings    = " << ICASTLOO + ICASTLOOO << std::endl;
                   std::cout << "promotions   = " << IPROM << std::endl;
                   std::cout << "checks       = " << ICHECK << std::endl;
     #endif
        /*---------------------------------------------------------*/
		} else if (command == "undo") {
                   if (board.endOfGame) {
                          unmakeMove(board.gameLine[--board.endOfGame].move);
                          board.endOfSearch = board.endOfGame;
                          board.display();
                   } else {
                          cout << "already at start of game" << endl;
                   }
        /*---------------------------------------------------------*/
		} else if ( command == "game") {
            if (board.endOfGame) {
               for (i = 0 ; i < board.endOfGame ; i++) {
                  cout << i+1 << ". ";
                  displayMove(board.gameLine[i].move);
                  cout << endl;
               }
            }
            else {
               cout << "there are no game moves" << endl;
            }
        /*---------------------------------------------------------*/
		} else {
			cout << " command not implemented:" << command << ", type 'help' for more info" << endl;
		}
		getline( cin, command);
	}
}
