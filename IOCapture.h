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
  void releaseCin(){std::cin.rdbuf( cin_buffer );}
  void startCapture(){cout_buffer = std::cout.rdbuf(m_capture.rdbuf());}
  void stopCapture(){std::cout.rdbuf( cout_buffer );}
public:
  IOCapture(){startCapture();}
  ~IOCapture(){stopCapture();releaseCin();}
  std::string output(){return m_capture.str();}
  std::string outputFlush(){
    std::string out = m_capture.str();
    stopCapture();
    std::cout << out << std::flush;
    startCapture();
    return out;
  }
  void inputFeed(std::string in){
    m_input.str(in);
    cin_buffer = std::cin.rdbuf( m_input.rdbuf() );
  }
};
#endif
