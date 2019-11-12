// we are ready for project

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\objdetect\objdetect.hpp>

using namespace std;
using namespace cv;

void detectFaces(Mat img, char output_path[]);
CascadeClassifier faceDetection;
char input_path[100];


int main() {

	if (!faceDetection.load("C:\\Users\\Gursewak Singh\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
		cout << "\n XML File not found";
		exit(0);
	}

	char img1[40], img2[40];

	cout << "\n Enter name of first image : ";
	cin.getline(img1, 40);   // first image
	 
	cout << "\n Enter name of  Second image : ";
	cin.getline(img2, 40);   // second image


	strcpy(input_path, "input\\");
	strcat(input_path, img1);

	Mat image1 = imread(input_path, CV_LOAD_IMAGE_UNCHANGED);

	strcpy(input_path, "input\\");
	strcat(input_path, img2);

	Mat image2 = imread(input_path, CV_LOAD_IMAGE_UNCHANGED);

	if (image1.empty()) {
		cout << "\n image is not loaded! - " << img1;
	}
	
	if (image2.empty()) {
		cout << "\n image is not loaded! - " << img2;
	}

	char output_path1[100], output_path2[100];

	strcpy(output_path1, "output\\");
	strcat(output_path1, img1);
	strcpy(output_path2, "output\\");
	strcat(output_path2, img2);


	detectFaces(image1, output_path1);
	detectFaces(image2, output_path2);


	return 0;
}

void detectFaces(Mat img, char output_path[]) {

	vector<Rect> faces;

	faceDetection.detectMultiScale(img, faces);

	for (int i = 0; i < faces.size(); i++) {
		Point pt1(faces[i].x, faces[i].y);
		Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));

		rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
	}

	imwrite(output_path, img);

	cout << "\n Image is detected successfully!";

}








