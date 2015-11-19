main : main.o Sales_data.o
	g++ -o main main.o Sales_data.o

main.o : Sales_data.h
#	g++ -c main.cpp

Sales_data.o : Sales_data.h
#	g++ -o Sales_data.cpp

.PHONY : clean
clean:
	rm main *.o