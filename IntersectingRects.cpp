#include <iostream>

using namespace std;

class Rectangle {
	public:
		float x;
		float y;
		float width;
		float height;
	
	Rectangle(float x, float y, float width, float height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
  }
};

void intersects(Rectangle r1, Rectangle r2) {
	cout << "R1: origin(" << r1.x << "," << r1.y << "), ";
	cout << "width: " << r1.width << ", ";
	cout << "height: " << r1.height << endl;

  cout << "R2: origin(" << r2.x << "," << r2.y << "), ";
  cout << "width: " << r2.width << ", ";
  cout << "height: " << r2.height << endl;

	if(((r1.x <= r2.x && r2.x < r1.x + r1.width) ||
      (r2.x <= r1.x && r1.x < r2.x + r2.width)) &&
     ((r1.y <= r2.y && r2.y < r1.y + r1.height) ||
			(r2.y <= r1.y && r1.y < r2.y + r2.height))) {
		cout << "R1 and R2 intersect." << endl;
  } else {
		cout << "R1 and R2 don't intersect." << endl;
	}
	cout << endl;
}

int main(int argv, char** argc) {	
	cout << "1. Disjoint" << endl;
	Rectangle r1(0,0,5,5);
	Rectangle r2(6,6,5,5);
	intersects(r1,r2);	

	cout << "2. Same rectangle" << endl;
	intersects(r1,r1);

	cout << "3. Bottom right, top left" << endl;
	r1 = Rectangle(0,0,10,5);
	r2 = Rectangle(9,4,2,2);
	intersects(r1,r2);

	cout << "4. Top left, bottom right" << endl;
	intersects(r2,r1);

	cout << "5. Bottom left, top right" << endl;
	r1 = Rectangle(0,4,6,6);
	r2 = Rectangle(5,0,5,5);
	intersects(r1,r2);

	cout << "6. Top right, bottom left" << endl;
	intersects(r2,r1);

	cout << "7. One inside the other" << endl;
	r1 = Rectangle(5,5,4,4);
	r2 = Rectangle(6,6,2,2);
	intersects(r1,r2);

  cout << "8. Elongated" << endl;
	r1 = Rectangle(0,5,10,1);
	r2 = Rectangle(5,0,1,10);
	intersects(r1,r2);

	cout << "9. Horizontal adjacent" << endl;
	r1 = Rectangle(0,0,5,5);
	r2 = Rectangle(5,0,5,5);
	intersects(r1,r2);

	cout << "10. Vertical adjacent" << endl;
	r1 = Rectangle(0,0,5,5);
	r2 = Rectangle(0,5,5,5);
	intersects(r1,r2);

  return 0;
}
