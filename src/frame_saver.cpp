#include <opencv2/opencv.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
 
using namespace std;
using namespace cv;
 
int main(int argc,char* argv[]){
  int count = -1;
  VideoCapture cap(argv[1]); 
    
   if(!cap.isOpened()){
   cout << "Error opening video stream or file" << endl;
   return -1;
  }
     
  while(1){
 
    Mat frame;
    
    cap >> frame;
  
   
    if (frame.empty())
      break;
 
    
    imshow( "Frame", frame );
    waitKey(1);
    
    char c;
    c = getchar();
    if(c=='s'){
	count++;
	string str = boost::lexical_cast<string>(count);
	string name = "frame_" + str + ".png";
        imwrite(argv[2] + name, frame);	
    }
    else if(c==27){
	break;
    }
    else{
        continue;
    }		
  }
    
  cap.release();
 
  destroyAllWindows();
     
  return 0;
}
