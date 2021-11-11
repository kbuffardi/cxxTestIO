# IOCapture

The IOCapture class provides functions to "capture" input and output, normally
used with `iostream` (e.g. `std::cin`, `std::cout`, and
`std::getline(std::cin,std::string)`) and specify input and gather output for
unit tests.

## std::string output()

Returns everything captured from cout. The contents of cout are maintained in
the buffer and the capture remains open

## std::string outputFlush()

Returns everything captured from cout, flushes it, AND continues the capture
so that the flush immediately displays but nothing is lost from cout capture but
the flushed output is not duplicated

## void inputFeed(std::string)

Provides a string that will be used as a buffer for any input, in place out
user-provided cin or getline

# Running Example

This repository has a simple example class, `Talk`, and a CxxTest suite,
`IOTest` to verify the functionality of IOCapture within unit tests. To run the
example tests, you must have CxxTest installed, or you can run the container
specified in `Dockerfile` with the following commands:

```
$ docker build -t iocapture . && docker run -it iocapture
/usr/src/cxxTestIO# make
```

This will build and run the tests
