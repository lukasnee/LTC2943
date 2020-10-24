all:
	g++ -o LTC2943.exe main.cpp i2c.cpp LTC2943.cpp 
	./LTC2943.exe