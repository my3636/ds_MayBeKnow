// addperson.cpp : 实现文件
//

#include "stdafx.h"
#include "zonghe.h"
#include "addperson.h"
#include "afxdialogex.h"
#include "zongheDlg.h"
#include "shehuiguanxiDlg.h"

int hang = 0;
int info_id;
CString info_xingming;
CString info_diqu;
CString info_xuexiao;
CString info_xingqu;
CString info_friends;

char *city_name[36] =
{
	"北京",
	"天津",
	"上海",
	"重庆",
	"河北",
	"山西",
	"辽宁",
	"吉林",
	"黑龙江",
	"江苏",
	"浙江",
	"安徽",
	"福建",
	"江西",
	"山东",
	"河南",
	"湖北",
	"湖南",
	"广东",
	"海南",
	"四川",
	"贵州",
	"云南",
	"陕西",
	"甘肃",
	"青海",
	"台湾",
	"内蒙古",
	"广西",
	"西藏",
	"宁夏",
	"新疆",
	"香港",
	"澳门"
};//34
char *school_name[20] =
{
	"清华大学",
	"北京大学",
	"中国人民大学",
	"南开大学",
	"天津大学",
	"上海交通大学",
	"复旦大学",
	"同济大学",
	"浙江大学",
	"南京大学",
	"武汉大学",
	"中山大学",
};//12
char *hobby_name[12] =
{
	"游泳","篮球","舞蹈","滑冰","乒乓球",
	"羽毛球","体操","跳高","唱歌","跑步"
};//10

person ren[MAXN];
//========================================================================================//

// addperson 对话框

IMPLEMENT_DYNAMIC(addperson, CDialogEx)

addperson::addperson(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_REN_DIALOG, pParent)
	, input_name(_T(""))
	, input_friends(_T(""))
	, input_id(0)
{
}

addperson::~addperson()
{
}

BOOL addperson::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//34
	m_combo_diqu.AddString((CString)(city_name[0]));
	m_combo_diqu.AddString((CString)(city_name[1]));
	m_combo_diqu.AddString((CString)(city_name[2]));
	m_combo_diqu.AddString((CString)(city_name[3]));
	m_combo_diqu.AddString((CString)(city_name[4]));
	m_combo_diqu.AddString((CString)(city_name[5]));
	m_combo_diqu.AddString((CString)(city_name[6]));
	m_combo_diqu.AddString((CString)(city_name[7]));
	m_combo_diqu.AddString((CString)(city_name[8]));
	m_combo_diqu.AddString((CString)(city_name[9]));
	m_combo_diqu.AddString((CString)(city_name[10]));
	m_combo_diqu.AddString((CString)(city_name[11]));
	m_combo_diqu.AddString((CString)(city_name[12]));
	m_combo_diqu.AddString((CString)(city_name[13]));
	m_combo_diqu.AddString((CString)(city_name[14]));
	m_combo_diqu.AddString((CString)(city_name[15]));
	m_combo_diqu.AddString((CString)(city_name[16]));
	m_combo_diqu.AddString((CString)(city_name[17]));
	m_combo_diqu.AddString((CString)(city_name[18]));
	m_combo_diqu.AddString((CString)(city_name[19]));
	m_combo_diqu.AddString((CString)(city_name[20]));
	m_combo_diqu.AddString((CString)(city_name[21]));
	m_combo_diqu.AddString((CString)(city_name[22]));
	m_combo_diqu.AddString((CString)(city_name[23]));
	m_combo_diqu.AddString((CString)(city_name[24]));
	m_combo_diqu.AddString((CString)(city_name[25]));
	m_combo_diqu.AddString((CString)(city_name[26]));
	m_combo_diqu.AddString((CString)(city_name[27]));
	m_combo_diqu.AddString((CString)(city_name[28]));
	m_combo_diqu.AddString((CString)(city_name[29]));
	m_combo_diqu.AddString((CString)(city_name[30]));
	m_combo_diqu.AddString((CString)(city_name[31]));
	m_combo_diqu.AddString((CString)(city_name[32]));
	m_combo_diqu.AddString((CString)(city_name[33]));
	//12
	m_combo_xuexiao.AddString((CString)(school_name[0]));
	m_combo_xuexiao.AddString((CString)(school_name[1]));
	m_combo_xuexiao.AddString((CString)(school_name[2]));
	m_combo_xuexiao.AddString((CString)(school_name[3]));
	m_combo_xuexiao.AddString((CString)(school_name[4]));
	m_combo_xuexiao.AddString((CString)(school_name[5]));
	m_combo_xuexiao.AddString((CString)(school_name[6]));
	m_combo_xuexiao.AddString((CString)(school_name[7]));
	m_combo_xuexiao.AddString((CString)(school_name[8]));
	m_combo_xuexiao.AddString((CString)(school_name[9]));
	m_combo_xuexiao.AddString((CString)(school_name[10]));
	m_combo_xuexiao.AddString((CString)(school_name[11]));
	//10
	m_combo_xingqu.AddString(_T("游泳"));
	m_combo_xingqu.AddString(_T("篮球"));
	m_combo_xingqu.AddString(_T("舞蹈"));
	m_combo_xingqu.AddString(_T("滑冰"));
	m_combo_xingqu.AddString(_T("乒乓球"));
	m_combo_xingqu.AddString(_T("羽毛球"));
	m_combo_xingqu.AddString(_T("体操"));
	m_combo_xingqu.AddString(_T("跳高"));
	m_combo_xingqu.AddString(_T("唱歌"));
	m_combo_xingqu.AddString(_T("跑步"));
	// 默认选择第一项   
	m_combo_diqu.SetCurSel(0);
	m_combo_xuexiao.SetCurSel(0);
	return TRUE;
}
void addperson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_EDIT, input_name);
	DDX_Control(pDX, IDC_diqu_COMBO, m_combo_diqu);
	DDX_Control(pDX, IDC_xuexiao_COMBO, m_combo_xuexiao);
	DDX_Control(pDX, IDC_xingqu_COMBO, m_combo_xingqu);
	DDX_Text(pDX, IDC_friends_EDIT, input_friends);
	DDX_Text(pDX, IDC_ID_EDIT, input_id);
}
BEGIN_MESSAGE_MAP(addperson, CDialogEx)
	ON_BN_CLICKED(IDOK, &addperson::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &addperson::OnBnClickedCancel)
