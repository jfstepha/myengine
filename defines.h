/*
 * defines.h
 *
 *  Created on: Sep 14, 2015
 *      Author: jfstepha
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define PROG_VER "myengine version 0.0"
//#define WINGLET_DEBUG_PERFT
//#define WINGLET_DEBUG_MOVES


#define MAX_CMD_BUFF 256
#define MAX_MOV_BUFF 4096    // Number of moves that we can store (all plies)
#define MAX_PLY      64      // Search depth
#define MAX_GAME_LINE    1024   // Number of moves in the (game + search) line that we can store


typedef int BOOLTYPE;
typedef unsigned long long U64;
typedef unsigned long long BitMap;
typedef short SHORTINT;
typedef unsigned short USHORTINT;
typedef int BOOLTYPE;

#endif /* DEFINES_H_ */
