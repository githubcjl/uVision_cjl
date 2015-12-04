#include "stdafx.h"
#include <shlwapi.h>
#include "Advance.h"
#include "AdvanceDlg.h"
#include "SetupDlg.h"

#pragma comment(lib,"shlwapi.lib")

#define WM_UPDATE_PICTURE	(WM_APP + 0x100)

#define NODETECTDEVICETEXT	_T("No Detect Device")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

CAdvanceDlg::CAdvanceDlg(CWnd* pParent /*=NULL*/)
: CDialog(CAdvanceDlg::IDD, pParent), m_nFrames(0), m_pSetupDlg(NULL), m_nReconect(0)
, m_pDevice(NULL), m_pImageData(NULL), m_nDataSize(0), m_nWidth(0), m_nHeight(0)
, m_bPnP_Arrival(FALSE), m_bPnP_DevNodeChange(FALSE), m_bAspectRatio(TRUE)
{
	//IDevice::DeviceInitialSDK(NULL, FALSE);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CAdvanceDlg::~CAdvanceDlg()
{
	if(m_pDevice != NULL){
		m_pDevice->Release();
	}
	IDevice::DeviceUnInitialSDK();
	if(m_pImageData != NULL)
		delete []m_pImageData;
	if(m_pSetupDlg != NULL)
		delete m_pSetupDlg;
}

void CAdvanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CAdvanceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CRect rcWnd(0, 0, 640, 535);
	CalcWindowRect(&rcWnd);
	SetWindowPos(NULL, 0, 0, rcWnd.Width(), rcWnd.Height(), SWP_NOMOVE|SWP_NOZORDER);

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	
	DetectDevice();
	return TRUE;
}

void CAdvanceDlg::DetectDevice()
{
	CComboBox *pCombo = (CComboBox *)GetDlgItem(IDC_CAMERALIST);
	int nIndex = pCombo->GetCurSel();
	UCHAR usbDev = 0;
	int nSelect = 0;
	if(nIndex != CB_ERR){
		CString strText;
		pCombo->GetLBText(nIndex, strText);
		if(strText.Compare(NODETECTDEVICETEXT) != 0 && m_pDevice != NULL){
			usbDev = HIBYTE(pCombo->GetItemData(nIndex));
		}else nIndex = CB_ERR;
	}
	pCombo->ResetContent();
	INT nDevice = 0;
	if(SUCCEEDED(IDevice::EnumDevice(NULL, &nDevice))){
		if(nDevice == 0){
			pCombo->AddString(NODETECTDEVICETEXT);
		}else{
			LPEnumDeviceParam lpEDP = new EnumDeviceParam[nDevice];
			if(lpEDP != NULL){
				if(SUCCEEDED(IDevice::EnumDevice(lpEDP, &nDevice))){
					int nIndex = CB_ERR;
					CString strText;
					for(int i = 0; i < nDevice; ++i){
						strText.Format(_T("%s : %d"), lpEDP[i].lpDeviceDesc, lpEDP[i].index);
						nIndex = pCombo->AddString(strText);
						if(nIndex != CB_ERR){
							pCombo->SetItemData(nIndex, MAKEWORD(lpEDP[i].devIndex, lpEDP[i].usbAddress));
							if(usbDev == lpEDP[i].usbAddress){
								nSelect = i;
							}
						}
					}
				}
				delete []lpEDP;
			}
		}
		pCombo->SetCurSel(nSelect);
		if(m_pDevice == NULL){
			OnCbnSelchangeCameralist();
			//OnBnClickedPlay();
		}
	}
}

void CAdvanceDlg::ReceiveDataProc(BYTE *pImgData, int nWidth, int nHeight)
{
	++m_nFrames;
	int nDataSize = (((nWidth * 24 + 31) & ~31) >> 3) * nHeight;
	if(m_pImageData != NULL && nDataSize != m_nDataSize){
		delete []m_pImageData;
		m_pImageData = NULL;
	}
	if(m_pImageData == NULL){
		m_nDataSize = nDataSize;
		m_pImageData = new BYTE[m_nDataSize];
		m_nWidth = nWidth;
		m_nHeight = nHeight;
	}
	m_csImageData.Lock();
	memcpy(m_pImageData, pImgData, nDataSize);
	m_csImageData.Unlock();
	PostMessage(WM_UPDATE_PICTURE);
}

