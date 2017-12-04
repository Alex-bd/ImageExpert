#include "cimageprocessing.h"

CImageProcessing::CImageProcessing()
{

}

int CImageProcessing::IpCalcHistorgram(Mat img, Mat mask,vector<Mat> outHistImage,vector<vector<int>> outHistData)
{
    float crange[] = {0,256};
    int histSize[] = {256};
    const float* ranges[] = {crange};
    int channels[] = {0};
    if(img.channels()==3)
    {

    }
    else
    {
		//todo
    }
    MatND hist;
    calcHist( &img, 1, channels, mask, hist, 2, histSize, ranges,true, false );
    double maxVal=0;
    minMaxLoc(hist, 0, &maxVal, 0, 0);

    return 0;
}
