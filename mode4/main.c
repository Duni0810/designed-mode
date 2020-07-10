#include <stdio.h>
#include "proxy.h"
#include "conf_young_man.h"
#include "string.h"


int main(int argc, char *argv[])
{
	char *girl = "xiaohua\0";
	
	// С�������Ǹ���������н� 
	proxy_handle handle = young_man_inst_init(girl, strlen(girl));
	
	// �н�ʵ���Ͷ����Ĳ��� 
	chocolates_giving(handle);
	milk_tea_giving(handle);
	dolls_giving(handle);
	
	// ���궫��֮��С��ʧ���� ���������Ͷ������� 
	young_man_deinit(handle);
	
	chocolates_giving(handle);
	milk_tea_giving(handle);
	dolls_giving(handle);
	
	
	return 0;
}