void CALLBACK  CAdvanceDlg::InitReceiveDataProc(LPVOID pDevice, BYTE *pImageBuffer, DeviceFrameInfo *pFrInfo, LPVOID lParam)
{
	BYTE *pRGB24Buff = NULL;
	if((pRGB24Buff = ((IDevice *)pDevice)->DeviceISP(pImageBuffer, pFrInfo)) != NULL)
		((CAdvanceDlg *)lParam)->ReceiveDataProc(pRGB24Buff, pFrInfo->uiWidth, pFrInfo->uiHeight);
}

BEGIN_MESSAGE_MAP(CAdvanceDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_CAMERALIST, OnCbnSelchangeCameralist)
	ON_BN_CLICKED(IDC_PLAY, OnBnClickedPlay)
	ON_BN_CLICKED(IDC_STOP, OnBnClickedStop)
	ON_BN_CLICKED(IDC_SETUP, OnBnClickedSetup)
	ON_BN_CLICKED(IDC_SNAP, OnBnClickedSnap)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RAD_ASPECTRATIO, IDC_RAD_FIXWINDOW, OnBnClickedBtnOutputImage)
	ON_MESSAGE(WM_UPDATE_PICTURE, OnUpdatePicture)
END_MESSAGE_MAP()

void CAdvanceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CAdvanceDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if(SIZE_MINIMIZED != nType){
		CRect rcCtrl;
		CWnd *pCtrl = GetDlgItem(IDC_PICTURE);
		if(pCtrl != NULL){
			pCtrl->GetWindowRect(&rcCtrl);
			ScreenToClient(&rcCtrl);
			pCtrl->SetWindowPos(NULL, 0, 0, cx, cy - rcCtrl.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}
	if(m_pDevice == NULL) Invalidate();
}

void CAdvanceDlg::OnDestroy()
{
	if(m_pDevice != NULL){
		m_pDevice->Stop();
		m_pDevice->CloseDevice();
		m_pDevice->DeviceUnInit();
		m_pDevice->Release();
		m_pDevice = NULL;
	}
	CDialog::OnDestroy();
}

void CAdvanceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CAdvanceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAdvanceDlg::OnBnClickedDetection()
{
	DetectDevice();
}

void CAdvanceDlg::OnCbnSelchangeCameralist()
{
	CComboBox *pCombo = (CComboBox *)GetDlgItem(IDC_CAMERALIST);
	int nIndex = pCombo->GetCurSel();
	if(nIndex != CB_ERR){
		CString strText;
		pCombo->GetLBText(nIndex, strText);
		if(strText.Compare(NODETECTDEVICETEXT) != 0){
			UCHAR dev = LOBYTE(pCombo->GetItemData(nIndex));
			if(m_pSetupDlg != NULL) m_pSetupDlg->UpdateDevice(NULL);
			if(m_pDevice != NULL){
				m_pDevice->Stop();
				m_pDevice->Release();
				m_pDevice = NULL;
			}
			if(m_pDevice == NULL){
				UionOpenDeviceParam param;
				param.devIndex = dev;
				DeviceStatus devStatus = IDevice::OpenDevice(param, &m_pDevice);
				if(SUCCEEDED(devStatus)){
					devStatus = m_pDevice->DeviceInitEx(InitReceiveDataProc, this, NULL, TRUE);
					if(m_pSetupDlg != NULL) m_pSetupDlg->UpdateDevice(m_pDevice);
				}
				if(FAILED(devStatus)){
					CString strText;
					strText.Format(_T("Error Code: %d"), devStatus);
					::AfxMessageBox(strText, MB_ICONERROR|MB_OK);
				}else{
					OnBnClickedPlay();
				}
			}
		}
	}
}

void CAdvanceDlg::OnBnClickedPlay()
{
	if(m_pDevice != NULL && !m_pDevice->IsReceivingData()){
		DeviceStatus devStatus = m_pDevice->Start();
		if(FAILED(devStatus)){
			CString strText;
			strText.Format(_T("Error Code: %d"), devStatus);
			::AfxMessageBox(strText, MB_ICONERROR|MB_OK);
		}
	}
}

void CAdvanceDlg::OnBnClickedStop()
{
	if(m_pDevice != NULL && m_pDevice->IsReceivingData()){
		m_pDevice->Stop();
		Invalidate(TRUE);
	}
}

void CAdvanceDlg::OnBnClickedSetup()
{
	if(m_pDevice != NULL){
		if(m_pSetupDlg == NULL) m_pSetupDlg = new CSetupDlg(m_pDevice, this);
		if(m_pSetupDlg->GetSafeHwnd() == NULL){
			m_pSetupDlg->Create(IDD_SETUP, NULL);
			m_pSetupDlg->Invalidate();
		}
		m_pSetupDlg->ShowWindow(TRUE);
	}
}

void CAdvanceDlg::OnBnClickedSnap()
{
	if(m_pDevice != NULL ){
		emDSFileType type = FILE_BMP;
		CString strPath = (m_pSetupDlg != NULL ? m_pSetupDlg->GetPicPath(type) : _T(""));
		if(strPath.IsEmpty()){
			GetModuleFileName(NULL, strPath.GetBuffer(256), 256);
			strPath.ReleaseBuffer();
			int nPos = strPath.ReverseFind(_T('\\'));
			strPath = strPath.Left(nPos + 1);
			strPath.Append(_T("Pic\\"));
		}
		if (!PathIsDirectory(strPath))
			CreateDirectory(strPath, NULL);
		CTime time = CTime::GetCurrentTime();
		CString sfilename; 
		sfilename.Format(_T("%sImage_%02d%02d%02d%02d%02d"), strPath, time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
		if(SUCCEEDED(m_pDevice->CaptureFile(sfilename, type))){
			AfxMessageBox(_T("ÅÄÕÕ³É¹¦!"));
		}
	}
}

void CAdvanceDlg::OnBnClickedBtnOutputImage(UINT nID)
{
	m_bAspectRatio = (IDC_RAD_ASPECTRATIO == nID);
}

LRESULT CAdvanceDlg::OnUpdatePicture(WPARAM wParam, LPARAM)
{
	CWnd *pWnd = GetDlgItem(IDC_PICTURE);
	if(pWnd != NULL){
		if(wParam == 0){
			CRect rcClient;
			pWnd->GetClientRect(&rcClient);
			int x = 0, y = 0, width = rcClient.right, height = rcClient.bottom;
			if(m_bAspectRatio){
				if(width < m_nWidth || height < m_nHeight){
					float fXScale = (float)width/(float)m_nWidth, fYScale = (float)height/(float)m_nHeight;
					if(fXScale > fYScale) fXScale = fYScale;
					width = (int)(fXScale * (float)m_nWidth);
					height = (int)(fXScale * (float)m_nHeight);
					if(width == 0) width = 1;
					if(height == 0) height = 1;
					if(width < rcClient.right) x = (rcClient.right - width)/2;
					if(height < rcClient.bottom) y = (rcClient.bottom - height)/2;
				}else{
					x = (width - m_nWidth)/2; width = m_nWidth;
					y = (height - m_nHeight)/2; height = m_nHeight;
				}
			}
			CDC *pDC = pWnd->GetDC();
			if(x > 0 || y > 0){
				CRgn rgn;
				rgn.CreateRectRgn(x, y, x + width, y + height);
				pDC->SelectClipRgn(&rgn, RGN_DIFF);
				pDC->FillSolidRect(0, 0, rcClient.right,rcClient.bottom, 0x808080);
				pDC->SelectClipRgn(NULL, RGN_COPY);
			}
			pDC->SetStretchBltMode(COLORONCOLOR);
			BITMAPINFO bmpInfo = {{sizeof(BITMAPINFOHEADER), m_nWidth, -m_nHeight, 1, 24, BI_RGB, 0, 0, 0, 0, 0}};
			m_csImageData.Lock();
			::StretchDIBits( pDC->GetSafeHdc(), x, y, width, height, 0, 0, m_nWidth, m_nHeight,
					m_pImageData, &bmpInfo, DIB_RGB_COLORS, SRCCOPY );
			m_csImageData.Unlock();
			pWnd->ReleaseDC(pDC);
		}else{
			InvalidateRect(NULL);
		}
	}
	return 0;
}
