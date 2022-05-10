#include "Statement.h"

Statement::Statement()	
{ 
	Text = "";
	Selected = false;		
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

