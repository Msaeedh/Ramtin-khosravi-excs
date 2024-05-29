#include <iostream>
class IllegalArgumentException {};

class Shape {
public:
    Shape(int init_x, int init_y) : x(init_x), y(init_y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
    void move(int dx, int dy);

    virtual void scale(int s) = 0;
    virtual void print() = 0;
protected:
    int x;
    int y;
};

void Shape::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

class line_segment : public Shape {
	public :
	line_segment(int ,int ,int d) ;
	int get_degree() ;
	virtual void scale(int s) ;
	virtual void print() ;
	
	private :
	int degree ;
};

line_segment::line_segment(int init_x , int init_y ,int d) 
	: Shape(init_x , init_y) ,
	degree(d)
{
	if (d < 0)
		throw IllegalArgumentException();
}

int line_segment::get_degree(){
	return degree ;
}

void line_segment::print() {
	std::cout << "line segment : " << x <<',' << y << ',' << degree <<std::endl ;
}

void line_segment::scale(int s) {}

int main()
{
	line_segment (0,0,0) ;
	
	return 0 ;
}












