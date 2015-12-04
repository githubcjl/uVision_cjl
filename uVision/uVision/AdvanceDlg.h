#pragma once
#include <IDevice.h>

class CSetupDlg;

class CAdvanceDlg : public CDialog
{
public:
	CAdvanceDlg(CWnd* pParent = NULL);
	~CAdvanceDlg();

	enum { IDD = IDD_CGUSBDEMO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	void DetectDevice();
	void ReceiveDataProc(BYTE *pImgData, int nWidth, int nHeight);
public:
	static void CALLBACK  InitReceiveDataProc(LPVOID pDevice, BYTE *pImageBuffer, DeviceFrameInfo *pFrInfo, LPVOID lParam);
protected:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedDetection();
	afx_msg void OnCbnSelchangeCameralist();
	
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedSetup();
	afx_msg void OnBnClickedSnap();
	afx_msg void OnBnClickedBtnOutputImage(UINT nID);
	afx_msg LRESULT OnUpdatePicture(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
private:
	HICON				m_hIcon;
	UINT				m_nFrames;
	UINT				m_nReconect;
	CSetupDlg			*m_pSetupDlg;
	BOOL				m_bPnP_Arrival;
	BOOL				m_bPnP_DevNodeChange;
	BOOL				m_bAspectRatio;

	IDevice				*m_pDevice;

	CCriticalSection	m_csImageData;

	BYTE				*m_pImageData;
	int					m_nDataSize;
	int					m_nWidth;
	int					m_nHeight;
};
