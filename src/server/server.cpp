#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>

#include <chrono>
#include <thread>

#include <bots/bot.h>
#include <server/server.h>

void ServerStuff()
{
	puts("server stuff");
}

void *LoadTick(FBotTick *pfnBotTick)
{
	*pfnBotTick = nullptr;

	dlerror(); // clear old error
	void *pHandle = dlopen("./libbot.so", RTLD_NOW | RTLD_GLOBAL);
	const char *pError = dlerror();
	if(!pHandle || pError)
	{
		fprintf(stderr, "dlopen failed: %s\n", pError);
		if(pHandle)
			dlclose(pHandle);
		return nullptr;
	}

	*pfnBotTick = (FBotTick)dlsym(pHandle, "BotTick");
	pError = dlerror();
	if(!*pfnBotTick || pError)
	{
		fprintf(stderr, "dlsym failed: %s\n", pError);
		if(pHandle)
			dlclose(pHandle);
		return nullptr;
	}
	return pHandle;
}

void CCollision::Init()
{
	m_pTiles = (int *)malloc(sizeof(int) * m_Width * m_Height);

	for(int x = 0; x < m_Width; x++)
	{
		for(int y = 0; y < m_Height; y++)
		{
			SetTile(x, y, 22);
		}
	}
	SetTile(1, 1, 11);
}

void Sleep(int Miliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(Miliseconds));
}

int main()
{
	puts("starting server ...");

	CCollision Col;
	Col.Init();

	while(true)
	{
		FBotTick pfnBotTick;
		void *pHandle = LoadTick(&pfnBotTick);
		if(pHandle)
		{
			pfnBotTick(&Col);
			dlclose(pHandle);
		}
		else
		{
			BotTick(&Col);
		}

		Sleep(20);
	}
}

