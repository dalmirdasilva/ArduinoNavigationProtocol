g++ -c ../Message/Message.cpp -o message.o -I ../Message/
g++ -c ../Message/AckMessage.cpp -o  ack.o -I ../Message/
g++ -c ../Message/GpsMessage.cpp -o  gps.o -I ../Message/
g++ -c ../Message/GyroscopeMessage.cpp -o  gyro.o -I ../Message/
g++ -c ../Message/RCRawMessage.cpp -o  rc.o -I ../Message/
g++ -c ../Message/SysStatusMessage.cpp -o  sys.o -I ../Message/

g++ test.cpp gyro.o message.o gps.o ack.o rc.o sys.o -I ../Message/ -o test
./test
