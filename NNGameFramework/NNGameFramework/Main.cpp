
#include "NNApplication.h"

#include "AnimationSample.h"
#include "XMLSample.h"
#include "SpriteAtlasSample.h"
#include "CameraSample.h"
//#include "FMODSoundSample.h"
#include "SpriteSample.h"
#include "NNGameScene.h"
#include "BHDefine.h"
#include <stdio.h>
#include <time.h>
#include "NNStartScene.h"
#include "NNGameOver.h"

/*
void main()
{
	WinMain(0, 0, 0, 3);
}*/ 

//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc( 0x0906a160 );
#endif

	srand( (unsigned int) time(NULL) );

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", RESOLUTION_WIDTH, RESOLUTION_HEIGHT, D2D );
	
	// 콘솔창 띄우기

	AllocConsole();
	FILE* pStream;
	freopen_s(  &pStream, "CONOUT$", "wt", stdout );
// 	while(1)
// 	{
// 		NNPoint pos = NNInputSystem::GetInstance() ->GetMousePosition();
// 		printf_s("%f %f\n", pos );
// 
// 	}
	
	
		
	NNSceneDirector::GetInstance()->ChangeScene( new NNStartScene() );

	 //NNSceneDirector::GetInstance()->ChangeScene( NNGameScene::Create() );
//   //NNSceneDirector::GetInstance()->ChangeScene( SpriteSample::Create() );
 	 //NNSceneDirector::GetInstance()->ChangeScene( AnimationSample::Create() );
// 	 //NNSceneDirector::GetInstance()->ChangeScene( XMLSample::Create() );
// 	 NNSceneDirector::GetInstance()->ChangeScene( SpriteAtlasSample::Create() );
// 	 NNSceneDirector::GetInstance()->ChangeScene( CameraSample::Create() );
// 	// NNSceneDirector::GetInstance()->ChangeScene( FMODSoundSample::Create() );

	Application->Run();
	Application->Release();

	//디버그 후 콘솔창 없앨 것
	FreeConsole();
	return 0;
}