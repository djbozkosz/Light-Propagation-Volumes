CC           = g++
CCVER        = -std=c++0x
TARGETNAME   = LightPropagationVolumes
ENVIRONMENT  = -D ENV_SDL

ifeq ($(OS), Windows_NT)
  CCFLAGS    = 
  LDFLAGS    = -static-libgcc -static-libstdc++ -mwindows -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
  LIBS       = -lopengl32 -lSDL2 -lSDL2_image
  RM         = del /S
  RUN        = 
else
  CCFLAGS    = 
  LDFLAGS    = 
  LIBS       = -lGL -lX11 -lSDL2 -lSDL2_image
  RM         = rm -f
  RUN        = ./
endif

CFLAGS       = -pedantic -Wall -Wextra -Wdouble-promotion -Wunreachable-code -O0 $(CCVER) $(CCFLAGS) $(ENVIRONMENT) -c

SRC          = main.cpp engine.cpp window.cpp scenes.cpp models.cpp renderer.cpp shaders.cpp framebuffers.cpp maps.cpp openGL.cpp filesystem.cpp
OBJ          = $(SRC:.cpp=.o)
SOURCES      = $(addprefix src/, $(SRC))
OBJECTS      = $(addprefix obj/, $(OBJ))
TARGET       = bin/$(TARGETNAME).exe

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o stdout.txt stderr.txt

run:
	$(RUN)$(TARGET)

make-run: $(SOURCES) $(TARGET)
	$(RUN)$(TARGET)