//duilib_tutorial.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "duilib_tutorial.h"
#include "main_frame_wnd.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// 设置窗口关联的实例
	CPaintManagerUI::SetInstance(hInstance);

	// 设置皮肤的默认路径
	CPaintManagerUI::SetCurrentPath(CPaintManagerUI::GetInstancePath());

	// 创建窗口
	MainFrameWnd* pMainWndFrame = new MainFrameWnd;
	pMainWndFrame->Create(nullptr, MainFrameWnd::kClassName, UI_WNDSTYLE_FRAME, 0);
	pMainWndFrame->CenterWindow();
	pMainWndFrame->ShowWindow();

	CPaintManagerUI::MessageLoop();

	if (nullptr != pMainWndFrame)
	{
		delete pMainWndFrame;
	}

	return 0;
}
