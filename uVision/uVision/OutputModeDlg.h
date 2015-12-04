#pragma once
#include <IDevice.h>

class COutputModeDlg : public CDialog
{
	DECLARE_DYNAMIC(COutputModeDlg)
public:
	COutputModeDlg(IDevice *pDevice, CWnd* pParent = NULL);
	virtual ~COutputModeDlg();

	void UpdateDevice(IDevice *pDevice);
	void UpdateControls();
	void SetCaptureModeCtrl(emDeviceCaptureMode mode);
	void SetDataTypeCtrl(emDeviceDataType dataType);

	enum { IDD = IDD_OUTPUTMODE };
protected:
	virtual void OnOK(){}
	virtual void OnCancel(){}
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL ResetDevice(IDevice *pDevice, BOOL bInit = FALSE);

	afx_msg void OnBnClickedSoftTrigger();
	afx_msg void OnCbnSelchangeCmbOutputMode();
	afx_msg void OnCbnSlechangeCmbDataType();
	afx_msg void OnEnKillfocusEdtSoftTriggerFrameNum();
	afx_msg void OnEnChangeoftTriggerFrameNum();

	DECLARE_MESSAGE_MAP()
private:
	IDevice			*m_pDevice;
	CSpinButtonCtrl	m_spinTriggerFrameNum;
};