// addperson.cpp : ʵ���ļ�
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
	"����",
	"���",
	"�Ϻ�",
	"����",
	"�ӱ�",
	"ɽ��",
	"����",
	"����",
	"������",
	"����",
	"�㽭",
	"����",
	"����",
	"����",
	"ɽ��",
	"����",
	"����",
	"����",
	"�㶫",
	"����",
	"�Ĵ�",
	"����",
	"����",
	"����",
	"����",
	"�ຣ",
	"̨��",
	"���ɹ�",
	"����",
	"����",
	"����",
	"�½�",
	"���",
	"����"
};//34
char *school_name[20] =
{
	"�廪��ѧ",
	"������ѧ",
	"�й������ѧ",
	"�Ͽ���ѧ",
	"����ѧ",
	"�Ϻ���ͨ��ѧ",
	"������ѧ",
	"ͬ�ô�ѧ",
	"�㽭��ѧ",
	"�Ͼ���ѧ",
	"�人��ѧ",
	"��ɽ��ѧ",
};//12
char *hobby_name[12] =
{
	"��Ӿ","����","�赸","����","ƹ����",
	"��ë��","���","����","����","�ܲ�"
};//10

person ren[MAXN];
//========================================================================================//

// addperson �Ի���

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
	m_combo_xingqu.AddString(_T("��Ӿ"));
	m_combo_xingqu.AddString(_T("����"));
	m_combo_xingqu.AddString(_T("�赸"));
	m_combo_xingqu.AddString(_T("����"));
	m_combo_xingqu.AddString(_T("ƹ����"));
	m_combo_xingqu.AddString(_T("��ë��"));
	m_combo_xingqu.AddString(_T("���"));
	m_combo_xingqu.AddString(_T("����"));
	m_combo_xingqu.AddString(_T("����"));
	m_combo_xingqu.AddString(_T("�ܲ�"));
	// Ĭ��ѡ���һ��   
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


// addperson ��Ϣ�������


void addperson::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//CDialog* p = (CDialog*)::AfxGetMainWnd();//���Ի���ָ��
	CzongheDlg* p = (CzongheDlg*)::AfxGetMainWnd();//���Ի���ָ��

	info_id = GetDlgItemInt(IDC_ID_EDIT);
	ren[info_id].flag = true;

	GetDlgItemText(IDC_NAME_EDIT, info_xingming);//��ȡB�����пؼ������ݴ浽info_xingming
	ren[info_id].name = info_xingming;

	int nSel;
	nSel = m_combo_diqu.GetCurSel();// ��ȡ��Ͽ�ؼ����б����ѡ���������  
	m_combo_diqu.GetLBText(nSel, info_diqu);// ����ѡ����������ȡ�����ַ���   
	int i_diqu = m_combo_diqu.GetCurSel();// ���µ����б�
	city_list[i_diqu][0]++;//��ʾ�õ���Ŀǰ�м���
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

//==========��cstring�������ö��Ÿ�����ת��int������,���������б�==============//
	string str = CW2A(info_friends.GetString());
	int str_n;
	str_n = str.length();///�������Ŀ��ַ���
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
	m--;//�����һ��
	ren[info_id].fri_list[0] = m;
	for (int i = 1; i <= m; i++)
	{
		pengyou[info_id][ren[info_id].fri_list[i]] = 1; 
		pengyou[ren[info_id].fri_list[0]][info_id] = 1;
	}
	//==========��cstring�������ö��Ÿ�����ת��int�����ݣ����������б�end==============//

	hang++;
	CString s_id;
	s_id.Format(_T("%d"), info_id);
	p->m_list2.InsertItem(hang - 1, s_id);
	p->m_list2.SetItemText(hang - 1, 1, info_xingming);
	p->m_list2.SetItemText(hang - 1, 2, info_diqu);
	p->m_list2.SetItemText(hang - 1, 3, info_xuexiao);
	p->m_list2.SetItemText(hang - 1, 4, info_xingqu);
	p->m_list2.SetItemText(hang - 1, 5, info_friends);

	UpdateData(false);//�����ݸ���

	CDialogEx::OnOK();
}

void addperson::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

//============================================================================================//

