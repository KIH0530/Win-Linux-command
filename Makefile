CC := g++
TARGET_touch := touch.cpp
TARGET_rm := rm.cpp
TARGET_ls := ls.cpp
TARGET_winfetch := winfetch.cpp
TARGET_cat := cat.cpp
CFLAGS_touch := -Wall -g -o touch.exe -mconsole
CFLAGS_rm := -Wall -g -o rm.exe -mconsole
CFLAGS_ls := -Wall -g -o ls.exe -mconsole
CFLAGS_winfetch := -mconsole -Wall -g -o winfetch.exe 
CFLAGS_cat := -Wall -g -o cat.exe -mconsole

.PHONY: all clean touch rm ls winfetch cat

all:
	$(CC)  $(TARGET_touch) $(CFLAGS_touch)
	$(CC)  $(TARGET_winfetch) $(CFLAGS_winfetch)
	$(CC)  $(TARGET_rm) $(CFLAGS_rm)
	$(CC)  $(TARGET_ls) $(CFLAGS_ls)
	$(CC)  $(TARGET_cat) $(CFLAGS_cat)
touch:
	$(CC) $(TARGET_touch) $(CFLAGS_touch)
rm:
	$(CC) $(TARGET_rm) $(CFLAGS_rm)
ls:
	$(CC) $(TARGET_ls) $(CFLAGS_ls)
winfetch:
	$(CC) $(TARGET_winfetch) $(CFLAGS_winfetch)
cat:
	$(CC) $(TARGET_cat) $(CFLAGS_cat)
clean:
	rm *.exe