CFLAGS = -std=c++14 -Wall
OBJDIR = cmake-build-debug

list:	$(OBJDIR)/list.o $(OBJDIR)/book.o $(OBJDIR)/main.o
	g++ $(OBJDIR)/list.o $(OBJDIR)/book.o $(OBJDIR)/main.o -o $(OBJDIR)/list $(CFLAGS)

$(OBJDIR)/main.o:	main.cpp list.h book.h
	g++ -c main.cpp $(CFLAGS) -o $(OBJDIR)/main.o

test:	$(OBJDIR)/list.o $(OBJDIR)/book.o $(OBJDIR)/test.o
	g++ $(OBJDIR)/list.o $(OBJDIR)/book.o $(OBJDIR)/test.o -o $(OBJDIR)/test $(CFLAGS)

$(OBJDIR)/test.o:	test.cpp list.h book.h
	g++ -c test.cpp $(CFLAGS) -o $(OBJDIR)/test.o


$(OBJDIR)/list.o:	list.cpp list.h book.h
	g++ -c list.cpp $(CFLAGS) -o $(OBJDIR)/list.o

$(OBJDIR)/book.o:	book.cpp book.h
	g++ -c book.cpp $(CFLAGS) -o $(OBJDIR)/book.o


clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/list $(OBJDIR)/test