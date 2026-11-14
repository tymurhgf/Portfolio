#pragma once

int* Create(int* mas, int size);

void CinArray(int* mas, int size);
void RandArray(int* mas, int size);

void ÑoutArray(int* mas, int size);

int* CompresArray(int* mas, int& size, int val);

int* AddBlockToArray(int* mas, int& size, int* block, int size_block, int pos);

int* DeleteBlockFromArray(int* mas, int& size, int size_block, int pos);
