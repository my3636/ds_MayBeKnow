
// zongheDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "zonghe.h"
#include "zongheDlg.h"
#include "afxdialogex.h"
#include "addperson.h"
#include "shehuiguanxiDlg.h"
#include <stdlib.h>

//==========================定义=============================//
//#define MAXN 30

int pengyou[MAXN][MAXN] = { 0 };
int city_list[8][MAXN] = { 0 };
int school_list[20][MAXN] = { 0 };
int hobby_list[12][MAXN] = { 0 };

CString input_gx_id;
//===========================================================//




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CzongheDlg 对话框

CzongheDlg::CzongheDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZONGHE_DIALOG, pParent)
	, m_gx_id(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CzongheDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST1, m_people_listbox);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Text(pDX, IDC_GXWL_EDIT, m_gx_id);
	DDX_Control(pDX, IDC_LIST_KNRS, m_list_knrs);
}

BEGIN_MESSAGE_MAP(CzongheDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDPEOPLE_BUTTON, &CzongheDlg::OnBnClickedAddpeopleButton)
	ON_BN_CLICKED(IDC_del_BUTTON, &CzongheDlg::OnBnClickeddelButton)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &CzongheDlg::OnLvnColumnclickList2)
	ON_BN_CLICKED(IDC_GXWL_BUTTON, &CzongheDlg::OnBnClickedGxwlButton)
	ON_BN_CLICKED(IDC_FIND_BUTTON, &CzongheDlg::OnBnClickedFindButton)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_KNRS, &CzongheDlg::OnLvnColumnclickListKnrs)
END_MESSAGE_MAP()

// CzongheDlg 消息处理程序

BOOL CzongheDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rect;
	// 获取编程语言列表视图控件的位置和大小
	m_list2.GetClientRect(&rect);
	m_list2.SetExtendedStyle(m_list2.GetExtendedStyle()
		| LVS_EX_GRIDLINES//设置扩展风格为网格
		| LVS_EX_FULLROWSELECT//设置整行选择
	);
	m_list2.InsertColumn(1, _T("ID"), LVCFMT_CENTER, rect.Width() / 12, 0);
	m_list2.InsertColumn(2, _T("姓名"), LVCFMT_CENTER, rect.Width() / 12 * 2, 1);
	m_list2.InsertColumn(3, _T("家乡"), LVCFMT_CENTER, rect.Width() / 12 * 2, 2);
	m_list2.InsertColumn(4, _T("学校"), LVCFMT_CENTER, rect.Width() / 12 * 4, 3);
	m_list2.InsertColumn(5, _T("兴趣"), LVCFMT_CENTER, rect.Width() / 12 * 2, 4);
	m_list2.InsertColumn(5, _T("好友"), LVCFMT_CENTER, rect.Width() / 2, 5);
	//m_wid = m_people_listbox.GetItemText(m_listIndex, 0); // 将选中的值赋值给成员变量，m_list为CListCtrl的控制变量
	//m_dp2 = m_list.GetItemText(m_listIndex, 3); // m_listIndex为列表控件的列号
	//m_position = m_list.GetItemText(m_listIndex, 4);
	for (int i = 0; i < MAXN; i++)
		ren[i].flag = false;

	CRect rect2;
	// 获取编程语言列表视图控件的位置和大小
	m_list_knrs.GetClientRect(&rect2);
	m_list_knrs.SetExtendedStyle(m_list_knrs.GetExtendedStyle()
		| LVS_EX_GRIDLINES//设置扩展风格为网格
		| LVS_EX_FULLROWSELECT//设置整行选择
	);
	m_list_knrs.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect2.Width() / 3);
	m_list_knrs.InsertColumn(1, _T("共同好友数"), LVCFMT_CENTER, rect2.Width() / 3);
	m_list_knrs.InsertColumn(2, _T("总关联度"), LVCFMT_CENTER, rect2.Width() / 3);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CzongheDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CzongheDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CzongheDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CzongheDlg::OnBnClickedAddpeopleButton()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes; // 用于保存DoModal 函数的返回值
	addperson zongheDlg; // 构造对话框类CTipDlg 的实例
	nRes = zongheDlg.DoModal(); // 弹出对话框
	if (IDCANCEL == nRes) // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行
		return;
	// 将各控件中的数据保存到相应的变量
	UpdateData(TRUE);

	/*ren[info_id].name = info_xingming;
	ren[info_id].city = info_diqu;//给每个学校一个编号 即数组下标
	ren[info_id].school = info_xuexiao;
	ren[info_id].hobby = 
	CzongheDlg* p = (CzongheDlg*)::AfxGetMainWnd();
	*/
	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum 的值
	UpdateData(FALSE);
}


