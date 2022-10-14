//stl
#include <iostream>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "interrupt.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_김호걸_과제1\\data\\"
#define IMG_NAME "lina.jpg"

/*1. 입력 영상을 컬러로 화면에 띄우고 마우스로 ROI를 입력받은 후에 입력받은 영역을 Mat 클래스의 at( ) 함수를 사용해서 R의 값에 10을 더하고, G의 값에 15을 빼고, B의 값에 30를 더한 후에 
전체 영상을 다시 출력하시오 */

//int main(int argc, char** argv)
//{
//  Interrupt::interrupt interrupt_class;
//  //image load
//  std::string image_path = IMG_PATH;
//  image_path += IMG_NAME;
//  if (!interrupt_class.init(image_path)) {
//    return -1;
//  }
//  interrupt_class.setRoi();
//  cv::waitKey(0);
//  return 0;
//}