#pragma once

#include <vector>
#include <cv.h>
class Octave {
private:
	std::vector < cv::Mat >* mpLaplaciansOfGaussians;
	unsigned mScaleFactor;
public:
	Octave(std::vector<cv::Mat>* pLaplaciansOfGaussians, unsigned scaleFactor ) {
		mpLaplaciansOfGaussians = pLaplaciansOfGaussians;
		mScaleFactor = scaleFactor;
	}
	void getFeatures(void) {
		return;
	}
};
