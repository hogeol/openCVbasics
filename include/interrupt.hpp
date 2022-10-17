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
    cv::Size m_filter_size;
    cv::Size m_img_size;
    bool m_mouse_flag;
  public:
    bool init(const std::string& img_path, const cv::Size &img_size);
    void setRoi();
    void onMouse(int event, int x, int y);
    static void onMouse(int event, int x, int y, int flags, void* param);
    void onFilterMouse(int event, int x, int y);
    static void onFilterMouse(int event, int x, int y, int flags, void* param);
    void trackbarControl();
    void onFilterTrackbar(int pos);
    static void onFilterTrackbar(int pos, void* param);
    void onFilterWidthTrackbar(int pos);
    static void onFilterWidthTrackbar(int pos, void* param);
    void onFilterHeightTrackbar(int pos);
    static void onFilterHeightTrackbar(int pos, void* param);
    void onFilterModeTrackbar(int pos);
    static void onFilterModeTrackbar(int pos, void* param);
    void setRectPoint();
    void setColor(const double& b, const double& g, const double& r, cv::Mat &image);
    void displayImage(const std::string window_name);
    void displayImage(const std::string window_name, const cv::Mat& image);
    interrupt(void);
  };
}

#endif
