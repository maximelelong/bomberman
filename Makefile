monprog: main.o Game.o Terrain.o Case.o GameElement.o Player.o
	g++ -o monprog main.o Game.o Terrain.o Case.o GameElement.o Player.o -lsfml-graphics -lsfml-window -lsfml-system



Game.o: Game.cpp Terrain.hpp Case.hpp Player.hpp
	gcc -c Game.cpp -lsfml-graphics -lsfml-window -lsfml-system

Terrain.o: Terrain.cpp Case.hpp
	g++ -c Terrain.cpp -lsfml-graphics -lsfml-window -lsfml-system

Case.o: Case.cpp GameElement.hpp
	g++ -c Case.cpp -lsfml-graphics -lsfml-window -lsfml-system

GameElement.o: GameElement.cpp Displayable.hpp
	g++ -c GameElement.cpp -lsfml-graphics -lsfml-window -lsfml-system

Player.o: Player.cpp Terrain.hpp
	g++ -c Player.cpp -lsfml-graphics -lsfml-window -lsfml-system




main.o: main.cpp Game.hpp Terrain.hpp Case.hpp Player.hpp GameElement.hpp
	g++ -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system



clean:
	rm -f *.o


vclean: clean
	rm -f monprog