#include <stdio.h>
#include <stdlib.h>
#include "hwconf_function.h"

#define   FOEVER       for(;;)

static void func1(void)
{
	oled_handle handle = oled1_inst_init();

	oled_font_size_cfg(handle, FONT_SIZE_12_24);

	oled_str_show(handle, "young_test\n"); 
	
	char p_data[] = {0x31, 0x32, 0x41, 0x42}; // 12AB

	oled_graph_show(handle, p_data, sizeof(p_data));
	
	oled1_inst_deinit(handle); 
}

static void func2(void)
{
	oled_handle handle = oled2_inst_init();

	oled_font_size_cfg(handle, FONT_SIZE_12_24);

	oled_str_show(handle, "young_test\n"); 
	
	char p_data[] = {0x31, 0x32, 0x41, 0x42}; // 12AB 

	oled_graph_show(handle, p_data, sizeof(p_data));
	
	oled1_inst_deinit(handle); 
}
int main(int argc, char *argv[]) 
{
	func1();
	func2();

	return 0;
}
