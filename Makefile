SLUG = Neiroi

VERSION = 2.0.0
SOURCES += src/plugin.cpp
SOURCES += src/FreeNeiroi.cpp

DISTRIBUTABLES += res
DISTRIBUTABLES += plugin.json
include $(RACK_DIR)/plugin.mk
