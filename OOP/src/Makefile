a.out: App.o main.o CmdManager.o Leinter.o Box.o Flashcard.o
	g++ $^ -o $@
main.o: main.cpp App.hpp CmdManager.hpp Leinter.hpp Box.hpp Flashcard.hpp
	g++ -c $< -o $@
App.o: App.cpp App.hpp CmdManager.hpp Leinter.hpp Box.hpp Flashcard.hpp
	g++ -c $< -o $@
CmdManager.o: CmdManager.cpp CmdManager.hpp Leinter.hpp Box.hpp Flashcard.hpp
	g++ -c $< -o $@
Leinter.o: Leinter.cpp Leinter.hpp Box.hpp Flashcard.hpp
	g++ -c $< -o $@
Box.o: Box.cpp Box.hpp Flashcard.hpp
	g++ -c $< -o $@
Flashcard.o: Flashcard.cpp Flashcard.hpp
	g++ -c $< -o $@
clean:
	rm *.o a.out

