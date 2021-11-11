#include "IOCapture.h"

// Constructor initiates capturing anything in the cout buffer
IOCapture::IOCapture(){
  startCapture();
}

// Destructor stops the cout and cin capture
IOCapture::~IOCapture(){
  stopCapture();
  releaseCin();
}

// Stops the input feed so the cin returns to its normal behavior
void IOCapture::releaseCin(){
  std::cin.rdbuf( cin_buffer );
}

// Provides a string that will be used as a buffer for any input, in place out
// user-provided cin or getline
void IOCapture::inputFeed(std::string in){
  m_input.str(in);
  cin_buffer = std::cin.rdbuf( m_input.rdbuf() );
}

// Begins capture by redirecting the cout buffer to IOCapture private member
// stream, cout_stream
void IOCapture::startCapture(){
  cout_buffer = std::cout.rdbuf(m_capture.rdbuf());
}

// Stops the capture so that the cout returns to its normal behavior
void IOCapture::stopCapture(){
  std::cout.rdbuf( cout_buffer );
}

// Returns everything captured from cout. The contents of cout are maintained in
// the buffer and the capture remains open
std::string IOCapture::output(){
  return m_capture.str();
}

// Returns everything captured from cout, flushes it, AND continues the capture
// so that the flush immediately displays but nothing is lost from cout capture
// but the flushed output is not duplicated
std::string IOCapture::outputFlush(){
  std::string out = m_capture.str();
  stopCapture();
  std::cout << out << std::flush;
  startCapture();
  return out;
}
