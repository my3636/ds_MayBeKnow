
// zongheDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CzongheDlg 对话框
class CzongheDlg : public CDialogEx
{
// 构造
public:
	CzongheDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZONGHE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddpeopleButton();
	CListBox m_people_listbox;
//private:
	//CString info_person;
//	CListCtrl m_list2;
	afx_msg void OnBnClickeddelButton();
	afx_msg void OnLvnColumnclickList2(NMHDR *pNMHDR, LRESULT *pResult);
	int m_gx_id;
	afx_msg void OnBnClickedGxwlButton();
//	CListCtrl m_list_knrs;
	CListCtrl m_list2;
	CListCtrl m_list_knrs;
	afx_msg void OnBnClickedFindButton();
	afx_msg void OnLvnColumnclickListKnrs(NMHDR *pNMHDR, LRESULT *pResult);
};
enum { INT_TYPE = 0, STRING_TYPE, DOUBLE_TYPE };