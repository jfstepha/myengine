/*
 * protos.h


 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */


#ifndef PROTOS_H_
#define PROTOS_H_

unsigned int  bitCnt(BitMap);
void          dataInit();
void          displayBitmap(BitMap);
unsigned int  firstOne(BitMap);
void          info();
unsigned int  lastOne(BitMap);

BOOLTYPE    doCommand(const char *buf);
void        readCommands();



#endif /* PROTOS_H_ */
