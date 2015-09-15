/*
 * protos.h


 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */


#ifndef PROTOS_H_
#define PROTOS_H_
#include "move.h"

unsigned int  bitCnt(BitMap);
void          dataInit();
void          displayBitmap(BitMap);
void          displayMove(Move &);
BOOLTYPE      doCommand(const char *);
unsigned int  firstOne(BitMap);
void          info();
BOOLTYPE      isAttacked(BitMap &, const unsigned char &);
unsigned int  lastOne(BitMap);
int           movegen(int);
void          readCommands();
BOOLTYPE      readFen(const char *, int);
void          setup();
void          setupFen(char *, char *, char *, char *, int , int );
#endif
