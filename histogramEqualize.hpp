#ifndef _HISTOGRAM_EQUALIZE_
#define _HISTOGRAM_EQUALIZE_

#include <string>
#include <opencv2/opencv.hpp>
#include "histogram.hpp"

namespace HistogramEqualize {
  class histogramEqualize
  {
  private:
    cv::Mat m_equalized_image;
    cv::Mat m_threshold_image;
    cv::Mat m_otsu_threshold_image;
    cv::Size m_image_size;
    Histogram::histogram m_histogram_class;
    double m_threshold_value;
  public:
    bool init(const std::string& image_path, const cv::Size &image_size,const double& threshold_value);
    void equailze();
    void setThreshold();
    void setThresholdOtsu();
    void displayHistogram();
    void displayImage();
    histogramEqualize(void);
  };
}

#endif
