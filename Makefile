main: main.o imageio.o tasks.o
	g++ -o main main.o imageio.o tasks.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

main.o: main.cpp imageio.h

tasks.o: tasks.cpp

sample.o: sample.cpp imageio.h

clean:
	rm -f *.o main sample
