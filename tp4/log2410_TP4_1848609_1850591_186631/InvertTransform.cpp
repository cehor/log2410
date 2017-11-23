#include "InvertTransform.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
	Chunk_iterator chunkSortant(outFile, outFile.getNumberChunks());

	//recupération des donnees
	
	auto taille = c->size();	
	auto donneeEntrantes = c->get();
	auto donneeSortantes = chunkSortant->get();

	for (size_t i = 0; i < taille; i++){
		donneeSortantes[i] = donneeEntrantes[taille - 1 - i];
	}

	outFile.addChunk(chunkSortant);
}
