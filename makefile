CC = g++
CFLAGS = -c
LFLAGS = -w


all: stoGpsDistance 

stoGpsDistance: stoGpsDistance.cpp LocationGPS.cpp
	$(CC) $(LFLAGS) -o $@ $^ --std=gnu++11 
	
clean:
	rm stoGpsDistance 

