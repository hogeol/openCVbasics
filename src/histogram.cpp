#include "histogram.hpp"

namespace Histogram {
  bool histogram::init(const std::string& image_path, const cv::Size& img_size, const int& histogram_bin_size, const bool& is_color)
  {
    if (is_color) {
      mp_image = cv::imread(image_path, CV_8SC3);
    }
    else {
      mp_image = cv::imread(image_path, CV_8UC1);
    }
    if (mp_image.empty()) {
      std::cerr << "\nERROR! input image is empty\n";
      return 0;
    }
    m_histogram_bin_size = histogram_bin_size;
    m_img_size = img_size;
    m_is_color = is_color;
    mp_histogram_image = cv::Mat(m_img_size.height, m_img_size.width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (int histogram_iter = 0; histogram_iter < 256; histogram_iter++) {
      if (m_is_color) {
        std::vector<int> histo_color_tmp(3, 0);
        m_histogram.push_back(histo_color_tmp);
      }
      else {
        m_grey_histogram.push_back(0);
      }
    }
    cv::resize(mp_image, mp_image, m_img_size, 0.0, 0.0, CV_INTER_NN);
    return 1;
  }

  void histogram::drawHistogram()
  {
    calculateHistogram();
    normalization();
    drawHistogramLine();
  }

  void histogram::calculateHistogram()
  {
    if (m_is_color) {
      for (int rows_iter = 0; rows_iter < m_img_size.height; rows_iter++) {
        for (int cols_iter = 0; cols_iter < m_img_size.width; cols_iter++) {
          for (int channel_iter = 0; channel_iter < 3; channel_iter++) {
            m_histogram[(int)mp_image.at<cv::Vec3b>(rows_iter, cols_iter)[channel_iter]][channel_iter]++;
          }
        }
      }
    }
    else {
      for (int rows_iter = 0; rows_iter < m_img_size.height; rows_iter++) {
        for (int cols_iter = 0; cols_iter < m_img_size.width; cols_iter++) {
          m_grey_histogram[(int)mp_image.at<uchar>(rows_iter, cols_iter)]++;
        }
      }
    }
  }

  inline void histogram::normalization()
  {
    if (m_is_color) {
      int b_max = m_histogram[0][0];
      int g_max = m_histogram[0][1];
      int r_max = m_histogram[0][2];
      findColorMaxValue(b_max, g_max, r_max);
      for (int intensity_iter = 0; intensity_iter < 255; intensity_iter++) {
        m_histogram[intensity_iter][0] = floor(((double)m_histogram[intensity_iter][0] / b_max) * m_img_size.height);
        m_histogram[intensity_iter][1] = floor(((double)m_histogram[intensity_iter][1] / g_max) * m_img_size.height);
        m_histogram[intensity_iter][2] = floor(((double)m_histogram[intensity_iter][2] / r_max) * m_img_size.height);
      }
    }
    else {
      int max = m_grey_histogram[0];
      findGreyMaxValue(max);
      for (int intensity_iter = 0; intensity_iter < 255; intensity_iter++) {
        m_grey_histogram[intensity_iter] = floor(((double)m_grey_histogram[intensity_iter] / max) * m_img_size.height);
      }
    }
  }

  void histogram::findColorMaxValue(int& b_out, int& g_out, int& r_out)
  {
    for (int intensity_iter = 1; intensity_iter < 256; intensity_iter++) {
      if (b_out < m_histogram[intensity_iter][0]) {
        b_out = m_histogram[intensity_iter][0];
      }
      if (g_out < m_histogram[intensity_iter][1]) {
        g_out = m_histogram[intensity_iter][1];
      }
      if (r_out < m_histogram[intensity_iter][2]) {
        r_out = m_histogram[intensity_iter][2];
      }
    }
  }

  void histogram::findGreyMaxValue(int& max_out)
  {
    for (int intensity_iter = 1; intensity_iter < 256; intensity_iter++) {
      if (max_out < m_grey_histogram[intensity_iter]) {
        max_out = m_grey_histogram[intensity_iter];
      }
    }
  }

  void histogram::drawHistogramLine()
  {
    int bin_width = cvRound((double)m_img_size.width / m_histogram_bin_size);
    if (m_is_color) {
      for (int intensity_iter = 0; intensity_iter < 255; intensity_iter++) {
        cv::line(mp_histogram_image, cv::Point(bin_width * intensity_iter, m_img_size.height), cv::Point(bin_width * intensity_iter, m_img_size.height - m_histogram[intensity_iter][0]), cv::Scalar(255, 0, 0));
        cv::line(mp_histogram_image, cv::Point(bin_width * intensity_iter, m_img_size.height), cv::Point(bin_width * intensity_iter, m_img_size.height - m_histogram[intensity_iter][1]), cv::Scalar(0, 255, 0));
        cv::line(mp_histogram_image, cv::Point(bin_width * intensity_iter, m_img_size.height), cv::Point(bin_width * intensity_iter, m_img_size.height - m_histogram[intensity_iter][2]), cv::Scalar(0, 0, 255));
      }
    }
    else {
      for (int intensity_iter = 0; intensity_iter < 255; intensity_iter++) {
        cv::line(mp_histogram_image, cv::Point(bin_width * intensity_iter, m_img_size.height), cv::Point(bin_width * intensity_iter, m_img_size.height - m_grey_histogram[intensity_iter]), cv::Scalar(0, 0, 0));
      }
    }
  }

  histogram::histogram(void)
  {
  }
}
