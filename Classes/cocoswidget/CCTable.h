/****************************************************************************
Copyright (c) 2013 viva

Created by Li JunLin on 2013

csdn_viva@foxmail.com
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCWIDGET_TABLE_H__
#define __CCWIDGET_TABLE_H__

/////////////////////////////////////////////////////////////////////////////
/// BugFix : [1]
/// 
/////////////////////////////////////////////////////////////////////////////

#include "cocos2d.h"
#include "CCWidgetMacros.h"
#include "CCWidget.h"
#include "CCScroll.h"
#include <list>
#include <vector>
#include <set>

NS_CC_WIDGET_BEGIN

class CCTable;
class CCTableCell;

/**
 * ���� : SEL_TableDataSourceHandler
 * ���� : �б�ؼ����������ⲿ�ص�����
 * ���� : pTable - ���ñ������Ŀؼ�
 *        idx - Ŀǰ���ڴ���ڼ����б���
 * ��� : �б���
 */
typedef CCTableCell* (CCObject::*SEL_TableDataSourceHandler)(CCTable* pTable, unsigned int idx);
#define tabledatasource_selector(__SELECTOR__) (cocos2d::cocoswidget::SEL_TableDataSourceHandler)(&__SELECTOR__)

/**
 * ���� : CCTableCell
 * ���� : [����]-Viva
 * ���� : csdn_viva@foxmail.com
 * ���� : �б���ؼ����ַ��¼�
 */
class CCTableCell : public CCPanel
{
public:
    CCTableCell();
    virtual ~CCTableCell();

	/**
	 * ���� : getIdx()
	 * ���� : ��ȡ�б�����±�
	 * ���� : 
	 * ��� : �±�
	 */
    unsigned int getIdx() { return m_uIdx; }

	/**
	 * ���� : setIdx()
	 * ���� : �����б�����±�
	 * ���� : uIdx - �±�
	 * ��� : 
	 */
    void setIdx(unsigned int uIdx) { m_uIdx = uIdx; }

	/**
	 * ���� : reset()
	 * ���� : ���б���������״̬��ʱ�����״̬
	 * ���� : 
	 * ��� : 
	 */
    virtual void reset(){ m_uIdx = CC_INVALID_INDEX; }
    
protected:
	/// �б��±�
    unsigned int m_uIdx;
};

/**
 * ���� : CCTable
 * ���� : [����]-Viva
 * ���� : csdn_viva@foxmail.com
 * ���� : �б�ؼ�
 */
class CCTable : public CCScroll
{
public:
    CCTable();
    virtual ~CCTable();

	/**
	 * ���� : setCountOfCell()
	 * ���� : �����б�������� ��ҪreloadData��Ч
	 * ���� : uCellsCount - ����
	 * ��� : 
	 */
    void setCountOfCell(unsigned int uCellsCount);

	/**
	 * ���� : getCountOfCell()
	 * ���� : ��ȡ�б�������� ��ҪreloadData��Ч
	 * ���� : 
	 * ��� : ����
	 */
    unsigned int getCountOfCell() const;

	/**
	 * ���� : setSizeOfCell()
	 * ���� : �����б���Ĵ�С ��ҪreloadData��Ч
	 * ���� : tCellsSize - �б���Ĵ�С
	 * ��� : 
	 */
    void setSizeOfCell(const CCSize& tCellsSize);

	/**
	 * ���� : getSizeOfCell()
	 * ���� : ��ȡ�б���Ĵ�С ��ҪreloadData��Ч
	 * ���� : 
	 * ��� : �б���Ĵ�С
	 */
    const CCSize& getSizeOfCell() const;

	/**
	 * ���� : setDataSourceSelector()
	 * ���� : �����б�ؼ��������ⲿ�ص�����
	 * ���� : pTarget - �������
	 *        pDataSourceHandler - ������
	 * ��� : 
	 */
    void setDataSourceSelector(CCObject* pTarget, SEL_TableDataSourceHandler pDataSourceHandler);

	/**
	 * ���� : isAutoRelocate()
	 * ���� : ��ȡ�Ƿ��Զ����뵽Cell;
	 * ���� : 
	 * ��� : �Ƿ��Զ�����
	 */
	bool isAutoRelocate() const;

	/**
	 * ���� : setAutoRelocate()
	 * ���� : �����Ƿ��Զ����뵽Cell;
	 * ���� : bAuto - �Ƿ��Զ�����
	 * ��� : 
	 */
	void setAutoRelocate(bool bAuto);

