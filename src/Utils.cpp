//Include our classes
#include "Utils.h"
#include <algorithm>

bool C_RectangleCollision(C_Rectangle RectA, C_Rectangle RectB){
	if ((RectA.x < RectB.x + RectB.w) &&
		(RectB.x < RectA.x + RectA.w) &&
		(RectA.y < RectB.y + RectB.h) &&
		(RectB.y < RectA.y + RectA.h)){
		return true;
    }
	return false;
}

bool RectangleTriangleCollision(C_Rectangle a_rect, C_Triangle a_tri){
	if(isPointInRectangle(a_tri.a, a_rect)){return true;}
	if(isPointInRectangle(a_tri.b, a_rect)){return true;}
	if(isPointInRectangle(a_tri.c, a_rect)){return true;}

	Point topLeft = {a_rect.x, a_rect.y};
	Point topRight = {a_rect.x + a_rect.w, a_rect.y};
	Point bottomLeft = {a_rect.x, a_rect.y + a_rect.h};
	Point bottomRight = {a_rect.x + a_rect.w, a_rect.y + a_rect.h};

	if(isPointInTriangle(topLeft, a_tri)){return true;}
	if(isPointInTriangle(topRight, a_tri)){return true;}
	if(isPointInTriangle(bottomLeft, a_tri)){return true;}
	if(isPointInTriangle(bottomRight, a_tri)){return true;}

	if(doIntersect(topLeft, topRight, a_tri.a, a_tri.b)){return true;}
	if(doIntersect(topLeft, topRight, a_tri.b, a_tri.c)){return true;}
	if(doIntersect(topLeft, topRight, a_tri.a, a_tri.c)){return true;}
	if(doIntersect(topLeft, bottomLeft, a_tri.a, a_tri.b)){return true;}
	if(doIntersect(topLeft, bottomLeft, a_tri.b, a_tri.c)){return true;}
	if(doIntersect(topLeft, bottomLeft, a_tri.a, a_tri.c)){return true;}
	if(doIntersect(bottomRight, bottomLeft, a_tri.a, a_tri.b)){return true;}
	if(doIntersect(bottomRight, bottomLeft, a_tri.b, a_tri.c)){return true;}
	if(doIntersect(bottomRight, bottomLeft, a_tri.a, a_tri.c)){return true;}
	if(doIntersect(bottomRight, topRight, a_tri.a, a_tri.b)){return true;}
	if(doIntersect(bottomRight, topRight, a_tri.b, a_tri.c)){return true;}
	if(doIntersect(bottomRight, topRight, a_tri.a, a_tri.c)){return true;}

	return false;
}

bool isPointInRectangle(Point a_point, C_Rectangle a_rect){
	if(a_point.x >= a_rect.x && a_point.x <= a_rect.x + a_rect.w &&
	   a_point.y >= a_rect.y && a_point.y <= a_rect.y + a_rect.h){
		   return true;
	}
	return false;
}

bool isPointInTriangle(Point a_point, C_Triangle a_tri){
	int as_x = a_point.x-a_tri.a.x;
    int as_y = a_point.y-a_tri.a.y;

    bool s_ab = (a_tri.b.x-a_tri.a.x)*as_y-(a_tri.b.y-a_tri.a.y)*as_x > 0;

    if((a_tri.c.x-a_tri.a.x)*as_y-(a_tri.c.y-a_tri.a.y)*as_x > 0 == s_ab){
		return false;
	}
    if((a_tri.c.x-a_tri.b.x)*(a_point.y-a_tri.b.y)-(a_tri.c.y-a_tri.b.y)*(a_point.x-a_tri.b.x) > 0 != s_ab){
		return false;
	}
    return true;
}

bool onSegment(Point p, Point q, Point r){
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)){
       return true;
	}
    return false;
}
 
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

bool PointsAtDistance(int x1, int y1, int x2, int y2, int distance){
	int RealDistance = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	if(RealDistance <= (distance*distance)){
		return true;
	}
	return false;
}

int integerLength(int value){
  int l=!value;
  while(value){ l++; value/=10; }
  return l;
}

bool checkEllipsePoint(int pointX, int pointY, int halfHeight, int halfWidth){
	if((pointX*pointX*halfHeight*halfHeight + pointY*pointY*halfWidth*halfWidth) <= halfHeight*halfHeight*halfWidth*halfWidth){
		return true;
	}
	return false;
}

int intClamp(int v, int a, int b){
    return std::max(a, std::min(v, b));
}

Point rotatePoint(Point pivot, Point a_point, float angle){
	// Rotate clockwise, angle in radians
	float x = floor(cos(angle) * (a_point.x - pivot.x) -
					 sin(angle) * (a_point.y - pivot.y) +
					 pivot.x);
	float y = floor(sin(angle) * (a_point.x - pivot.x) +
					 cos(angle) * (a_point.y - pivot.y) +
					 pivot.y);
	Point rotated_point = {(int)x, (int)y};
	return rotated_point;
}

std::string itos(int number, int num_digits){
	int n = num_digits;
	if(n > MAX_DIGITS_U32){
		n = MAX_DIGITS_U32;
	}
	char convertedNumber[MAX_DIGITS_U32];
	std::stringstream ss;
	ss << "%0" << n <<"d";
	sprintf_s(convertedNumber, ss.str().c_str(), number);

	return convertedNumber;
}

bool findInString(std::string& aString, std::string to_find){
	if(std::string::npos != aString.find(to_find)){
		return true;
	}
	return false;
}

void replaceString(std::string& aString, std::string replaced, std::string replacing){
	size_t pos = aString.find(replaced);
	if ( pos != std::string::npos ) {
		aString.replace(pos, replaced.size(), replacing);
	}
}

void replaceAllInString(std::string& aString, std::string replaced, std::string replacing){
	std::string::size_type n = 0;
	while ((n = aString.find(replaced, n)) != std::string::npos){
		aString.replace( n, replaced.size(), replacing);
		n += replacing.size();
	}
}

std::vector<std::string> splitString(std::string aString, char separationCharacter){
	std::stringstream test(aString);
	std::string segment;
	std::vector<std::string> seglist;

	while(std::getline(test, segment, separationCharacter))
	{
	   seglist.push_back(segment);
	}
	return seglist;
}

bool isStringInVector(std::vector<std::string> &aVector, std::string aString){
	int size = aVector.size();
	for(int i = 0; i < size; i++){
		if(aVector[i] == aString){
			return true;
		}
	}
	return false;
}

bool findPointInVector(Point aPoint, std::vector<Point> &aVector){
	std::vector<Point>::iterator location;
	location = std::find(aVector.begin(),aVector.end(), aPoint);

	if (location != aVector.end()){
		return true;
	}
	return false;
}

bool findPointInVector(Point aPoint, std::vector<Point> &aVector, int &index){
	std::vector<Point>::iterator location;
	location = std::find(aVector.begin(),aVector.end(), aPoint);

	if (location != aVector.end()){
		index = (location - aVector.begin());
		return true;
	}
	index = -1;
	return false;
}

void deleteFile(const char* file_path){
	if( remove(file_path) != 0 ){
		std::cout<< "Error deleting file " << file_path <<std::endl;
	}else{
		#ifndef __PUBLICRELEASE__
			std::cout<< "File " << file_path << " successfully deleted" << std::endl;
		#endif
	}
}
