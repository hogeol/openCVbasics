#ifndef _ADJUSTMENT_
#define _ADJUSTMENT_

#include <string>
#include <opencv2/opencv.hpp>

namespace Adjustment {
  class adjustment
  {
  private:
    double m_alpha;
    double m_beta;
    cv::Size m_image_size;
    cv::Mat m_image_1;
    cv::Mat m_image_2;
    cv::Mat m_image_3;
  public:
    void init(const double& alpha, const double& beta, const cv::Size &image_size);
    bool loadImage(const std::string& img_1, const std::string& img_2, const std::string& img_3);
    void convertImage(cv::Mat &img_out);

    adjustment(void);
  };
}

#endif _ADJUSTMENT_

