///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"

std::vector<std::shared_ptr<AbsTransform>> AbsTransform::m_empty_transforms;


// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
	CompositeTransform* newClone = new CompositeTransform;

	for (auto child : m_transforms)
		newClone->addChild(child->clone());

	return newClone;
}

// Executer les transformations sur l'ensemble de l'arbre composite
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for (auto child : m_transforms)
		child->transform(c, outFile);
}