	/**
	 * ���� : getAutoRelocateSpeed()
	 * ���� : ��ȡ�Զ�����cellʱ���ٶ�
	 * ���� : 
	 * ��� : �Զ�������ٶ�
	 */
	float getAutoRelocateSpeed() const;

	/**
	 * ���� : setAutoRelocateSpeed()
	 * ���� : �����Զ�����cellʱ���ٶ�
	 * ���� : fSpeed - �Զ�������ٶ�
	 * ��� : 
	 */
	void setAutoRelocateSpeed(float fSpeed);

	/**
	 * ���� : initWithParams()
	 * ���� : ͨ��������ʼ��
	 * ���� : tViewSize - ���ӷ�Χ��С
	 *        tCellSize - ÿһ��Ĵ�С
	 *        uCellCount - �ܹ��ж�����
	 *        pTarget - ���ݺ����������
	 *        pDataSourceHandler - ���ݺ���
	 * ��� : �Ƿ��ʼ���ɹ�
	 */
	bool initWithParams(const CCSize& tViewSize, const CCSize& tCellSize, unsigned int uCellCount, 
		CCObject* pTarget, SEL_TableDataSourceHandler pDataSourceHandler);
		
    static CCTable* create(const CCSize& tViewSize);
	static CCTable* create(const CCSize& tViewSize, const CCSize& tCellSize, unsigned int uCellCount, 
		CCObject* pTarget, SEL_TableDataSourceHandler pDataSourceHandler);

public:
	/**
	 * ���� : getCells()
	 * ���� : ��ȡ�����б���
	 * ���� : 
	 * ��� : �����б���
	 */
	CCArray* getCells();

	/**
	 * ���� : cellAtIndex()
	 * ���� : ��ȡ�б��� ͨ���±꣬������cellû�б�ʹ�ã��򷵻�NULL
	 * ���� : idx - �±�
	 * ��� : �б���
	 */
	CCTableCell* cellAtIndex(unsigned int idx);

	/**
	 * ���� : dequeueCell()
	 * ���� : �����ؼ��б������ͷ�����б���
	 * ���� : 
	 * ��� : �б���
	 */
    CCTableCell* dequeueCell();

	/**
	 * ���� : reloadData()
	 * ���� : ���¼�������
	 * ���� : 
	 * ��� : 
	 */
	void reloadData();
    
protected:
	/**
	 * ���� : executeDataSource()
	 * ���� : ִ���ⲿ���ݺ���
	 * ���� : pTable - ���ؼ�
	 *        idx - ��ǰ������б����±�
	 * ��� : �б���
	 */
    CCTableCell* executeDataSource(CCTable* pTable, unsigned int idx);

	/**
	 * ���� : onScrolling()
	 * ���� : �������ؼ�����ʱ����
	 * ���� : 
	 * ��� : 
	 */
    virtual void onScrolling();

	/**
	 * ���� : onDeaccelerateScrollEnded()
	 * ���� : �������ؼ����ٹ������ʱ����
	 * ���� : 
	 * ��� : 
	 */
	virtual void onDeaccelerateScrollEnded();

	/**
	 * ���� : onDeaccelerateScrollEnded()
	 * ���� : �������ؼ���ק�������ʱ����
	 * ���� : 
	 * ��� : 
	 */
	virtual void onDraggingScrollEnded();

protected:
	void removeAllFromUsed();
    void removeAllFromFreed();
	void insertSortableCell(CCTableCell* pCell, unsigned int idx);
	unsigned int cellBeginIndexFromOffset(const CCPoint& offset);
	unsigned int cellEndIndexFromOffset(const CCPoint& offset);
	CCPoint cellPositionFromIndex(unsigned int idx);
	void updateCellAtIndex(unsigned int idx);
	void updatePositions();

protected:
    CCSize m_tCellsSize;
    unsigned int m_uCellsCount;
	bool m_bAutoRelocate;
	float m_fAutoRelocateSpeed;
    
	std::set<unsigned int>* m_pIndices;
	std::vector<float>* m_pPositions;
	std::list<CCTableCell*>* m_pCellsUsed;
	std::list<CCTableCell*>* m_pCellsFreed;
    
    SEL_TableDataSourceHandler m_pDataSourceHandler;
    CCObject* m_pDataSourceListener;
};

NS_CC_WIDGET_END

#endif //__CCWIDGET_TABLEVIEW_H__
