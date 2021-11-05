all: run_tests app

# Rules to build your targets
app:
	g++ -o talker main.cpp Talk.cpp

# A rule that runs the unit tests
run_tests: runner
	./runner

# Build the test runner
runner: runner.cpp
	$(CXX) -o $@ $<

# Generate the test runner
runner.cpp: IOTest.h
	cxxtestgen -o $@ --error-printer $^
