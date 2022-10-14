#include "adjustment.hpp"

namespace Adjustment {
  void adjustment::init(const double& alpha, const double& beta, const cv::Size &image_size)
  {
    m_alpha = alpha;
    m_beta = beta;
    m_image_size = image_size;
  }

  bool adjustment::loadImage(const std::string& img_1, const std::string& img_2, const std::string& img_3)
  {
    m_image_1 = cv::imread(img_1);
    m_image_2 = cv::imread(img_2);
    m_image_3 = cv::imread(img_3);
    if (m_image_1.empty() || m_image_2.empty() || m_image_3.empty()) {
      std::cerr << "\nError 1 of three images is empty\n";
      return 0;
    }
    cv::resize(m_image_1, m_image_1, m_image_size, 0.0, 0.0, CV_INTER_NN);
    cv::resize(m_image_2, m_image_2, m_image_size, 0.0, 0.0, CV_INTER_NN);
    cv::resize(m_image_3, m_image_3, m_image_size, 0.0, 0.0, CV_INTER_NN);
    cv::imshow("ybw", m_image_1);
    cv::imshow("pth", m_image_2);
    cv::imshow("kgw", m_image_3);
    return 1;
  }

  void adjustment::convertImage(cv::Mat& img_out)
  {
    for (int cols_iter = 0; cols_iter < m_image_size.width; cols_iter++)
    {
      for (int rows_iter = 0; rows_iter < m_image_size.height; rows_iter++)
      {
        for (int channel_iter = 0; channel_iter < 3; channel_iter++)
        {
          img_out.at<cv::Vec3b>(rows_iter, cols_iter)[channel_iter] = cv::saturate_cast<uchar>((1 - 0.8 * m_alpha - 1.2 * m_beta) * m_image_1.at<cv::Vec3b>(rows_iter, cols_iter)[channel_iter] + (0.8 * m_alpha * m_image_2.at<cv::Vec3b>(rows_iter, cols_iter)[channel_iter]) + (1.2 * m_beta * m_image_3.at<cv::Vec3b>(rows_iter, cols_iter)[channel_iter]));
        }
      }
    }
  }

  adjustment::adjustment(void)
  {
  }
}
