#ifndef IOTESTSUITE_H
#define IOTESTSUITE_H
#include <sstream>
#include <string>
#include <iostream>

class IOCapture
{
private:
  std::stringstream cout_stream;
  std::streambuf *buffer;
public:
  IOCapture();
  ~IOCapture();
  void startCapture();
  void stopCapture();
  std::string output();
  std::string outputFlush();
};
#endif
