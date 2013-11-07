
#include "NNApplication.h"
#include "SpriteExampleScene.h"
#include "C2DFighterScene.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(  );
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"2D Fighter", 1280, 720, D2D );
	// NNSceneDirector::GetInstance()->ChangeScene( /* Insert Scene! */ );
	NNSceneDirector::GetInstance()->ChangeScene( new C2DFighterScene() );
	Application->Run();
	NNApplication::GetInstance()->Release();

	return 0;
}