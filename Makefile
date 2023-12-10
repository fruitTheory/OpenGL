INCLUDES ?= -I ./include/ \
-I C:/Programs/glfw/include/ \
-I C:/Programs/glad/include/ \
-I ./imgui/
BUILD = ./build/
SOURCES = ./src/
BINARIES = ./bin/
FLAGS = -g -Wall -Wextra -fdiagnostics-color=always #-fsanitize=address -O3
CC = g++
OBJECTS = ${BUILD}glad.o ${BUILD}imgui.o ${BUILD}imgui_draw.o \
${BUILD}imgui_widgets.o ${BUILD}imgui_tables.o ${BUILD}imgui_demo.o \
${BUILD}imgui_impl_glfw.o ${BUILD}imgui_impl_opengl3.o
LIBRARY_DIR ?=	-L C:/Programs/glfw/lib-mingw-w64 \
-L "C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64"
				 
LINKED_LIBRARIES = -lglfw3 -lopengl32 -lgdi32

# ${OBJECTS} ${LIBRARY_DIR} ${LINKED_LIBRARIES}
all: ${OBJECTS}
	if not exist "bin" mkdir bin
	if not exist "build" mkdir build
	${CC} ${FLAGS} ${INCLUDES} ${OBJECTS} ${SOURCES}main.cpp ${LIBRARY_DIR} ${LINKED_LIBRARIES} -o ${BINARIES}main
	mingw32-make run

# Build all - wildcards
${BUILD}%.o:${SOURCES}%.cpp
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

# Special rule for glad.c
GLAD_SRC = C:/Programs/glad/src/
${BUILD}glad.o: ${GLAD_SRC}glad.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

# Special rule for imgui
IMGUI_SRC = ./imgui/
${BUILD}%.o: ${IMGUI_SRC}%.cpp
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


.PHONY: clean run

# Clean build folder if needed
clean:
	del "${BUILD}"

# Run with file
RUN_FILE = main
EXT = exe
run:
	${BINARIES}${RUN_FILE}.${EXT}
