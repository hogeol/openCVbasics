//stl
#include <iostream>
//opencv
#include <opencv2/opencv.hpp>
//local
#include "interrupt.hpp"

#define IMG_PATH "C:\\Users\\Pc\\Desktop\\cv_project\\2017035122_��ȣ��_����1\\data\\"
#define IMG_NAME "lina.jpg"

/*1. �Է� ������ �÷��� ȭ�鿡 ���� ���콺�� ROI�� �Է¹��� �Ŀ� �Է¹��� ������ Mat Ŭ������ at( ) �Լ��� ����ؼ� R�� ���� 10�� ���ϰ�, G�� ���� 15�� ����, B�� ���� 30�� ���� �Ŀ� 
��ü ������ �ٽ� ����Ͻÿ� */

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