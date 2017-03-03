#include "huffman.h"

int main()
{
	huffman::encode("medi.hfm","taiji.bmp");
	huffman::decode("ijiat.bmp","medi.hfm");
	return 0;
}
