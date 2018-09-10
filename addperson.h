#pragma once
#include "afxwin.h"
#include <string>
using namespace std;


// addperson 对话框

class addperson : public CDialogEx
{
	DECLARE_DYNAMIC(addperson)

public:
	addperson(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~addperson();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_REN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString input_name;
	CComboBox m_combo_diqu;
	CComboBox m_combo_xuexiao;
	CComboBox m_combo_xingqu;
	CString input_friends;
	int input_id;
};