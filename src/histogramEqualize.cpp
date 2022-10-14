#include "histogramEqualize.hpp"

namespace HistogramEqualize {
  bool histogramEqualize::init(const std::string& image_path, const cv::Size& image_size, const double& threshold_value)
  {
    m_image_size = image_size;
    m_threshold_value = threshold_value;
    m_histogram_class.init(image_path, m_image_size, 256, false);
    return 1;
  }

  void histogramEqualize::equailze()
  {
    cv::equalizeHist(m_histogram_class.mp_image, m_equalized_image);
  }

  void histogramEqualize::setThreshold()
  {
    cv::threshold(m_histogram_class.mp_image, m_threshold_image, m_threshold_value, 255, CV_THRESH_BINARY);
  }
  void histogramEqualize::setThresholdOtsu()
  {
    cv::threshold(m_histogram_class.mp_image, m_otsu_threshold_image, m_threshold_value, 255, CV_THRESH_OTSU);
  }

  void histogramEqualize::displayHistogram()
  {
    m_histogram_class.drawHistogram();
  }

  void histogramEqualize::displayImage()
  {
    cv::imshow("origin", m_histogram_class.mp_image);
    cv::imshow("histogram", m_histogram_class.mp_histogram_image);
    cv::imshow("threshold", m_threshold_image);
    cv::imshow("otsu_threshold", m_otsu_threshold_image);
    cv::imshow("after_equailze", m_equalized_image);
  }
  histogramEqualize::histogramEqualize(void)
  {
  }
}
