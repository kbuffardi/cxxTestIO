#ifndef IOCAPTURE_H
#define IOCAPTURE_H
#include <sstream>
#include <string>
#include <iostream>

class IOCapture
{
private:
  std::stringstream m_capture;
  std::streambuf *cout_buffer;
  void startCapture();
  void stopCapture();
public:
  IOCapture();
  ~IOCapture();
  std::string output();
  std::string outputFlush();
};
#endif
