/*
可变参数
*/

main
{
	putsl sum[1,2]
	putsl sum[1,2,3]
	putsl sum[1,99,3]
	putsl sum[1,2,3,4]
	putsl sum[1,sum[1,2,5],3,4]
}

int sum(int count)
{
	//sub esp,sizeof(s_local)
	//push ebp
	//mov ebp,esp

	int* p=&count+1
	int ret=0
	for i=0;i<count;i++
		ret+=*p
		p++
	*p=ret

	mov ecx,4
	imul ecx,count
	add ecx,4
	pop ebp
	add esp,sizeof(s_local)
	mov eax,[esp]
	_reti(eax,ecx)

	//这里有编译器自动增加的语句
}