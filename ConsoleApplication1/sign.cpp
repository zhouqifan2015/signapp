#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>


using namespace std;
BOOL iJudge(HWND hwnd)
{
	if(!hwnd)
	{
		cout << "NO HWND!  -> " << hwnd << endl;
		return FALSE;
	}
	return TRUE;
}

//BOOL iIsLogin(HWND hwnd)
//{
//	int l_iChecked = SendMessage(hwnd, BM_GETCHECK,0,0); 
//	if(!l_iChecked)
//	{
//		//cout << "�������Զ���¼�������Զ���¼" << endl;
//		//cout << "��ʼ��½" << endl;
//		return TRUE;
//	}
//	//cout << "�������Զ���¼�����ڵ�¼" << endl;
//	return FALSE;
//}

int main()
{
	HWND l_Hndl_Main = NULL;
	HWND l_Hndl_Sign = NULL;
	HWND l_Hndl_AutoLogin = NULL;
	HWND l_Hndl_AutoLogin_State = NULL;
	HWND l_Hndl_LoginButton = NULL;
	HWND l_ChildWindowHandle = NULL;
	BOOL l_WindowActived = false;
	BOOL l_SetCur = false;
	POINT l_point = {0,0};
	RECT l_Rect = {0,0,0,0};
	time_t l_time = time(NULL);
	struct tm *l_TimeStruct = NULL;
	INT l_iCount = 0;
	INT l_iTimeMin = 0;

	l_TimeStruct = localtime(&l_time); 
	//cout << l_TimeStruct->tm_hour << endl;

	srand(time(NULL));
	l_iTimeMin = rand()%25;

	while(l_TimeStruct->tm_hour!=8 || l_TimeStruct->tm_min!= l_iTimeMin )
	{
		cout << l_TimeStruct->tm_hour << ":" << l_TimeStruct->tm_min << ":" 
			<< l_TimeStruct->tm_sec << "    " << "sign time: " << "08" << ":" << l_iTimeMin << endl;
		Sleep(1000);
		time_t l_time = time(NULL);
		l_TimeStruct = localtime(&l_time); 
	}

	l_Hndl_Main = FindWindow("#32770","�ſ���ʵ����");

	if(!l_Hndl_Main)
	{
		cout << "����δ�򿪣���������" << endl;
		WinExec("sign.bat",SW_HIDE);
		//WinExec("start \"\" \"D:\\Program Files\\Jingoal\\Jingoal.exe\"", SW_HIDE);
		Sleep(20000);
		Sleep(5000);
		cout << "3" << endl;
		Sleep(5000);
		cout << "2" << endl;
		Sleep(5000);
		cout << "1" << endl;

		l_Hndl_Main = FindWindow("#32770","�ſ���ʵ����");
		l_ChildWindowHandle = FindWindowEx(l_Hndl_Main, NULL, "#32770", 0);
		l_Hndl_AutoLogin_State = FindWindowEx(l_ChildWindowHandle, NULL, "Button", "�Զ���¼");


		if( l_Hndl_AutoLogin_State )
		{
			l_Hndl_LoginButton = FindWindowEx(l_ChildWindowHandle, NULL, "Button", "��    ¼");

			SendMessage(l_Hndl_LoginButton,WM_LBUTTONDOWN,0,0);
			SendMessage(l_Hndl_LoginButton,WM_LBUTTONUP,0,0);
			cout << " ��ʼ�ֶ���¼" << endl;
			Sleep(20000);
		}	
	}

	cout << "������������" << endl;

	l_iCount = 3;
	l_ChildWindowHandle = NULL;

	l_Hndl_Main = FindWindow("#32770","�ſ���ʵ����");
	iJudge(l_Hndl_Main);
	l_ChildWindowHandle = FindWindowEx(l_Hndl_Main, NULL, "AfxWnd80su", 0);
	iJudge(l_ChildWindowHandle);
	l_ChildWindowHandle = FindWindowEx(l_Hndl_Main, l_ChildWindowHandle, "AfxWnd80su", 0);
	iJudge(l_ChildWindowHandle);
	l_ChildWindowHandle = FindWindowEx(l_ChildWindowHandle, 0, "AfxWnd80su", 0);
	iJudge(l_ChildWindowHandle);


	SendMessage(l_ChildWindowHandle,WM_LBUTTONDOWN,0,0);
	SendMessage(l_ChildWindowHandle,WM_LBUTTONUP,0,0);

	Sleep(3000);

	l_Hndl_Sign = FindWindow("#32770","����");
	iJudge(l_Hndl_Sign);

	l_WindowActived = SetWindowPos(l_Hndl_Sign,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	if(!l_WindowActived)
		cout << "activing window failed!" << endl;

	GetWindowRect(l_Hndl_Sign,&l_Rect);
	l_point.x = l_Rect.left+(LONG)(0.86*(l_Rect.right-l_Rect.left));
	l_point.y = l_Rect.top+(LONG)(0.2*(l_Rect.bottom-l_Rect.top));

	l_SetCur = SetCursorPos(l_point.x, l_point.y);
	if(!l_SetCur)
		cout << "setting cur failed!" << endl;

	Sleep(10000);
	Sleep(5000);
	cout << "3" << endl;
	Sleep(5000);
	cout << "2" << endl;
	Sleep(5000);
	cout << "1" << endl;


	mouse_event(MOUSEEVENTF_LEFTDOWN,l_point.x,l_point.y,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,l_point.x,l_point.y,0,0);

	return 0;
}