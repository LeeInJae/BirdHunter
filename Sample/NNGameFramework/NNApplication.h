
#pragma once

#include "NNRenderer.h"
#include "NND2DRenderer.h"
#include "NNSceneDirector.h"
#include "NNConfig.h"

/* */
/* NNApplication
/* �����ӿ�ũ�� �ٽ� Ŭ����
/* �������� ������ �������� �����ϰ�
/* ���� ������ ���� ��Ȱ�� �Ѵ�.
/* */

class NNApplication
{
private:
	static NNApplication* m_pInstance;

private:
	NNApplication();
	~NNApplication();

public:
	static NNApplication* GetInstance();
	static void ReleaseInstance();

public:
	bool Init( wchar_t* const title, int width, int height, RendererStatus renderStatus );
	/* �Ķ���Ϳ� ���� ������ ������, ������ ���� */
	bool Release();

	bool Run();

private:
	bool _CreateWindow( wchar_t* title, int width, int height );
	bool _CreateRenderer( RendererStatus renderStatus );

private:
	NNRenderer* m_Renderer;
	NNSceneDirector* m_pSceneDirector;

private:
	HWND m_Hwnd;
	HINSTANCE m_hInstance;
	RendererStatus m_RendererStatus;

private:
	wchar_t* m_Title;
	int m_ScreenWidth;
	int m_ScreenHeight;

private:
	float m_Fps;
	float m_ElapsedTime;
	float m_DeltaTime;

	int m_PrevTime;
	int m_NowTime;

	bool m_DestroyWindow;

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

public:
	inline NNRenderer* GetRenderer() const { return m_Renderer; }
	inline HWND GetHWND() const { return m_Hwnd; }
	inline HINSTANCE GetHandleInstance() const { return m_hInstance; }
	inline const wchar_t* GetTitle() const { return m_Title; }
	inline int GetScreenWidth() const { return m_ScreenWidth; }
	inline int GetScreenHeight() const { return m_ScreenHeight; }
	inline RendererStatus GetRendererStatus() const { return m_RendererStatus; }

	inline float GetFPS() const { return m_Fps; }
	inline float GetElapsedTime() const { return m_ElapsedTime; }
	inline float GetDeltaTime() const { return m_DeltaTime; }
};