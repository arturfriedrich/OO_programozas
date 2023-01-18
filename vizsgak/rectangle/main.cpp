#include <iostream>
#include <sstream>

enum RType
{
    RECTANGLE = 1,
    SQUARE = 2
};

class Rectangle
{
protected:
    int w, h;

public:
    Rectangle(int w, int h)
        : w(w), h(h)
    {
    }
    virtual ~Rectangle()
    {
        std::cerr << "~Rectangle()" << this << "\n";
    }
    virtual void rotate()
    {
        int tmp = w;
        w = h;
        h = tmp;
    }
    virtual std::string toString() const
    {
        std::string str;
        for (int row = 0; row < h; ++row)
        {
            for (int col = 0; col < w; ++col)
            {
                if (row == 0 || row == h - 1 || col == 0 || col == w - 1)
                {
                    // on the border
                    if ((row == 0 || row == h - 1) && (col == 0 || col == w - 1))
                        str += '+';
                    else if (row == 0 || row == h - 1)
                        str += '-';
                    else
                        str += '|';
                }
                else
                {
                    str += ' ';
                }
            }
            str += '\n';
        }
        return str;
    }
    friend std::ostream &operator<<(std::ostream &out, const Rectangle &r)
    {
        return out << r.toString();
    }
    virtual int type() const
    {
        return RECTANGLE;
    }
    void scale(double factor)
    {
        w = (int)round(w * factor);
        h = (int)round(h * factor);
    }
    void scaleWidth(double factor)
    {
        w = (int)round(w * factor);
    }
    void scaleHeight(double factor)
    {
        h = (int)round(h * factor);
    }
};

class Square : public Rectangle
{
public:
    Square(int size)
        : Rectangle(size, size)
    {
    }
    ~Square()
    {
        std::cerr << "~Square()" << this << "\n";
    }
    void rotate() override {}
    std::string toString() const override
    {
        std::string str = Rectangle::toString();
        for (int row = 1; row + 1 < h; ++row)
        {
            for (int col = 1; col + 1 < w; ++col)
            {
                if (row == col || row + col == w - 1)
                    str[row * (w + 1) + col] = 'x';
            }
        }
        return str;
    }
    friend std::ostream &operator<<(std::ostream &out, const Square &sq)
    {
        return out << sq.toString();
        /*std::stringstream ss;
        ss << static_cast<Rectangle&>(sq);
        std::string str = ss.str();
        for (int row = 1; row +1 < sq.h; ++row) {
            for (int col = 1; col + 1 < sq.w; ++col) {
                if (row == col || row + col == sq.w - 1)
                    str[row * (sq.w + 1) + col] = 'x';
            }
        }
        return out << str;*/
    }
    int type() const override
    {
        return SQUARE;
    }
};

void listRectangles(Rectangle *arr[], int size)
{
    for (int i = 0; i < 4; ++i)
    {
        /*if (arr[i]->type() == RECTANGLE)
            std::cout << "Rectangle:\n";
        else if (arr[i]->type() == SQUARE)
            std::cout << "Square:\n";
        else
            std::cout << "Unknown rectangle type:\n";*/
        Square *ptr = dynamic_cast<Square *>(arr[i]);
        if (ptr)
            std::cout << "Square:\n"
                      << *ptr;
        else
            std::cout << "Rectangle:\n"
                      << *arr[i];
    }
}

int main()
{
    Rectangle rect(6, 5);
    // rect.draw();
    std::cout << rect;
    rect.rotate();
    std::cout << rect;

    Square sq(5);
    // sq.draw();
    std::cout << sq;
    sq.rotate();
    std::cout << sq;

    std::cout << "====================\n";
    Rectangle *arr[4];
    arr[0] = new Rectangle(3, 8);
    arr[1] = new Square(3);
    arr[2] = new Rectangle(6, 2);
    arr[3] = new Square(6);
    // for (int i = 0; i < 4; ++i)
    // std::cout << *arr[i];
    listRectangles(arr, 4);

    std::cout << sizeof(Rectangle) << '\n'
              << sizeof(Square) << '\n';

    arr[3]->scale(2);
    std::cout << *arr[3];

    Square bad(4);
    bad.scaleWidth(3);
    std::cout << bad;

    for (int i = 0; i < 4; ++i)
        delete arr[i];
    std::cerr << "return from main()\n";
    return 0;
}