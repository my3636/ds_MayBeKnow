
// zongheDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CzongheDlg �Ի���
class CzongheDlg : public CDialogEx
{
// ����
public:
	CzongheDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZONGHE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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