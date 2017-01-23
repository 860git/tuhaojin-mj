
#pragma once

#include "Game/Game/GamePlayer.h"
#include "GameLib/Game/GameLib.h"
#include "cocos2d.h"
#include "CMD_HNMJ.h"

struct OutCardInfo
{
	OutCardInfo(cocos2d::Node* pCard,int nData)
		:pCardNode(pCard)
		,nCardDarta(nData)
	{

	}
	cocos2d::Node* pCardNode;
	int           nCardDarta;
};

//游戏逻辑
class HNMJPlayer:public GamePlayer
{
public:
	const static int CARD_DWON_POSY = 70;
	const static int CARD_UP_POSY = 160;

	HNMJPlayer(int iIdex,cocos2d::Node* pSeatNode);
	~HNMJPlayer();

	void init();
	int  getIdex();
	void defaultState();
	void startGame();
	void EndGame();
	void setZhuang();
	void showAddGold(int iGold);
	void showEffect(std::string kKey);
	void showStatusImagic(std::string kKey);
	cocos2d::Node* getPlayerNode();
public:
	virtual void PlayerEnter();
	virtual void PlayerLeave();
	virtual void upPlayerInfo();
	virtual void upPlayerState();
public:
	void setHandCard(BYTE* pCardData,int iCout);
	void setWeaveItem(CMD_WeaveItem* pWeave,int iCout);
	void setOperateResoult(CMD_S_OperateResult* pNetInfo);
	void addNewInCard(int iCard);
	void sendOutCard(int iCard);
	void setActOutCard(int iCard,bool bDel = true);
	cocos2d::Node* addHandOutCard(int iCard);
	void showHandCard();
	void showHandCard(CMD_WeaveItem* pWeave,int iWeaveCout,BYTE* pHandCard,int iHandCout);
	void setCardImagic(cocos2d::Node* pNode,int kValue,std::string kImagicFront);
	cocos2d::Node* getTouchCardNode(cocos2d::Vec2 kTouchPos);
	BYTE getTouchCardVlaue(cocos2d::Node* pNode);
	void showHuPai(bool bZiMo);
public:
	void removeHandOutCard(BYTE cbCardData);
	void showCard();
	void showCard(BYTE* cbCardData,BYTE cbCardCount);
	void showJieSuanCard(cocos2d::Node* pCardNode,CMD_WeaveItem* pWeave,int iWeaveCout,BYTE* pHandCard,int iHandCout);
	void setChiHuCard(BYTE cbCard);
	BYTE getChiHuCard();
public:
	BYTE getGangCard(BYTE currentCard);
	void seatDownCard();
	void ClickCard(cocos2d::Node* pCard);

	void runAniDianPao();
	void runAniZiMo();
	void runAniPeng();
	void runAniMingGang();
	void runAniAnGang();
	void runAniChi();

private:
	int						m_iIdex;
	cocos2d::Node*			m_pSeatNode;

	BYTE					m_kHandCardData[MAX_COUNT];
	BYTE					m_kHandCardCout;

	CMD_WeaveItem			m_kWeaveItemArray[MAX_WEAVE];		//组合扑克
	BYTE					m_kWeaveCount;					//组合数目

//	int						m_iOutCardCout;

	std::vector<OutCardInfo>  m_kOutCardList;

	BYTE                  m_cbChiHuCard;//所胡的牌
	cocos2d::Node*         m_pHandOutCard;
};

