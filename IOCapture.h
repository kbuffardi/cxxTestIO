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
  std::streambuf *cin_buffer;
  std::stringstream m_input;
  void releaseCin();
  void startCapture();
  void stopCapture();
public:
  IOCapture();
  ~IOCapture();
  std::string output();
  std::string outputFlush();
  void inputFeed(std::string);
};
#endif
