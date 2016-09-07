CXX=g++
CXXFLAGS=-std=c++11 -g

OBJS=main_PA4.o BinarySearchTree.o BinaryNode.o
main_PA4: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.h

clean:
	rm -f $(OBJS) main
