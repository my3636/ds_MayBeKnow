
// zonghe.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include <string>
using namespace std;

// CzongheApp: 
// 有关此类的实现，请参阅 zonghe.cpp
//

class CzongheApp : public CWinApp
{
public:
	CzongheApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CzongheApp theApp;

extern int hang;
extern int info_id;
extern CString info_xingming;
extern CString info_diqu;
extern CString info_xuexiao;
extern CString info_xingqu;
extern CString info_friends;
#define MAXN 30
extern int pengyou[MAXN][MAXN];
extern int city_list[8][MAXN];
extern int school_list[20][MAXN];
extern int hobby_list[12][MAXN];

extern char *city_name[36];
extern char *school_name[20];
extern char *hobby_name[12];

typedef struct person {
	//int id;
	bool flag;
	CString name;
	int city;
	int school;
	int hobby;
	int fri_list[MAXN];
}person;
extern person ren[MAXN];

//=========================================//
extern CString input_gx_id;