#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <cv.h>

class Octave {
private:
	std::vector < cv::Mat >* mpLaplaciansOfGaussians;
	unsigned mScaleFactor;
	std::vector < std::pair<unsigned, unsigned> >*  getNeighbours(unsigned x, unsigned  y, bool isSameLevel) {
		std::vector <std::pair<unsigned, unsigned> >* pResults = new std::vector <std::pair< unsigned, unsigned > > ();
		if(!isSameLevel) {
			pResults->push_back(std::make_pair<unsigned, unsigned>(x,y));
		}
		pResults->push_back(std::make_pair<unsigned, unsigned>(x-1,y-1));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x,y-1));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x+1,y-1));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x-1,y));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x+1,y));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x-1,y+1));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x,y+1));
		pResults->push_back(std::make_pair<unsigned, unsigned>(x+1,y+1));
		return pResults;
	}
	unsigned getGradient(int x, int y, int layer) {
		unsigned bestGradient = 0;
		unsigned biggerCounter = 0;
		unsigned smallerCounter = 0;
		for(int adjacentLayerIndex = -1; adjacentLayerIndex <= 1; ++adjacentLayerIndex) {
			std::vector< std::pair<unsigned, unsigned> >* pNeighbours = getNeighbours(x, y, adjacentLayerIndex == 0);
			for(std::vector<std::pair<unsigned, unsigned> >::iterator aNeighbourIterator= pNeighbours->begin(); aNeighbourIterator != pNeighbours->end(); ++aNeighbourIterator) {
				unsigned neighbourX = aNeighbourIterator->first;
				unsigned neighbourY = aNeighbourIterator->second;
				int difference = (int)(((*mpLaplaciansOfGaussians)[layer]).at<unsigned>(x,y) - ((*mpLaplaciansOfGaussians)[layer+adjacentLayerIndex]).at<unsigned>(neighbourX, neighbourY));
				if(difference > 0)
					smallerCounter++;
				if(difference < 0)
					biggerCounter++;
				bestGradient = std::max(
					(int)(bestGradient), 
					std::abs(difference)
				);
				if(smallerCounter != 0 && biggerCounter != 0) {
					delete pNeighbours;
					return 0;
				}
			}
			delete pNeighbours; 
		}
		return bestGradient;
	}
public:
	Octave(std::vector<cv::Mat>* pLaplaciansOfGaussians, unsigned scaleFactor ) {
		mpLaplaciansOfGaussians = pLaplaciansOfGaussians;
		mScaleFactor = scaleFactor;
	}
	cv::Mat getFeatures(void) {
		unsigned numberOfLayers = 5;
		cv::Mat tempFeatures = cv::Mat::zeros(((*mpLaplaciansOfGaussians)[0]).rows, ((*mpLaplaciansOfGaussians)[0]).cols, CV_8UC1);
		for(unsigned layer = 1; layer != numberOfLayers-1; ++layer) {
			for(unsigned x = 1; x != ((*mpLaplaciansOfGaussians)[layer]).cols - 1; ++x) {
				for(unsigned y = 1; y != ((*mpLaplaciansOfGaussians)[layer]).rows - 1; ++y) {
					tempFeatures.at<unsigned>(x,y) = std::max(getGradient(x, y, layer), tempFeatures.at<unsigned>(x,y));
				}
			}
		}
		char filename[20];
		sprintf(filename, "debug%d.bmp", mScaleFactor);
		imwrite(filename, tempFeatures);
		return tempFeatures;
	}
};