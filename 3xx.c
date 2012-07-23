#include <stdlib.h>
#include <pspkernel.h>
//test
#undef main
extern int SDL_main(int argc, char *argv[]);

PSP_MODULE_INFO("SWORD GIRL", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|PSP_THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(12*1024);


int sdl_psp_exit_callback(int arg1, int arg2, void *common)
{
        exit(0);
        return 0;
}

int sdl_psp_callback_thread(SceSize args, void *argp)
{
        int cbid;
        cbid = sceKernelCreateCallback("Exit Callback", sdl_psp_exit_callback, NULL);
        sceKernelRegisterExitCallback(cbid);
        sceKernelSleepThreadCB();
        return 0;
}

int sdl_psp_setup_callbacks(void)
{
        int thid = 0;
        thid = sceKernelCreateThread("update_thread", sdl_psp_callback_thread, 0x11, 0xFA0, 0, 0);
        if(thid >= 0) sceKernelStartThread(thid, 0, 0);
        return thid;
}




int main(int argc,char **argv)
{
	pspDebugScreenInit();
	sdl_psp_setup_callbacks();

	/* Register sceKernelExitGame() to be called when we exit */
	atexit(sceKernelExitGame);

	(void)SDL_main(argc, argv);
	return 0;
}
