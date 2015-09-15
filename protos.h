/*
 * protos.h


 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */


#ifndef PROTOS_H_
#define PROTOS_H_
#include "board.h"
#include "move.h"

unsigned int  bitCnt(BitMap);
void          dataInit();
void          displayBitmap(BitMap);
void          displayMove(Move &);
BOOLTYPE      doCommand(const char *);
unsigned int  firstOne(BitMap);
void          info();
BOOLTYPE      isAttacked(BitMap &, const unsigned char &);
BOOLTYPE      isValidTextMove(const char *, Move &);
BOOLTYPE      isOtherKingAttacked();
BOOLTYPE      isOwnKingAttacked();
unsigned int  lastOne(BitMap);
void          makeBlackPromotion(unsigned int, unsigned int &);
void          makeCapture(unsigned int &, unsigned int &);
void          makeMove(Move &);
void          makeWhitePromotion(unsigned int, unsigned int &);
int           movegen(int);
U64           perft(int, int);
void          readCommands();
BOOLTYPE      readFen(const char *, int);
void          setup();
void          setupFen(char *, char *, char *, char *, int , int );
void          unmakeBlackPromotion(unsigned int, unsigned int &);
void          unmakeCapture(unsigned int &, unsigned int &);
void          unmakeMove(Move &);
void          unmakeWhitePromotion(unsigned int, unsigned int &);
#endif
