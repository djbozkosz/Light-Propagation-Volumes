QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LightPropagationVolumes
TEMPLATE = app
CONFIG += static

DEFINES += ENV_QT

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Wextra
QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS += -Wdouble-promotion
QMAKE_CXXFLAGS += -Wunreachable-code
QMAKE_CXXFLAGS += -O3

SOURCES += \
    src/main.cpp \
    src/engine.cpp \
    src/window.cpp \
    src/scenes.cpp \
    src/models.cpp \
    src/renderer.cpp \
    src/shaders.cpp \
    src/framebuffers.cpp \
    src/maps.cpp \
    src/openGL.cpp \
    src/filesystem.cpp

HEADERS += \
    src/engine.h \
    src/window.h \
    src/scenes.h \
    src/models.h \
    src/renderer.h \
    src/shaders.h \
    src/culling.h \
    src/pickColor.h \
    src/framebuffers.h \
    src/maps.h \
    src/camera.h \
    src/openGL.h \
    src/filesystem.h \
    src/exceptions.h \
    src/context.h \
    src/matrix.h \
    src/vector.h \
    src/string.h \
    src/headers/sceneTypes.h \
    src/headers/modelTypes.h \
    src/headers/rendererTypes.h \
    src/headers/shaderTypes.h \
    src/headers/cullingTypes.h \
    src/headers/mapTypes.h \
    src/headers/cameraTypes.h \
    src/headers/openGLTypes.h \
    src/headers/fileTypes.h \
    src/headers/exceptionTypes.h \
    src/headers/engineTypes.h \
    src/headers/math.h \
    src/headers/stringTypes.h \
    src/headers/types.h

FORMS += \
    ui/mainWindow.ui

OTHER_FILES += \
    data/shaders/color.vs \
    data/shaders/depth.vs \
    data/shaders/basic.vs \
    data/shaders/illumination.vs \
    data/shaders/geometry.vs \
    data/shaders/lpvClear.vs \
    data/shaders/lpvInjection.vs \
    data/shaders/lpvPropagation.vs \
    data/shaders/lpvClear.gs \
    data/shaders/lpvInjection.gs \
    data/shaders/lpvPropagation.gs \
    data/shaders/color.fs \
    data/shaders/depth.fs \
    data/shaders/sunRays.fs \
    data/shaders/basic.fs \
    data/shaders/illumination.fs \
    data/shaders/geometry.fs \
    data/shaders/lpvClear.fs \
    data/shaders/lpvInjection.fs \
    data/shaders/lpvPropagation.fs \
    data/shaders/lpvClear.cs \
    data/shaders/lpvInjection.cs \
    data/shaders/lpvPropagation.cs
