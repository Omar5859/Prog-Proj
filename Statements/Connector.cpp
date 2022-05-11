#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the flowchart
{
	SrcStat = Src;
	DstStat = Dst;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::SetSelected(bool s)
{
	Selected = s;
}

bool Connector::IsSelected() const
{
	return Selected;
}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector(Start, End, Selected);
}

