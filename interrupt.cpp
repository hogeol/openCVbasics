#define _USE_MATH_DEFINES_
#include "interrupt.hpp"

namespace Interrupt {
  bool interrupt::init(const std::string &img_path)
  {
    m_x1 = 0;
    m_y1 = 0;
    m_x2 = 0;
    m_y2 = 0;
    m_mouse_flag = false;
    m_image = cv::imread(img_path);
    if (m_image.empty()) {
      std::cerr << "\nCould not read the image: " << img_path << std::endl;
      return 0;
    }
    cv::resize(m_image, m_image, cv::Size(640, 360), 0.0, 0.0, CV_INTER_NN);
    return 1;
  }

  void interrupt::setRoi()
  {
    displayImage("image");
    cv::setMouseCallback("image", onMouse, this);
  }

  void interrupt::onMouse(int event, int x, int y)
  {
    if (event == CV_EVENT_LBUTTONDOWN) {
      m_x1 = x;
      m_y1 = y;
      m_mouse_flag = true;
    }
    else if (event == CV_EVENT_MOUSEMOVE && m_mouse_flag == true) {
      cv::Mat img_tmp = m_image.clone();
      m_x2 = x;
      m_y2 = y;
      setRectPoint();
      cv::rectangle(img_tmp, CvRect(m_rect_start.x, m_rect_start.y, std::abs(m_rect_end.x - m_rect_start.x), std::abs(m_rect_end.y - m_rect_start.y)), cv::Scalar(0, 0, 255), 2);
      displayImage("origin_roi", img_tmp);
    }
    else if (event == CV_EVENT_LBUTTONUP && m_mouse_flag == true) {
      cv::Mat img_final = m_image.clone();
      cv::Mat origin_color = m_image.clone();
      m_x2 = x;
      m_y2 = y;
      setRectPoint();
      cv::rectangle(img_final, CvRect(m_rect_start.x, m_rect_start.y, std::abs(m_rect_end.x - m_rect_start.x), std::abs(m_rect_end.y - m_rect_start.y)), cv::Scalar(0, 0, 255), 2);
      setColor(30, -15, 10, origin_color);
      img_final = origin_color(CvRect(m_rect_start.x, m_rect_start.y, std::abs(m_rect_end.x - m_rect_start.x), std::abs(m_rect_end.y - m_rect_start.y)));
      displayImage("roi", img_final);
      cv::rectangle(origin_color, CvRect(m_rect_start.x, m_rect_start.y, std::abs(m_rect_end.x - m_rect_start.x), std::abs(m_rect_end.y - m_rect_start.y)), cv::Scalar(0, 0, 255), 2);
      displayImage("origin_roi", origin_color);
      m_mouse_flag = false;
    }
  }

  void interrupt::onMouse(int event, int x, int y, int flags, void* param)
  {
    interrupt* interrupts = reinterpret_cast<interrupt*>(param);
    interrupts->onMouse(event, x, y);
  }

  void interrupt::setRectPoint()
  {
    m_rect_start.x = SMALL(m_x1, m_x2);
    m_rect_start.y = SMALL(m_y1, m_y2);
    m_rect_end.x = BIG(m_x1, m_x2);
    m_rect_end.y = BIG(m_y1, m_y2);
    if (m_rect_start.x < 0) {
      m_rect_start.x = 0;
    }
    if (m_rect_start.y < 0) {
      m_rect_start.y = 0;
    }
    if (m_rect_end.x > m_image.cols) {
      m_rect_end.x = m_image.cols - 1;
    }
    if (m_rect_end.y > m_image.rows) {
      m_rect_end.y = m_image.rows - 1;
    }
  }

  void interrupt::setColor(const double& b, const double& g, const double& r, cv::Mat &image)
  {
    for (int rows_iter = m_rect_start.y; rows_iter < m_rect_end.y; rows_iter++) {
      for (int cols_iter = m_rect_start.x; cols_iter < m_rect_end.x; cols_iter++) {
        image.at<cv::Vec3b>(rows_iter, cols_iter)[0] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(rows_iter, cols_iter)[0] + b);
        image.at<cv::Vec3b>(rows_iter, cols_iter)[1] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(rows_iter, cols_iter)[1] - g);
        image.at<cv::Vec3b>(rows_iter, cols_iter)[2] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(rows_iter, cols_iter)[2] + r);
      }
    }
  }

  void interrupt::displayImage(const std::string window_name)
  {
    cv::imshow(window_name, m_image);
  }

  void interrupt::displayImage(const std::string window_name, const cv::Mat& image)
  {
    cv::imshow(window_name, image);
  }

  interrupt::interrupt(void)
  {
  }
}
