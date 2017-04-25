#pragma once
#ifndef EMBEDITEM_H
#define EMBEDITEM_H

#include "BaseItem.h"

class CMenuItemsHolder : public CMenuBaseItem
{
public:
	CMenuItemsHolder();

	void Init();
	void VidInit();
	virtual const char *Key( int key, int down );
	virtual void Char( int key );
	virtual const char *Activate( void );
	virtual void ToggleInactive( void );
	virtual void SetInactive( bool visible );
	virtual void Draw( void );

	virtual void MouseMove( int x, int y );

	virtual void Show();
	virtual void Hide();
	virtual bool IsVisible();

	void CursorMoved( void );
	void SetCursor( int newCursor, bool notify = true );
	void SetCursorToItem( CMenuBaseItem *item, bool notify = true );
	void AdjustCursor( int dir );

	void AddItem( CMenuBaseItem &item );
	CMenuBaseItem *ItemAtCursor( void );
	CMenuBaseItem *ItemAtCursorPrev( void );

	inline int GetCursor() const { return m_iCursor; }
	inline int GetCursorPrev() const { return m_iCursorPrev; }
	inline int ItemCount() const { return m_numItems; }
	inline bool WasInit() const { return m_bInit; }

protected:
	virtual void _Init() {}
	virtual void _VidInit() {}

	int m_iCursor;
	int m_iCursorPrev;

	CMenuBaseItem *m_pItems[UI_MAX_MENUITEMS];
	int m_numItems;
	bool m_bInit;
private:
};

#endif // EMBEDITEM_H
