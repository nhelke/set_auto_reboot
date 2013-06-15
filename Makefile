CC := clang

default: set_auto_reboot

OBJECTS := set_auto_reboot.o

set_auto_reboot: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
