#pragma once

class IDevice;

class CExposeDlg : public CDialog
{
	DECLARE_DYNAMIC(CExposeDlg)

public:
	CExposeDlg(IDevice *pDevice, CWnd* pParent = NULL);
	virtual ~CExposeDlg();

	void UpdateDevice(IDevice *pDevice);
	void UpdateControls();
	CString GetPicPath(emDSFileType &type);

	enum { IDD = IDD_EXPOSE };

protected:
	virtual void OnOK(){}
	virtual void OnCancel(){}
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL ResetDevice(IDevice *pDevice, BOOL bInit = FALSE);
	void SetExposeTimeCtrl(USHORT usExposureTime);
	void SetAnalogGainCtrl(UCHAR uGain);
	void SetAETarget(BYTE nAETarget);
	void EnableUpdateControls(BOOL bShow = TRUE);

	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedChkAE();
	afx_msg void OnBnClickedBtnPicpath();
	afx_msg void OnBnClickedBtnOutputImage(UINT nID);
	afx_msg void OnBnClickedBtnSaveType(UINT nID);

	DECLARE_MESSAGE_MAP()
private:
	IDevice			*m_pDevice;

	CSliderCtrl		m_ctrlExposeTime;
	CSliderCtrl		m_ctrlAETarget;
	CSliderCtrl		m_ctrlGain;
};
