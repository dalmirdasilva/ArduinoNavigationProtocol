g++ -c ../Message/Message.cpp -o message.o -I ../Message/
g++ -c ../Message/GyroscopeMessage.cpp -o  gyro.o -I ../Message/
g++ test.cpp gyro.o message.o -I ../Message/ -o test
./test
