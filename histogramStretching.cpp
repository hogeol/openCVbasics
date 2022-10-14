#include "histogramStretching.hpp"

namespace HistogramStretching {

  bool histogramStretching::init(const std::string& image_path, const cv::Size& image_size, const int& r1, const int& s1, const int& r2, const int& s2)
  {
    m_image = cv::imread(image_path);
    if (m_image.empty()) {
      std::cerr << "\nError! input image is empty\n";
      return 0;
    }
    m_image_size = image_size;
    cv::resize(m_image, m_image, m_image_size, 0.0, 0.0, CV_INTER_NN);
    mp_stretch_image = m_image.clone();
    m_r1 = r1;
    m_s1 = s1;
    m_r2 = r2;
    m_s2 = s2;
    return 1;
  }

  void histogramStretching::imageStretch()
  {
    for (int rows_iter = 0; rows_iter < m_image_size.height; rows_iter++) {
      for (int cols_iter = 0; cols_iter < m_image_size.width; cols_iter++) {
        for (int ch_iter = 0; ch_iter < 3; ch_iter++) {
          int value = 0;
          setStretchValue(m_image.at<cv::Vec3b>(rows_iter, cols_iter)[ch_iter], value);
          mp_stretch_image.at<cv::Vec3b>(rows_iter, cols_iter)[ch_iter] = cv::saturate_cast<uchar>(value);
        }
      }
    }
    displayImage();
  }

  void histogramStretching::setStretchValue(const int& pix, int &value_out)
  {
    double result = 0.0;
    if (0 <= pix && pix <= m_r1) {
      result = m_s1 / m_r1 * pix;
    }
    else if (m_r1 < pix && pix <= m_r2) {
      result = ((m_s2 - m_s1) / (m_r2 - m_r1)) * (pix - m_r1) + m_s1;
    }
    else if (m_r2 < pix && pix <= 255) {
      result = ((255 - m_s2) / (255 - m_r2)) * (pix - m_r2) + m_s2;
    }
    value_out = (int)result;
  }

  void histogramStretching::displayImage()
  {
    cv::imshow("origin_image", m_image);
  }

  histogramStretching::histogramStretching(void)
  {
  }
}