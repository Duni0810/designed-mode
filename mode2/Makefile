VPATH = hw_oled1:hw_oled2

objects = main.o hwconf_oled1.o oled1.o hwconf_oled2.o oled2.o   
CC = gcc                                 

a.out : $(objects)                     
	$(CC) -o a.out $(objects)

.PHONY : clean
clean:
	rm a.out $(objects) -rf 
	clear
	ls