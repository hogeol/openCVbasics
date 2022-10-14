//stl
#include <iostream>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "adjustment.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_김호걸_과제1\\data\\"
#define IMG_NAME_1 "hyb.jpg"
#define IMG_NAME_2 "pth.jpg"
#define IMG_NAME_3 "kgw.jpg"
#define IMG_WIDTH 640
#define IMG_HEIGHT 480

/*세개의 영상과 𝛼, 𝛽 를 입력받아서 𝑔 𝑥, 𝑦 = 1 − 0.8 ∗ 𝛼 − 1.2 ∗ 𝛽 ∗ 𝑓1 𝑥, 𝑦 + 0.8 ∗ 𝛼 ∗ 𝑓2 𝑥, 𝑦 + 1.2 ∗ 𝛽 ∗ 𝑓3(𝑥, 𝑦) 를 계산해서 출력하시오*/

//int main(int argc, char** argv)
//{
//  Adjustment::adjustment adjustment_class;
//  double alpha = 0.0, beta = 0.0;
//  cv::Size image_size = cv::Size(IMG_WIDTH, IMG_HEIGHT);
//  std::string img1_path = IMG_PATH;
//  img1_path += IMG_NAME_1;
//  std::string img2_path = IMG_PATH;
//  img2_path += IMG_NAME_2;
//  std::string img3_path = IMG_PATH;
//  img3_path += IMG_NAME_3;
//  std::cout << "\nEnter an alpha value [1.0 - 3.0]: ";
//  std::cin >> alpha;
//  std::cout << "\nEnter a beta value [0 - 100]: ";
//  std::cin >> beta;
//  adjustment_class.init(alpha, beta, image_size);
//  if(!adjustment_class.loadImage(img1_path, img2_path, img3_path)){
//    return -1;
//  }
//  cv::Mat after_convert = cv::Mat::zeros(image_size, CV_8UC3);
//  adjustment_class.convertImage(after_convert);
//  cv::imshow("result", after_convert);
//  cvWaitKey(0);
//
//  return 0;
//}