main : main.o Multip.o
	g++ -o main main.o Multip.o

Multip.o : Multip.h

main.o : Multip.h

.PHNOY : clean
clean:
	rm main *.o