#ifndef _HISTOGRAM_
#define _HISTOGRAM_

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

namespace Histogram {
  class histogram
  {
  private:
    cv::Size m_img_size;
    std::vector<std::vector<int>> m_histogram;
    std::vector<int> m_grey_histogram;
    int m_histogram_bin_size;
    bool m_is_color;
  public:
    bool init(const std::string &image_path, const cv::Size &img_size, const int& histogram_bin_size = 256, const bool &is_color = true);
    void drawHistogram();
    void calculateHistogram();
    inline void normalization();
    void findColorMaxValue(int &b_out, int &g_out, int &r_out);
    void findGreyMaxValue(int& max_out);
    void drawHistogramLine();
    cv::Mat mp_image;
    cv::Mat mp_histogram_image;
    histogram(void);
  };
}

#endif _HISTOGRAM_