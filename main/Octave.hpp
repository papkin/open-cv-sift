#pragma once

#include <vector>
#include <cv.h>
class Octave {
private:
	std::vector < cv::Mat >* mpLaplaciansOfGaussians;
public:
	Octave(std::vector<cv::Mat>* pLaplaciansOfGaussians) {
		mpLaplaciansOfGaussians = pLaplaciansOfGaussians;
	}
	void getFeatures(void) {
		return;
	}
};
