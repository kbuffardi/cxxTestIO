CXX = g++

all: run_tests

# A rule that runs the unit tests
run_tests: runner
	./runner

# Build the test runner
runner: runner.cpp Talk.cpp IOCapture.h
	$(CXX) -o $@ $^

# Generate the test runner
runner.cpp: IOTest.h
	cxxtestgen -o $@ --error-printer $^
