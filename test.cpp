#include <iostream>
#include <fstream>
#include"color_enhance.h"
using namespace std;

#pragma(lib,"color_enhance.lib");

const int width = 1920;
const int height = 1080;
const int framesize = width * height * 3 / 2;
extern "C"
int color_enhance(const unsigned char* pYuvSrc, int width, int height, unsigned char* &pYuvDst);

int main()
{
	ifstream fin;
	fin.open("lxq_420.yuv", ios_base::in | ios_base::binary);
	if (fin.fail())
	{
		cout << "the file is error" << endl;
		return -1;
	}

	fin.seekg(0, ios::end);
	streampos ps = fin.tellg();
	unsigned long NumberPixe = ps;
	cout << "file size: " << ps << endl;
	unsigned FrameCount = ps / framesize;
	cout << "frameNuber: " << FrameCount;
	fin.close();

	FILE* fileIn = fopen("lxq_420.yuv", "rb+");
	FILE* fileOut = fopen("D://lxq_420ce3.yuv", "wb+");

	unsigned char* pYuvBuf = new unsigned char[framesize];
	unsigned char* pYuvDst = new unsigned char[framesize];

	unsigned char* pUBuf;
	unsigned char* pVBuf;

	for (int i = 0; i < FrameCount; ++i)
	{
		fread(pYuvBuf, framesize * sizeof(unsigned char), 1, fileIn);

		color_enhance(pYuvBuf, width, height, pYuvDst);

		fwrite(pYuvDst, framesize * sizeof(unsigned char), 1, fileOut);
	}
	fclose(fileIn);
	fclose(fileOut);
	delete[]pYuvBuf;
	delete[]pYuvDst;

	return 0;
}