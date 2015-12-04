#pragma once
class IDevice;

class CImageProcessDlg : public CDialog
{
	DECLARE_DYNAMIC(CImageProcessDlg)

public:
	CImageProcessDlg(IDevice *pDevice, CWnd* pParent = NULL);
	virtual ~CImageProcessDlg();

	void UpdateDevice(IDevice *pDevice);
	void UpdateControls();

	enum { IDD = IDD_IMAGEPROCESS };

protected:
	virtual void OnOK(){}
	virtual void OnCancel(){}
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL ResetDevice(IDevice *pDevice, BOOL bInit = FALSE);
	void SetGainCtrl(UCHAR RGain, UCHAR GGain, UCHAR BGain);
	void SetGammaCtrl(FLOAT fGamma);
	void SetContrastCtrl(SHORT shContrast);
	void SetSaturationCtrl(BYTE nSaturation);
	void SetSpeedTuneCtrl(float fSpeedTune);

	afx_msg void OnClose();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedChkSaturation();
	afx_msg void OnCbnSelchangeCmbFrameSpeed();
	afx_msg void OnBnClickedHflip();
	afx_msg void OnBnClickedVflip();
	afx_msg void OnBnClickedMono();
	afx_msg void OnBnClickedInverse();
	afx_msg void OnBnClickedOnewb2();
	
	DECLARE_MESSAGE_MAP()
private:
	IDevice			*m_pDevice;

	CSliderCtrl		m_ctrlRGain;
	CSliderCtrl		m_ctrlGGain;
	CSliderCtrl		m_ctrlBGain;
	CSliderCtrl		m_ctrlGamma;
	CSliderCtrl		m_ctrlContrast;
	CSliderCtrl		m_ctrlSaturation;
	CSliderCtrl		m_ctrlFrameTune;
};
