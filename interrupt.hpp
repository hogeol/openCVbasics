#ifndef _INTERRUPT_
#define _INTERRUPT_

#include <cmath>
#include <opencv2/opencv.hpp>

#define SMALL(a, b) (a)<(b) ? (a):(b)
#define BIG(a, b) (a)>(b) ? (a):(b)

namespace Interrupt {
  class interrupt {
  private:
    cv::Mat m_image;
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    cv::Point2d m_rect_start;
    cv::Point2d m_rect_end;
    bool m_mouse_flag;
  public:
    bool init(const std::string& img_path);
    void setRoi();
    void onMouse(int event, int x, int y);
    static void onMouse(int event, int x, int y, int flags, void* param);
    void setRectPoint();
    void setColor(const double& b, const double& g, const double& r, cv::Mat &image);
    void displayImage(const std::string window_name);
    void displayImage(const std::string window_name, const cv::Mat& image);
    interrupt(void);
  };
}

#endif