void CzongheDlg::OnBnClickeddelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	hang--;//人数减少1
	//删除多列列表中选中的项
	POSITION pos = m_list2.GetFirstSelectedItemPosition();
	int idx = m_list2.GetNextSelectedItem(pos);
	CString str_id = m_list2.GetItemText(idx, 0);
	int int_id = _ttoi(str_id);

	ren[int_id].flag = false;
	for(int i=1;i<= city_list[ren[int_id].city][0];i++)
		if (city_list[ren[int_id].city][i] == int_id)
		{
			i++;
			for (; i <= city_list[ren[int_id].city][0]; i++)
			{
				city_list[ren[int_id].city][i - 1] = city_list[ren[int_id].city][i];
			}
		}
	city_list[ren[int_id].city][0]--;
	for (int i = 1; i <= school_list[ren[int_id].school][0]; i++)
		if (school_list[ren[int_id].school][i] == int_id)
		{
			i++;
			for (; i <= school_list[ren[int_id].school][0]; i++)
			{
				school_list[ren[int_id].school][i - 1] = school_list[ren[int_id].school][i];
			}
		}
	school_list[ren[int_id].school][0]--;
	for (int i = 1; i <= hobby_list[ren[int_id].hobby][0]; i++)
		if (hobby_list[ren[int_id].hobby][i] == int_id)
		{
			i++;
			for (; i <= hobby_list[ren[int_id].hobby][0]; i++)
			{
				hobby_list[ren[int_id].hobby][i - 1] = hobby_list[ren[int_id].hobby][i];
			}
		}
	hobby_list[ren[int_id].hobby][0]--;

	for (int i = 1; i < MAXN; i++)
	{
		pengyou[int_id][i] = 0;
		pengyou[i][int_id] = 0;
	}

	while (idx != -1) {
		LVITEM lvi;

		lvi.iItem = idx;
		lvi.iSubItem = 0;
		lvi.mask = LVIF_IMAGE;

		m_list2.DeleteItem(idx);
		idx = m_list2.GetNextSelectedItem(pos);
	}
	m_list2.Arrange(LVA_DEFAULT);
	m_list2.RedrawItems(0, m_list2.GetItemCount());

}

void CzongheDlg::OnBnClickedGxwlButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if(ren[m_gx_id].flag == true)
	{
		CEdit* pBoxOne;
		pBoxOne = (CEdit*)GetDlgItem(IDC_GX_XM_EDIT);
		pBoxOne->SetWindowTextW(ren[m_gx_id].name);

		int city = ren[m_gx_id].city;
		int school = ren[m_gx_id].school;
		int hobby = ren[m_gx_id].hobby;

		CString laoxiang;
		for (int i = 1; i <= city_list[city][0]; i++)
		{
			if (city_list[city][i] != m_gx_id)
				laoxiang += ren[city_list[city][i]].name + ' ';

		}
		GetDlgItem(IDC_LAOXIANG_STATIC)->SetWindowText(laoxiang);
		CString xiaoyou;
		for (int i = 1; i <= school_list[school][0]; i++)
		{
			if (school_list[school][i] != m_gx_id)
				xiaoyou += ren[school_list[school][i]].name + ' ';

		}
		GetDlgItem(IDC_XIAOYOU_STATIC)->SetWindowText(xiaoyou);
		CString tonghao;
		for (int i = 1; i <= hobby_list[hobby][0]; i++)
		{
			if (hobby_list[hobby][i] != m_gx_id)
				tonghao += ren[hobby_list[hobby][i]].name + ' ';

		}
		GetDlgItem(IDC_TONGHAO_STATIC)->SetWindowText(tonghao);
		CString pengyou;
		for (int i = 1; i <= ren[m_gx_id].fri_list[0]; i++)
		{
			if (ren[m_gx_id].fri_list[i] != m_gx_id)
				pengyou += ren[ren[m_gx_id].fri_list[i]].name + ' ';

		}
		GetDlgItem(IDC_PENGYOU_STATIC)->SetWindowText(pengyou);
	}
	else
	{
		//弹窗，提示不存在此人
		AfxMessageBox(_T("查无此人！"));
	}

	UpdateData(FALSE);

}

