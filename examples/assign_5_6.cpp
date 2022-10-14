//stl
#include <iostream>
#include <string>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "histogramEqualize.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_±èÈ£°É_°úÁ¦1\\data\\"
#define IMG_NAME "pth.jpg"
#define IMG_WIDTH 640
#define IMG_HEIGHT 480

int main(int argc, char** argv)
{
  HistogramEqualize::histogramEqualize histogram_equalize_class;
  std::string image_path = IMG_PATH;
  image_path += IMG_NAME;
  cv::Size image_size(IMG_WIDTH, IMG_HEIGHT);
  double threshold_value = 0.0;
  std::cout << "Enter a threshold_value [0 - 255]: ";
  std::cin >> threshold_value;
  if (!histogram_equalize_class.init(image_path, image_size,threshold_value)) {
    return -1;
  }
  histogram_equalize_class.equailze();
  histogram_equalize_class.setThreshold();
  histogram_equalize_class.setThresholdOtsu();
  histogram_equalize_class.displayHistogram();
  histogram_equalize_class.displayImage();
  cv::waitKey(0);
  return 0;
}