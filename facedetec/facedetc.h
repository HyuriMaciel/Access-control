
/**
 * @file stats 
 * @brief Functions the print in screen calculus statistcs of matrix 
 *
 * The functions of this header have the purpose of calculating some statistical
 * metrics of a one-dimensional matrix, printing these values on the screen, 
 * as well as performing the ordering in decreasing order of the matrix.
 *
 * @author hyuri Maciel 
 * @date 1 Jun 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


// Function prototypes
void printUsage();
void learn(const char *szFileTrain);
void doPCA();
void storeTrainingData();
int  loadTrainingData(CvMat ** pTrainPersonNumMat);
int  findNearestNeighbor(float * projectedTestFace);
int findNearestNeighbor(float * projectedTestFace, float *p);
int  loadFaceImgArray(const char * filename);
void recognizeFileList(const char *szFileTest);
void recognizeFromCam(void);
IplImage* getCameraFrame(void);
IplImage* convertImageToGreyscale(const IplImage *imageSrc);
IplImage* cropImage(const IplImage *img, const CvRect region);
IplImage* resizeImage(const IplImage *origImg, int newWidth, int newHeight);
IplImage* convertFloatImageToUcharImage(const IplImage *srcImg);
void saveFloatImage(const char *filename, const IplImage *srcImg);
CvRect detectFaceInImage(const IplImage *inputImg, const CvHaarClassifierCascade* cascade, int Parada, FILE*arq1 );
CvMat* retrainOnline(void);



#endif /* __STATS_H__ */