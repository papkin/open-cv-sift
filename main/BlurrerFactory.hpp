#pragma once

#include "Blurrer.hpp"

class BlurrerFactory {
public:
	Blurrer* createBlurrer(cv::Mat* pImage, OctaveFactory* pOctaveFactory) {
		return new Blurrer(pImage, pOctaveFactory);
	}
};
