namespace rff
{
	void* fopen_w(wchar* name,wchar* mode)
	{
		sub esp,4
		push mode
		push name
		calle rf.c_fopen_w
		mov s_ret,[esp]
		add esp,4
	}

	void* fopen(char* name,char* mode)
	{
		sub esp,4
		push mode
		push name
		calle rf.c_fopen
		mov s_ret,[esp]
		add esp,4
	}
	
	int fclose(void* fp)
	{
		sub esp,4
		push fp
		calle rf.c_fclose
		mov s_ret,[esp]
		add esp,4
	}
	
	int fread(char* data,int size,int count,void* fp)
	{
		sub esp,4
		push fp
		push count
		push size
		push data
		calle rf.c_fread
		mov s_ret,[esp]
		add esp,4
	}
	
	int fwrite(char* data,int size,int count,void* fp)
	{
		sub esp,4
		push fp
		push count
		push size
		push data
		calle rf.c_fwrite
		mov s_ret,[esp]
		add esp,4
	}
	
	fseek(void* fp,int off,int origin)
	{
		push origin
		push off
		push fp
		calle rf.c_fseek
	}
	
	fseek8(void* fp,int8 off,int origin)
	{
		push origin
		push [ebp+(s_off off+4)]
		push off
		push fp
		calle rf.c_fseek8
	}
	
	int ftell(void* fp)
	{
		sub esp,4
		push fp
		calle rf.c_ftell
		mov s_ret,[esp]
		add esp,4
	}
	
	int8 ftell8(void* fp)
	{
		sub esp,8
		push fp
		calle rf.c_ftell8
		mov8 s_ret,[esp]
		add esp,8
	}
}