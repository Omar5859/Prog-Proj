#include "Statement.h"

int Statement::ID_counter = 0;

Statement::Statement(Point P)
{
	ID = ID_counter++;
	Text = "";
	Selected = false;
	CenterPoint = P;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID()
{
	return ID;
}

pair<int, int> Statement::getvStatX()
{
	return vStatX;
}

pair<int, int> Statement::getvStatY()
{
	return vStatY;
}

void Statement::SetCenterPoint(Input* In)
{
	In->GetPointClicked(CenterPoint);
}

