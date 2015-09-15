/*
 * board.h
 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "defines.h"
#include "move.h"
#include "gameline.h"

struct Board
{
       BitMap whiteKing, whiteQueens, whiteRooks, whiteBishops, whiteKnights, whitePawns;
       BitMap blackKing, blackQueens, blackRooks, blackBishops, blackKnights, blackPawns;
       BitMap whitePieces, blackPieces, occupiedSquares;

       unsigned char nextMove;        // WHITE_MOVE or BLACK_MOVE
       unsigned char castleWhite;     // White's castle status, CANCASTLEOO = 1, CANCASTLEOOO = 2
       unsigned char castleBlack;     // Black's castle status, CANCASTLEOO = 1, CANCASTLEOOO = 2
       int epSquare;                  // En-passant target square after double pawn move
       int fiftyMove;                 // Moves since the last pawn move or capture

       // additional variables:
       int Material;                  // incrementally updated, total material on board,
                                      // in centipawns, from white�s side of view
       int square[64];                // incrementally updated, this array is usefull if we want to
                                      // probe what kind of piece is on a particular square.
       BOOLTYPE viewRotated;          // only used for displaying the board. TRUE or FALSE.

       // storing moves:
       Move moveBuffer[MAX_MOV_BUFF]; // all generated moves of the current search tree are stored in this array.
       int moveBufLen[MAX_PLY];       // this arrays keeps track of which moves belong to which ply
       int endOfGame;                 // index for board.gameLine
       int endOfSearch;               // index for board.gameLine
       GameLineRecord gameLine[MAX_GAME_LINE];

       void init();
       void initFromSquares(int input[64], unsigned char next, int fiftyM, int castleW, int castleB, int epSq);
       void initFromFen(char fen[], char fencolor[], char fencastling[], char fenenpassant[], int fenhalfmoveclock, int fenfullmovenumber);
       void display();
};

#endif /* BOARD_H_ */
