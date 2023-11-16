CFLAGS+= -lpthread -lge2d -lion
CFLAGS+= -Wall -Wextra

SRC:= main.c
OUT:= main

INCLUDE_BMP:= ../../libs/bmp/

LIBGE2D_DIR:= ../../libs/libge2d

SRC_BMP:= $(wildcard $(INCLUDE_BMP)*.c)

OBJS:= $(SRC:.c=.o) $(SRC_BMP:.c=.o)

default: $(OUT)
	
$(OUT): $(OBJS)
	$(MAKE) -C $(LIBGE2D_DIR)
	$(CC) -L$(LIBGE2D_DIR) -I $(INCLUDE_BMP) $(OBJS) -o $(OUT) $(CFLAGS)

%.o: %.c
	$(CC) -Wall -Wextra -c $< -o $@

clean:
	rm -rf $(OUT) $(OBJS)

.PHONY : clean all
