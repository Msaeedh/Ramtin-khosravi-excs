class Shape {
public:
    Shape(int init_x, int init_y) : x(init_x), y(init_y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
    void move(int dx, int dy);

    virtual void scale(int s) = 0;
    virtual void print() = 0;
    virtual int area() = 0 ;
protected:
    int x;
    int y;
};

void Shape::move(int dx, int dy)
{
    x += dx;
    y += dy;
}