NAME =			shadownetUI
LIBNAME =
LIBFILE =		lib$(LIBNAME).a

SRC =			src/main.cpp					\
			src/contact/contact.cpp				\
			src/contact/operator.cpp			\
			src/NetworkUDP/can.cpp				\
			src/NetworkUDP/NetworkUDP.cpp			\
			src/NetworkUDP/readFd.cpp			\
			src/NetworkUDP/recvFromSoft.cpp			\
			src/NetworkUDP/sendSoft.cpp			\
			src/NetworkUDP/sendUser.cpp			\
	 		src/NetworkUDP/testAllTarget.cpp		\
			src/NetworkUDP/testOneTarget.cpp		\

OBJS =			$(SRC:.cpp=.o)
INCLUDE =		-I./include

CPP =			g++

FLAGS =			-Wall
GCOV_FLAGS =		--coverage
LDFLAGS =		-L./

GDB_FLAGS =		-O0 -g -ggdb -g3
GCOV_FLAGS =		-O0 --coverage
LAPIN_FLAGS =		-L./ -llapin -lsfml-graphics -lsfml-audio -lsfml-window		\
			-lsfml-system -lstdc++ -lm -ldl -lpthread			\
			-lopencv_imgproc -lopencv_highgui				\
		        -lopencv_objdetect -lopencv_videoio				\
	                -lopencv_core -lavcall						\

OPT_FLAGS += $(GDB_FLAGS)
ifeq ($(GCOV), 1)
	OPT_FLAGS += $(GCOV_FLAGS)
endif
OPT_FLAGS += $(LAPIN_FLAGS)

all: $(NAME)

$(LIBFILE): $(OBJS)
	ar rsc $(LIBFILE) $(OBJS)

lib:$(LIBFILE)

.cpp.o:
	$(CPP) $(FLAGS) $(OPT_FLAGS) $(TEST_INCLUDE) $(INCLUDE) -c $< -o $@

clean:
	rm -f Makefile~
	rm -f $(shell find ./ -name "*.o")
	rm -f $(shell find ./ -name "*~")
	rm -f $(shell find ./ -name "*.gcno")
	rm -f $(shell find ./ -name "*.gcov")

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

tree: fclean
	tree

$(NAME):$(OBJS)
	$(CPP) $(OBJS) $(OPT_FLAGS) $(LDFLAGS) -o $(NAME)



