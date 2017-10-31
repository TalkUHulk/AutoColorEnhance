#ifdef COLOR_ENHANCE_DLL_EXPORTS
#define COLOR_ENHANCE_API __declspec(dllexport)
#else
#define COLOR_ENHANCE_API __declspec(dllimport)
#endif
#include<iostream>

extern "C"
{
	typedef enum color_enhance_return_code{
		CE_SUCCESS = 0,//color_enhance成功
		IN_ERROR = -1,//输入指针为空
		INP_ERROR = -2,//输入参数（长 or 宽）不正确
		OUT_ERROR = -3,//输出指针为空
	}CER_code;

}

/*
函数功能@颜色增强
输入@pYuvSrc 指向YUV图像的指针
	 width、 height为输入YUV图像的宽和高
	 pYuvDst 指向颜色增强后的YUV指针，使用前需分配内存空间。

返回值@
     CE_SUCCESS = 0,//color_enhance成功
	 IN_ERROR = -1,//输入指针为空
	 INP_ERROR = -2,//输入参数（长 or 宽）不正确
	 OUT_ERROR = -3,//输出指针为空
*/
extern "C"
COLOR_ENHANCE_API  int color_enhance(const unsigned char* pYuvSrc, int width, int height, unsigned char* &pYuvDst);

