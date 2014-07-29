#ifndef CHARMVALUE_EXCHANGE_HEAD_FILE
#define CHARMVALUE_EXCHANGE_HEAD_FILE

#include "PropertyModule.h"

#pragma once

//////////////////////////////////////////////////////////////////////////

//兑换金币 
class PROPERTY_MODULE_CLASS CCharmValueExchange : public CSkinDialogEx
{
	//变量定义
public:
	tagUserData						*m_pMeUserData;					//用户信息
	DWORD							m_lLoveliness;					//用户魅力
	LONGLONG							m_lBankGoldValue;				//银行金币
	DWORD							m_lExchangeCharmValue;			//对换魅力
	CString							m_strExChangeValue;				//对换比率

	//控件变量
protected:
	CSkinButton						m_btOK;							//确定按钮
	CSkinButton						m_btCancel;						//取消按钮

	//接口变量
protected:	
	IClientKernel					* m_pIClientKernel;				//内核接口
	ITCPSocket						* m_pClientSocket;				//网络接口

	//基础函数
public:
	//构造函数
	CCharmValueExchange(CWnd* pParent = NULL); 
	//析构函数
	virtual ~CCharmValueExchange();

	//辅助函数
public:
	//更新界面
	void UpdateView();

	//重载函数
protected:
	//控件绑定
	virtual void DoDataExchange(CDataExchange* pDX);
	//初始化函数
	virtual BOOL OnInitDialog();
	//确定信息
	afx_msg void OnBnClickedBtExchange();
	//鼠标信息
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//鼠标信息
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//命令信息
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//时间消息
	afx_msg void OnTimer(UINT nIDEvent);
	//输入信息
	afx_msg void OnEnChangeExchangeCharmValue();
	//设置颜色
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//绘画函数
	afx_msg void OnPaint();

	//功能函数
public:
	//设置组件
	void SetSendInfo(IClientKernel *pClientKernel,ITCPSocket *pClientSocket,tagUserData *pUserData);
	//发送信息
	void SendData(WORD wMainCmdID, WORD wSubCmdID, void * pBuffer, WORD wDataSize);

	DECLARE_MESSAGE_MAP()
};
//////////////////////////////////////////////////////////////////////////

//兑换魅力
extern "C" PROPERTY_MODULE_CLASS VOID __cdecl ShowCharmValueExchangeDlg(IClientKernel *pIClientKernel,ITCPSocket *pClientSocket,tagUserData *pUserData);

//////////////////////////////////////////////////////////////////////////
#endif