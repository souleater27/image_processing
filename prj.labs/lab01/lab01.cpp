#include <opencv2/opencv.hpp>


int main() {
   //First 
  cv::Mat img_I_1(60, 768, CV_8UC1);
  // draw dummy image
  img_I_1 = 0;
  int RGB = 0;
  cv::Mat img;
  for (int j = 0; j <= 765; j = RGB * 3)
  {
	  for (int i = 0; i < 60; i++)
	  {

          img_I_1.at<uint8_t>(i, j) = RGB;
          img_I_1.at<uint8_t>(i, j + 1) = RGB;
          img_I_1.at<uint8_t>(i, j + 2) = RGB;
      }
      RGB++;
  }
  img_I_1.convertTo(img, CV_32FC1, 1.0 / 255, 0);

  //Second 
  cv::TickMeter tm;
  tm.start();
  cv::Mat img_G_1;
  cv::pow(img, 2.3, img_G_1);
  img_G_1 *= 225;
  img_G_1.convertTo(img_G_1, CV_8UC1);
  tm.stop();
  std::cout << "Second " << tm.getTimeSec()<< std::endl;


//Third 
 
  tm.start();
  cv::Mat img_G_2(60, 768, CV_8UC1);
  for (int i = 0; i < 60; i++) {
      for (int j = 0; j < 768; j++) {
          img_G_2.at<uint8_t>(i, j) = pow(img.at<float_t>(i, j), 2.3) * 255;;
      }
  }
  tm.stop();
  std::cout << "Third" << tm.getTimeSec() << std::endl;
 


  cv::imwrite("lab01_1.png", img_I_1);
  cv::imwrite("lab01_2.png",img_G_1);
  cv::imwrite("lab01_3.png", img_G_2);
  


  cv::Mat end;
  end.push_back(img_I_1);
  end.push_back(img_G_2);
  end.push_back(img_G_1);
  cv::imwrite("lab01.png", end);
  cv::imshow("lab01.png", end);
  cv::waitKey(0);


 
  }



  
  
