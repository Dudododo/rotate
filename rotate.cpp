#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("1.jpg", 1);
	cv::Mat dstMat;

	//顺时针旋转50°,缩放尺度为1.5
	float angle = -50.0, scale = 1.5;
	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols * 0.5, srcMat.rows * 0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
	waitKey(0);
}