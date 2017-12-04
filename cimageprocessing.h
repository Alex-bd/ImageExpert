#ifndef CIMAGEPROCESSING_H
#define CIMAGEPROCESSING_H
#include <opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
class CImageProcessing
{
public:
    CImageProcessing();
public:
    //TODO 计算统计直方图 参数~
    static int IpCalcHistorgram(Mat img, Mat mask,vector<Mat> outHistImage,vector<vector<int>> outHistData);

};

#endif // CIMAGEPROCESSING_H
