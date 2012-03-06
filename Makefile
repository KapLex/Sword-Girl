TARGET = girl
PSPSDK = C:/pspsdk/psp/sdk
PSPBIN= C:/pspsdk/bin

OBJS = Role.o assist.o Dialog.o Map.o  Fighter.o  Record.o  Menu.o Girl.o 3xx.o Input.o

CFLAGS = -g -Wall -Wno-long-long -G0 -O2 -DJOY_$(JOY)
CFLAGS += $(shell $(PSPBIN)/sdl-config --cflags) -Dmain=SDL_main -DPSP
CXXFLAGS = $(DEFAULT_CFLAGS) -fno-exceptions -fno-rtti

LIBS = $(shell $(PSPBIN)/sdl-config --libs) -lSDL_ttf -lfreetype -lm -lz -lpspsdk  -lstdc++

BUILD_PRX = 1
PSP_FW_VERSION = 371
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = sword-girl

include $(PSPSDK)/lib/build.mak 
