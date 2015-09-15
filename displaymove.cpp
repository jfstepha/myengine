#include <iostream>
#include "defines.h"
#include "extglobals.h"

void displayMove(Move &move)
{
       // displays a single move on the console, no disambiguation

       if ((move.getPiec() == WHITE_KING) && (move.isCastleOO()))
       {
              std::cout << "O-O";
              return;
       };
       if ((move.getPiec() == WHITE_KING) && (move.isCastleOOO()))
       {
              std::cout << "O-O-O";
              return;
       };
       if ((move.getPiec() == BLACK_KING) && (move.isCastleOO()))
       {
              std::cout << "O-O";
              return;
       };
       if ((move.getPiec() == BLACK_KING) && (move.isCastleOOO()))
       {
              std::cout << "O-O-O";
              return;
       };

       if ((move.getPiec() == WHITE_ROOK)   || (move.getPiec() == BLACK_ROOK))   std::cout << "R";
       if ((move.getPiec() == WHITE_BISHOP) || (move.getPiec() == BLACK_BISHOP)) std::cout << "B";
       if ((move.getPiec() == WHITE_KNIGHT) || (move.getPiec() == BLACK_KNIGHT)) std::cout << "N";
       if ((move.getPiec() == WHITE_KING)   || (move.getPiec() == BLACK_KING))   std::cout << "K";
       if ((move.getPiec() == WHITE_QUEEN)  || (move.getPiec() == BLACK_QUEEN))  std::cout << "Q";
       if (((move.getPiec() == WHITE_PAWN)  || (move.getPiec() == BLACK_PAWN)) && move.isCapture())
       {
              if (FILES[move.getFrom()] == 1) std::cout << "a";
              if (FILES[move.getFrom()] == 2) std::cout << "b";
              if (FILES[move.getFrom()] == 3) std::cout << "c";
              if (FILES[move.getFrom()] == 4) std::cout << "d";
              if (FILES[move.getFrom()] == 5) std::cout << "e";
              if (FILES[move.getFrom()] == 6) std::cout << "f";
              if (FILES[move.getFrom()] == 7) std::cout << "g";
              if (FILES[move.getFrom()] == 8) std::cout << "h";
       }

       if (move.isCapture()) std::cout << "x" ;

       if (FILES[move.getTosq()] == 1) std::cout << "a";
       if (FILES[move.getTosq()] == 2) std::cout << "b";
       if (FILES[move.getTosq()] == 3) std::cout << "c";
       if (FILES[move.getTosq()] == 4) std::cout << "d";
       if (FILES[move.getTosq()] == 5) std::cout << "e";
       if (FILES[move.getTosq()] == 6) std::cout << "f";
       if (FILES[move.getTosq()] == 7) std::cout << "g";
       if (FILES[move.getTosq()] == 8) std::cout << "h";

       std::cout << RANKS[move.getTosq()];

       if (move.isPromotion())
       {
              if ((move.getProm() == WHITE_ROOK)   || (move.getProm() == BLACK_ROOK))   std::cout << "=R";
              if ((move.getProm() == WHITE_BISHOP) || (move.getProm() == BLACK_BISHOP)) std::cout << "=B";
              if ((move.getProm() == WHITE_KNIGHT) || (move.getProm() == BLACK_KNIGHT)) std::cout << "=N";
              if ((move.getProm() == WHITE_KING)   || (move.getProm() == BLACK_KING))   std::cout << "=K";
              if ((move.getProm() == WHITE_QUEEN)  || (move.getProm() == BLACK_QUEEN))  std::cout << "=Q";
       }
       std::cout.flush();
       return;
}
