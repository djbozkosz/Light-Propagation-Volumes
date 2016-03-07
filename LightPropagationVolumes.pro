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
    src/headers/windowTypes.h \
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

OTHER_FILES += \
    data/shaders/basic.vs \
    data/shaders/color.vs \
    data/shaders/depth.vs \
    data/shaders/perFragment.vs \
    data/shaders/perFragmentShadow.vs \
    data/shaders/perFragmentNormal.vs \
    data/shaders/perFragmentNormalShadow.vs \
    data/shaders/basic.fs \
    data/shaders/basicAlpha.fs \
    data/shaders/color.fs \
    data/shaders/depth.fs \
    data/shaders/perFragment.fs \
    data/shaders/perFragmentShadow.fs \
    data/shaders/perFragmentShadowJitter.fs \
    data/shaders/perFragmentAlpha.fs \
    data/shaders/perFragmentAlphaShadow.fs \
    data/shaders/perFragmentAlphaShadowJitter.fs \
    data/shaders/perFragmentNormal.fs \
    data/shaders/perFragmentNormalShadow.fs \
    data/shaders/perFragmentNormalShadowJitter.fs \
    data/shaders/perFragmentNormalAlpha.fs \
    data/shaders/perFragmentNormalAlphaShadow.fs \
    data/shaders/perFragmentNormalAlphaShadowJitter.fs \
    data/shaders/geometry.fs \
    data/shaders/lpvClear.cs \
    data/shaders/lpvInjection.cs \
    data/shaders/lpvPropagation.cs
