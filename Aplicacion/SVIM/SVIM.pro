
QT += core gui openglwidgets
CONFIG += c++17 console
CONFIG -= app_bundle
LIBS += -lopengl32 -lglu32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        archivo.cpp \
        archivo_mif.cpp \
        detectordeestructuras.cpp \
        filtrodecolor.cpp \
        graficador.cpp \
        imagen.cpp \
        interfaz.cpp \
        main.cpp \
        metadatos.cpp \
        oscuredor.cpp \
        pixel.cpp \
        procesador.cpp \
        sistema.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    archivo.h \
    archivo_mif.h \
    detectordeestructuras.h \
    filtrodecolor.h \
    graficador.h \
    imagen.h \
    interfaz.h \
    metadatos.h \
    oscuredor.h \
    pixel.h \
    procesador.h \
    sistema.h
