//stl
#include <iostream>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "histogram.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_��ȣ��_����1\\data\\"
#define IMG_NAME "hyb.jpg"
#define IMG_WIDTH 640
#define IMG_HEIGHT 480

/*calcHist�� ������� �ʰ� �÷� ������ ������׷��� ���ؼ� ȭ�鿡 �׸���, ������׷� bin�� ����� 40, 80, 120, 256 �� �ϳ��� �Է¹޾Ƽ� ����ϵ��� �ۼ��Ͻÿ�*/

//int main(int argc, char** argv)
//{
//  Histogram::histogram histogram_class;
//  std::string image_path = IMG_PATH;
//  image_path += IMG_NAME;
//  cv::Size image_size(IMG_WIDTH, IMG_HEIGHT);
//  int bin = 0;
//  std::cout << "\nEnter a histogram bin size one of [40, 80, 120, 256]: ";
//  std::cin >> bin;
//  histogram_class.init(image_path, image_size, bin, true);
//  histogram_class.drawHistogram();
//  cv::imshow("image", histogram_class.mp_image);
//  cv::imshow("histogram", histogram_class.mp_histogram_image);
//  cv::waitKey(0);
//  return 0;
//}