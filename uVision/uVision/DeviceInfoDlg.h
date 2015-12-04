#pragma once
#include <IDevice.h>


class CDeviceInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeviceInfoDlg)
public:
	CDeviceInfoDlg(IDevice *pDevice, CWnd* pParent = NULL);
	virtual ~CDeviceInfoDlg();

	void UpdateDevice(IDevice *pDevice);

	enum { IDD = IDD_DEVICEINFO };
protected:
	virtual void OnOK(){}
	virtual void OnCancel(){}
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL ResetDevice(IDevice *pDevice, BOOL bInit = FALSE);

	afx_msg void OnBnClickedBtnWriteSN();

	DECLARE_MESSAGE_MAP()
private:
	IDevice			*m_pDevice;
};