//寻找可能认识的人并计算其关联度
void CzongheDlg::OnBnClickedFindButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int i, j;
	int level[MAXN] = { 0 };//关联度
	int bothfri[MAXN] = { 0 };
	for (i = 1; i < MAXN; i++)
	{
		if (ren[i].flag == false||i == m_gx_id)//不存在的用户不考虑，自身不考虑
			continue;
		if (pengyou[i][m_gx_id] == 1)//是朋友的不考虑
			continue;
		if (ren[i].city == ren[m_gx_id].city)
			level[i]++;
		if (ren[i].hobby == ren[m_gx_id].hobby)
			level[i]++;
		if (ren[i].school == ren[m_gx_id].school)
			level[i]++;
		for (j = 1; j < MAXN; j++)
		{
			if (pengyou[i][j] == 1 && pengyou[m_gx_id][j] == 1)
				bothfri[i]++;
		}
		level[i] += bothfri[i];
	}
	m_list_knrs.DeleteAllItems();
	CString s_level;
	int number = 0;//可能认识的人个数
	for (i = 1; i < MAXN; i++)
	{
		if (level[i] != 0)//可能认识，因此加入列表
		{
			m_list_knrs.InsertItem(number, ren[i].name);
			s_level.Format(_T("%d"), bothfri[i]);
			m_list_knrs.SetItemText(number, 1, s_level);//共同好友数目
			s_level.Format(_T("%d"), level[i]);
			m_list_knrs.SetItemText(number, 2, s_level);
			number++;
		}
	}
}

//================================================多列列表排序===================================//
DWORD  dwSelColID = 0; //选择的列
BOOL   bASC = FALSE;     //是否升序
static int CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl *pListCtrl = (CListCtrl *)lParamSort;
	LVFINDINFO findInfo;
	findInfo.flags = LVFI_PARAM;
	findInfo.lParam = lParam1;
	int iItem1 = pListCtrl->FindItem(&findInfo, -1);
	findInfo.lParam = lParam2;
	int iItem2 = pListCtrl->FindItem(&findInfo, -1);

	CString str1, str2;
	str1 = pListCtrl->GetItemText(iItem1, dwSelColID);
	str2 = pListCtrl->GetItemText(iItem2, dwSelColID);
	HDITEM headerItem;
	headerItem.mask = HDI_LPARAM;
	CHeaderCtrl* pHeaderCtrl = pListCtrl->GetHeaderCtrl();
	pHeaderCtrl->GetItem(dwSelColID, &headerItem);
	UINT nType = (UINT)(headerItem.lParam);
	int iCompRes = 0;
	switch (nType)
	{
	case INT_TYPE:
	{
		int i1, i2;
		i1 = _ttoi(str1);
		i2 = _ttoi(str2);
		if (i1 > i2)
			iCompRes = 1;
		else if (i1 == i2)
			iCompRes = 0;
		else
			iCompRes = -1;
	}
	break;
	case DOUBLE_TYPE:
	{
		double i1, i2;
		i1 = _ttof(str1);
		i2 = _ttof(str2);
		if (i1 > i2)
			iCompRes = 1;
		else if (i1 == i2)
			iCompRes = 0;
		else
			iCompRes = -1;
	}
	break;
	case STRING_TYPE:
	default:
	{
		if (str1 > str2)
			iCompRes = 1;
		else if (str1 == str2)
			iCompRes = 0;
		else
			iCompRes = -1;
	}
	break;
	}
	if (bASC)
		return iCompRes;
	else
		return iCompRes*-1;
	return 0;
}

void CzongheDlg::OnLvnColumnclickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//每点击一次，换一种顺序排序
	if (dwSelColID != pNMLV->iSubItem)
	{
		dwSelColID = pNMLV->iSubItem;
		bASC = bASC;
	}
	else
		bASC = !bASC;
	int count = m_list2.GetItemCount();
	for (int i = 0; i < count; i++)
		m_list2.SetItemData(i, i);
	m_list2.SortItems(MyCompareProc, (LPARAM)(&m_list2));
	*pResult = 0;
}


void CzongheDlg::OnLvnColumnclickListKnrs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (dwSelColID != pNMLV->iSubItem)
	{
		dwSelColID = pNMLV->iSubItem;
		bASC = bASC;
	}
	else
		bASC = !bASC;
	int count = m_list_knrs.GetItemCount();
	for (int i = 0; i < count; i++)
		m_list_knrs.SetItemData(i, i);
	m_list_knrs.SortItems(MyCompareProc, (LPARAM)(&m_list_knrs));
	*pResult = 0;
}
