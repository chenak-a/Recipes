///////////////////////////////////////////////////////////
//  SingleStep.cpp
//  Implementation of the Class SingleStep
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "SingleStep.h"

SingleStep::SingleStep(std::string description, int duration)
	: AbsStep(description, duration)
{
}

SingleStep* SingleStep::clone() const 
{
	// � compl�ter pour construire une nouvelle �tape simple en appelant le constructeur de copie
	SingleStep* cloneStep = new SingleStep(m_description, m_duration);
	return cloneStep; // � remplacer
}

std::ostream& SingleStep::printToStream(std::ostream& o) const 
{
	// � compl�ter pour imprimer sur un stream une �tape
	o << m_description << std::endl;
	return o;
}