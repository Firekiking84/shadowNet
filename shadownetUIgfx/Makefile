NAME =			UI
LIBNAME =
LIBFILE =		lib$(LIBNAME).a

SRC =			src/main.cpp					\
			src/Button/Button.cpp				\
			src/Button/draw.cpp				\
			src/Button/inBox.cpp				\
			src/Button/mouseClickEvent.cpp			\
			src/Button/mouseMoveEvent.cpp			\
			src/Button/reset.cpp				\
			src/Div/addButton.cpp				\
			src/Div/Div.cpp					\
			src/Div/draw.cpp				\
			src/Div/mouseClickEvent.cpp			\
			src/Div/mouseMoveEvent.cpp			\
			src/Div/operator.cpp				\
			src/Div/setColor.cpp				\
			src/drawRectangle.cpp				\
			src/Gui/addButton.cpp				\
			src/Gui/addDiv.cpp				\
			src/Gui/draw.cpp				\
			src/Gui/eventResponse.cpp			\
			src/Gui/Gui.cpp					\
			src/Gui/rmDiv.cpp				\
			src/Gui/setDivColor.cpp				\
			src/loop.cpp					\
			src/setPixel.cpp				\

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