END_MESSAGE_MAP()


// addperson 消息处理程序


void addperson::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//CDialog* p = (CDialog*)::AfxGetMainWnd();//主对话框指针
	CzongheDlg* p = (CzongheDlg*)::AfxGetMainWnd();//主对话框指针

	info_id = GetDlgItemInt(IDC_ID_EDIT);
	ren[info_id].flag = true;

	GetDlgItemText(IDC_NAME_EDIT, info_xingming);//获取B窗口中控件的数据存到info_xingming
	ren[info_id].name = info_xingming;

	int nSel;
	nSel = m_combo_diqu.GetCurSel();// 获取组合框控件的列表框中选中项的索引  
	m_combo_diqu.GetLBText(nSel, info_diqu);// 根据选中项索引获取该项字符串   
	int i_diqu = m_combo_diqu.GetCurSel();// 更新地区列表
	city_list[i_diqu][0]++;//表示该地区目前有几人
	city_list[i_diqu][city_list[i_diqu][0]] = info_id;
	ren[info_id].city = i_diqu;

	nSel = m_combo_xuexiao.GetCurSel();  
	m_combo_xuexiao.GetLBText(nSel, info_xuexiao);
	int i_xuexiao = m_combo_xuexiao.GetCurSel();
	school_list[i_xuexiao][0]++;
	school_list[i_xuexiao][school_list[i_xuexiao][0]] = info_id;
	ren[info_id].school = i_xuexiao;

	nSel = m_combo_xingqu.GetCurSel();   
	m_combo_xingqu.GetLBText(nSel, info_xingqu);
	int i_xingqu = m_combo_xingqu.GetCurSel();
	hobby_list[i_xingqu][0]++;
	hobby_list[i_xingqu][hobby_list[i_xingqu][0]] = info_id;
	ren[info_id].hobby = i_xingqu;

	GetDlgItemText(IDC_friends_EDIT, info_friends);

//==========将cstring（数字用逗号隔开）转成int型数据,更新朋友列表==============//
	string str = CW2A(info_friends.GetString());
	int str_n;
	str_n = str.length();///不加最后的空字符串
	const char *shu = new char[str_n + 1];
	shu = str.c_str();
	int m = 1;
	for (int i = 0; i <= str_n; i++) 
	{
		if (shu[i] >= '0' && shu[i] <= '9') 
		{
			if (i == 0)
			{
				ren[info_id].fri_list[m] = shu[i] - '0';
			}
			else if (shu[i - 1] >= '0' && shu[i - 1] <= '9') 
			{
				ren[info_id].fri_list[m] = ren[info_id].fri_list[m] * 10 + (shu[i] - '0');
			}
			else 
				ren[info_id].fri_list[m] = shu[i] - '0';
		}
		else 
		{
			if (shu[i - 1] >= '0' && shu[i - 1] <= '9')
				m++;
		}
	}
	m--;//最后会多一个
	ren[info_id].fri_list[0] = m;
	for (int i = 1; i <= m; i++)
	{
		pengyou[info_id][ren[info_id].fri_list[i]] = 1; 
		pengyou[ren[info_id].fri_list[0]][info_id] = 1;
	}
	//==========将cstring（数字用逗号隔开）转成int型数据，更新朋友列表end==============//

	hang++;
	CString s_id;
	s_id.Format(_T("%d"), info_id);
	p->m_list2.InsertItem(hang - 1, s_id);
	p->m_list2.SetItemText(hang - 1, 1, info_xingming);
	p->m_list2.SetItemText(hang - 1, 2, info_diqu);
	p->m_list2.SetItemText(hang - 1, 3, info_xuexiao);
	p->m_list2.SetItemText(hang - 1, 4, info_xingqu);
	p->m_list2.SetItemText(hang - 1, 5, info_friends);

	UpdateData(false);//将数据更新

	CDialogEx::OnOK();
}

void addperson::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//============================================================================================//

