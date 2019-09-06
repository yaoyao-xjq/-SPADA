#include "Arrow.h"


CArrow::CArrow(void)
{
	m_hArrowWhite=0;
	m_hArrowBlack=0;
	m_hArrowWhitey=0;
	m_hArrowBlacky=0;
	point.x=0;
	point.y=0;
	ArrowStyle=0;
	flag=false;
}


CArrow::~CArrow(void)
{
	::DeleteObject(m_hArrowWhite);
	m_hArrowWhite=0;
	::DeleteObject(m_hArrowBlack);
	m_hArrowBlack=0;
	::DeleteObject(m_hArrowWhitey);
	m_hArrowWhitey=0;
	::DeleteObject(m_hArrowBlacky);
	m_hArrowBlacky=0;

}
