sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

invert: invert.o imageio.o
	g++ -o invert invert.o imageio.o

invert-half: invert-half.o imageio.o
	g++ -o invert-half invert-half.o imageio.o

box: box.o imageio.o
	g++ -o box box.o imageio.o

frame: frame.o imageio.o
	g++ -o frame frame.o imageio.o

scale: scale.o imageio.o
	g++ -o scale scale.o imageio.o

sample.o: sample.cpp imageio.h

invert.o : invert.cpp imageio.h

invert-half.o : invert-half.cpp imageio.h

box.o: box.cpp imageio.h

frame.o: frame.cpp imageio.h

scale.o: scale.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f *.o sample invert invert-half box frame scale
