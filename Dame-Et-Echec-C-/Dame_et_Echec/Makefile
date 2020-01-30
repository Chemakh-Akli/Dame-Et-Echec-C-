all:test

test:main.o Jeu.o JeuDame.o JeuDameAnglaise.o JeuEchec.o Piece.o PieceDame.o Pion.o PionAnglaise.o Dame.o DameAnglaise.o PieceEchec.o PionEchec.o Tour.o Fou.o Chevalier.o Reine.o Roi.o
	g++ -std=c++11 -o test main.o Jeu.o JeuDame.o JeuDameAnglaise.o JeuEchec.o Piece.o PieceDame.o Pion.o PionAnglaise.o Dame.o DameAnglaise.o PieceEchec.o PionEchec.o Tour.o Fou.o Chevalier.o Reine.o Roi.o

main.o: main.cpp Jeu.hpp
	 g++ -std=c++11 -c main.cpp

Piece.o: Piece.cpp Piece.hpp
		g++ -std=c++11 -c Piece.cpp

PieceDame.o: PieceDame.cpp PieceDame.hpp Piece.hpp
	 g++ -std=c++11 -c PieceDame.cpp

Pion.o: Pion.cpp Pion.hpp PieceDame.hpp
	g++ -std=c++11 -c Pion.cpp

PionAnglaise.o: PionAnglaise.cpp PionAnglaise.hpp PieceDame.hpp
	g++ -std=c++11 -c PionAnglaise.cpp

Dame.o: Dame.cpp Dame.hpp PieceDame.hpp
	g++ -std=c++11 -c Dame.cpp

DameAnglaise.o: DameAnglaise.cpp DameAnglaise.hpp PieceDame.hpp
	g++ -std=c++11 -c DameAnglaise.cpp

PieceEchec.o: PieceEchec.cpp PieceEchec.hpp Piece.hpp
		g++ -std=c++11 -c PieceEchec.cpp

PionEchec.o: PionEchec.cpp PionEchec.hpp PieceEchec.hpp
	g++ -std=c++11 -c PionEchec.cpp

Tour.o: Tour.cpp Tour.hpp PieceEchec.hpp
	g++ -std=c++11 -c Tour.cpp

Fou.o: Fou.cpp Fou.hpp PieceEchec.hpp
	g++ -std=c++11 -c Fou.cpp

Chevalier.o: Chevalier.cpp Chevalier.hpp PieceEchec.hpp
		g++ -std=c++11 -c Chevalier.cpp

Reine.o: Reine.cpp Reine.hpp PieceEchec.hpp
	g++ -std=c++11 -c Reine.cpp

Roi.o: Roi.cpp Roi.hpp PieceEchec.hpp
	g++ -std=c++11 -c Roi.cpp

Jeu.o: Jeu.cpp Jeu.hpp Piece.hpp
	g++ -std=c++11 -c Jeu.cpp

JeuDame.o: JeuDame.cpp JeuDame.hpp Jeu.hpp
	g++ -std=c++11 -c JeuDame.cpp

JeuDameAnglaise.o: JeuDameAnglaise.cpp JeuDameAnglaise.hpp Jeu.hpp
	g++ -std=c++11 -c JeuDameAnglaise.cpp


JeuEchec.o: JeuEchec.cpp JeuEchec.hpp Jeu.hpp
	g++ -std=c++11 -c JeuEchec.cpp



clean:
	rm *.o
