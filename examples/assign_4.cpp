//stl
#include <iostream>
#include <string>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "histogramStretching.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_��ȣ��_����1\\data\\"
#define IMG_NAME "lina.jpg"
#define IMG_WIDTH 640
#define IMG_HEIGHT 480

/*������׷� ��Ʈ��Ī���� r1, r2, r3�� s1, s2, s3�� �Է¹޾Ƽ� ���� �׸�ó�� ������׷� ��Ʈ��Ī�� �ǵ��� �����Ͻÿ�*/

//int main(int argc, char** argv)
//{
//  HistogramStretching::histogramStretching histogram_stretching_class;
//  std::string img_path = IMG_PATH;
//  img_path += IMG_NAME;
//  cv::Size img_size(IMG_WIDTH, IMG_HEIGHT);
//  int r1 = 0, r2 = 0, s1 = 0, s2 = 0;
//  std::cout << "Enter a r1: ";
//  std::cin >> r1;
//  std::cout << "Enter a r2: ";
//  std::cin >> r2;
//  std::cout << "Enter a s1: ";
//  std::cin >> s1;
//  std::cout << "Enter a s2: ";
//  std::cin >> s2;
//  if (!histogram_stretching_class.init(img_path, img_size, r1, s1, r2, s2)) {
//    return -1;
//  }
//  histogram_stretching_class.imageStretch();
//  cv::imshow("stretch_image", histogram_stretching_class.mp_stretch_image);
//  cv::waitKey(0);
//  return 0;
//}