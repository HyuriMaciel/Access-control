
/**
*
 * @author hyuri Maciel 
 * @date 1 may 2016
 *
 */
#ifndef __STATS_H__
#define __STATS_H__



// Global variables
IplImage ** faceImgArr        = 0; // array of face images
CvMat    *  personNumTruthMat = 0; // array of person numbers
//#define	MAX_NAME_LENGTH 256		// Give each name a fixed size for easier code.
//char **personNames = 0;			// array of person names (indexed by the person number). Added by Shervin.
vector<string> personNames;			// array of person names (indexed by the person number). Added by Shervin.
int faceWidth = 120;	// Default dimensions for faces in the face recognition database. Added by Shervin.
int faceHeight = 90;	//	"		"		"		"		"		"		"		"
int nPersons                  = 0; // the number of people in the training set. Added by Shervin.
int nTrainFaces               = 0; // the number of training images
int nEigens                   = 0; // the number of eigenvalues
IplImage * pAvgTrainImg       = 0; // the average image
IplImage ** eigenVectArr      = 0; // eigenvectors
CvMat * eigenValMat           = 0; // eigenvalues
CvMat * projectedTrainFaceMat = 0; // projected training faces

CvCapture* camera = 0;	// The camera device.
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
