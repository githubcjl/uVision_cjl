#pragma once
#include <IDevice.h>

class CROIDlg : public CDialog
{
	DECLARE_DYNAMIC(CROIDlg)
public:
	CROIDlg(IDevice *pDevice, CWnd* pParent = NULL);
	virtual ~CROIDlg();

	void UpdateDevice(IDevice *pDevice);
	void UpdateControls();

	enum { IDD = IDD_ROI };
protected:
	virtual void OnOK(){}
	virtual void OnCancel(){}
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL ResetDevice(IDevice *pDevice, BOOL bInit = FALSE);
	void EnablePresetResolutionCtrls(BOOL bEnable);
	void UpdateCurrentInfo(int offsetX, int offsetY, int iWidth, int iHeight);

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedSetROI();
	afx_msg void OnBnClickedMaximize();
	afx_msg void OnBnClickedRadResolution(UINT nID);
	afx_msg void OnEnKillfocusEdit(UINT nID);
	afx_msg void OnCbnSelchangeResolutionlist();

	DECLARE_MESSAGE_MAP()
private:
	IDevice					*m_pDevice;

	CSliderCtrl				m_ctrlOffseX;
	CSliderCtrl				m_ctrlOffseY;
	CSliderCtrl				m_ctrlWidth;
	CSliderCtrl				m_ctrlHeight;

	LPDeviceResolutionItem	m_lpDevRes;
	int						m_nResSize;
	int						m_nCulIndex;

	DeviceCapability		m_devCapability;
};
