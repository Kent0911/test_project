#include <stdio.h>
#include <Windows.h>
#include <d3d11.h>
#include <string>
#include <Shlwapi.h>




#define IDI_SAMPLE1 107

// コールバック関数定義
typedef LRESULT(CALLBACK *LPONMESSAGE)(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);


class CWindow {
private:
	WNDCLASSEX			wcex;
	RECT				m_rec;

	static LRESULT CALLBACK WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);

	HRESULT InitWindow(HINSTANCE _hInstance, int _nCmdShow);

public:
	CWindow(HINSTANCE _hInstance, int _nCmdShow);
	~CWindow();
	inline WNDCLASSEX GetWcex() {
		return wcex;
	}
	inline RECT GetRect() {
		return m_rec;
	}
};

LRESULT CWindow::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam) {
	
	PAINTSTRUCT ps;
	HDC hdc;

	switch (_message) {
	case WM_PAINT:
		hdc = BeginPaint(_hWnd, &ps);
		EndPaint(_hWnd, &ps);
		break;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(_hWnd, _message, _wParam, _lParam);
	}

	return 0;
}

HRESULT CWindow::InitWindow(HINSTANCE _hInstance, int _nCmdShow) {
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, (LPCTSTR)IDI_SAMPLE1);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "SampleWindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SAMPLE1);
	if (!RegisterClassEx(&wcex))
		return E_FAIL;
}

CWindow::CWindow(HINSTANCE _hInstance, int _nCmdShow) {
	InitWindow(_hInstance, _nCmdShow);
	m_rec = { 0,0,640,480 };
}

CWindow::~CWindow(){ }

class Application {
private:
	HINSTANCE	mhInst;
	HWND		mhWnd;
	
	CWindow		*mp_window;
	LPSTR		ml_str;
	bool		mb_is_Active;

	


public:
	Application(HINSTANCE _hInstance, int _nCmdShow);
	~Application();

	HRESULT	HCreateWindow(HINSTANCE _hInstance, int _nCmdShow);

	inline CWindow* GetWindow() {
		return mp_window;
	}
	inline bool IsActive() {
		return mb_is_Active;
	}
	inline void IsActive(BOOL _state) {
		mb_is_Active = _state;
	}
};

Application::Application(HINSTANCE _hInstance, int _nCmdShow) {
	mhInst = nullptr;
	mhWnd = nullptr;
	mp_window = new CWindow(_hInstance, _nCmdShow);
	AdjustWindowRect(&mp_window->GetRect(), WS_OVERLAPPEDWINDOW, FALSE);

	ml_str = "test_project";

	mb_is_Active = TRUE;
}

Application::~Application(){ }

HRESULT Application::HCreateWindow(HINSTANCE _hInstance, int _nCmdShow) {
	mhInst = _hInstance;
	mhWnd = CreateWindow(mp_window->GetWcex().lpszClassName, ml_str, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, mp_window->GetRect().right - mp_window->GetRect().left, mp_window->GetRect().bottom - mp_window->GetRect().top,
		nullptr, nullptr, _hInstance, nullptr);
	if (!mhWnd) { return E_FAIL; }

	ShowWindow(mhWnd, _nCmdShow);

	return S_OK;
}



int WINAPI wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
	
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	Application *app = new Application(hInstance, nCmdShow);
	
	if (FAILED(app->HCreateWindow(hInstance, nCmdShow))) { return 0; }


	MSG msg;


	while (app->IsActive()) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				app->IsActive(FALSE);
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			
		
		}
	}

	return (int)msg.wParam;
}