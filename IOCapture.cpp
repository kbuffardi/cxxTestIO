#include "IOCapture.h"

// Constructor initiates capturing anything in the cout buffer
IOCapture::IOCapture(){
  startCapture();
}

// Destructor stops the cout capture
IOCapture::~IOCapture(){
  stopCapture();
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
