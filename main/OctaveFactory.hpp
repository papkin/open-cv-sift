#pragma once

#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

#include "Octave.hpp"

class OctaveFactory {
public:
	Octave* createOctave(std::vector<cv::Mat>* pLaplaciansOfGaussians) {
		return new Octave(pLaplaciansOfGaussians);
	}
};
