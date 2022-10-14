#ifndef _HISTOGRAM_STRETCHING_
#define _HISTOGRAM_STRETCHING_

#include <string>
#include <opencv2/opencv.hpp>

namespace HistogramStretching {
  class histogramStretching
  {
  private:
    cv::Mat m_image;
    cv::Size m_image_size;
    int m_r1;
    int m_r2;
    int m_s1;
    int m_s2;
  public:
    bool init(const std::string& image_path, const cv::Size &image_size,const int& r1, const int& s1, const int& r2, const int& s2);
    void imageStretch();
    void setStretchValue(const int &pix, int &value_out);
    void displayImage();
    cv::Mat mp_stretch_image;
    histogramStretching(void);
  };
}

#endif

