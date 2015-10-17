CC           = g++
CCVER        = -std=c++0x
TARGETNAME   = LightPropagationVolumes

ifeq ($(OS), Windows_NT)
  CCFLAGS    = -D __NO_INLINE__
  LDFLAGS    = -static-libgcc -static-libstdc++
  RM         = del /S
  RUN        = 
else
  OSVER      = 
  CCFLAGS    = 
  LDFLAGS    = 
  RM         = rm -f
  RUN        = ./
endif

CFLAGS       = -pedantic -Wall -Wextra -Wdouble-promotion -Wunreachable-code -O3 $(CCVER) $(CCFLAGS) -c
LIBS         = -lopengl32 -lglew32 -lSDL2

SRC          = main.cpp engine.cpp scenes.cpp models.cpp renderer.cpp shaders.cpp framebuffers.cpp maps.cpp filesystem.cpp
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