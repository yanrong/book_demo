CONFIG	    += console debug
QT	    += network xml
HEADERS	    += ../aqp/kuhn_munkres.hpp
SOURCES	    += ../aqp/kuhn_munkres.cpp
HEADERS	    += ../aqp/alt_key.hpp
SOURCES	    += ../aqp/alt_key.cpp
INCLUDEPATH += ../aqp
HEADERS	    += ../option_parser/option_parser.hpp
SOURCES	    += ../option_parser/option_parser.cpp
INCLUDEPATH += ../option_parser
DEFINES	    += NO_REGEX
HEADERS	    += weathertrayicon.hpp
SOURCES     += weathertrayicon.cpp
SOURCES     += main.cpp
RESOURCES   += weathertrayicon.qrc
