#include <dlfcn.h>
main()
{
	void *handle=dlopen("./libdemo4.so",RTLD_LAZY);
	void(*fun)(int)=dlsym(handle,"diamond");
	fun(5);
	dlclose(handle);
}
