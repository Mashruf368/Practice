#include<iostream>
#include<string.h>
#include<math.h>
#include<cmath>


using namespace std;

double pi=M_PI;
class Rectangle
{
private:
    int length,width;
    char *color;
public:
    Rectangle() : length(0), width(0),color(nullptr) {}   //default constructor without parameters
    Rectangle(int a,int b,const char *s)  //constructor
    {
        this->length=a;
        this->width=b;
        //this->color=new string;
        color=new char[strlen(s)+1];
        strcpy(color, s);
    }

const char* getColor()
    {
       return color;
    }


int getPerimeter()
    {
        return 2*(this->length+this->width);
    }

int getArea()
    {
        return this->length*this->width;
    }
const char* setColor(const char *s)       //setter for color
{
    delete[] color;
    color=new char[strlen(s)+1];
    strcpy(color,s);
    return color;
}

    void setl(int l)
    {
        this->length=l;
    }
    void setw(int w)
    {
        this->width=w;
    }

    //getter

    int getl()
    {
        return length;
    }
    int getw()
    {
        return width;
    }
    const char* getc()
    {
        return color;
    }

    Rectangle (const Rectangle &r)
    {
        this->length=r.length;
        this->width=r.width;
        this->color=new char[strlen(r.color)+1];
        strcpy(this->color,r.color);
    }

    Rectangle* Clone ()
    {
        return new Rectangle(*this);
    }

    ~Rectangle ()
    {
        delete color;
    }

};

class Triangle
{
private:
    int a,b,c;
    char *color;
public:

    Triangle () : a(0),b(0),c(0),color(nullptr){}  //default constructor
    Triangle(int x,int y,int z ,const char *s)
    {
        this->a=x;
        this->b=y;
        this->c=z;
        color=new char[strlen(s)+1];
        strcpy(color, s);
    }
    int getPerimeter()
    {
        return a+b+c;
    }
    double getArea()
    {
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    const char* getColor()
    {
       return color;
    }
    
    const char* setColor(const char *s)
    {
        delete[] color;
        color=new char[strlen(s)+1];
        strcpy(color,s);
        return color;
    }
    void seta(int a)
    {
        this->a=a;
    }
    void setb(int b)
    {
        this->b=b;
    }
    void setc(int c)
    {
        this->c=c;
    }
    int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
    int getcc()
    {
        return c;
    }

    Triangle (const Triangle &t)
    {
        this->a=t.a;
        this->b=t.b;
        this->c=t.c;
        this->color=new char[strlen(t.color)+1];
        strcpy(this->color,t.color);
    }
    Triangle* Clone ()
    {
        return new Triangle(*this);
    }
    ~Triangle ()
    {
        delete color;
    }

    
};




class Circle
{
private:
    int radius;
    char *color;
public:

    Circle() : radius(0),color(nullptr) {}

    Circle (int a,const char *s)
    {
        radius=a;
        color=new char[strlen(s)+1];
        strcpy(color, s);
        
    }
    double getPerimeter()
    {
        return 2*pi*radius;
    }
    double getArea()
    {
        return pi*radius*radius;
    }
    const char* getColor()
    {
       return color;
    }
    int setr(int r)
    {
        this->radius=r;
    }
    const char* setColor(const char *s)
    {
        delete[] color;
        color=new char[strlen(s)+1];
        strcpy(color,s);
        return color;
    }

    int getr()
    {
        return radius;
    }

    Circle(const Circle &c)
    {
        this->radius=c.radius;
        this->color=new char[strlen(c.color)+1];
        strcpy(this->color,c.color);
    }

    Circle* clone()
    {
        return new Circle (*this);
    }
    ~Circle ()
    {
        delete color;
    }
};

class ShapeCollection
{
private:
   
    int rect_cap=1,tri_cap=1,cir_cap=1;
    Rectangle **rect=new Rectangle*[rect_cap];
    Triangle **tri=new Triangle*[tri_cap];
    Circle **cir=new Circle*[cir_cap];
    

    int ir=0,ic=0,it=0;
public:
    int getRectCount()
    {       
        return ir;
    }
    int getTriCount()
    {
        return it;
    }
    int getCircCount()
    {
        return ic;
    }


    void add(Rectangle r)
    {
        if(ir==rect_cap)
        {
            Rectangle **newrect=new Rectangle*[rect_cap*2];
            cout<<"Increasing capacity of rectangles from "<<rect_cap<<"to "<<rect_cap*2<<endl;
            for(int i=0;i<ir;i++)
            {
                newrect[i]=rect[i]->Clone();
                
            }
            
            delete [] rect;
            rect=newrect;
            rect_cap*=2; 

            
        }
        rect[ir]=r.Clone();
               
        ir++;
    }

    void add(Triangle t)
    {
        if(it==tri_cap)
        {
            Triangle **newtri=new Triangle*[tri_cap*2];
            cout<<"Increasing capacity of triangles from "<<tri_cap<<"to "<<tri_cap*2<<endl;
            for(int i=0;i<it;i++)
            {
                newtri[i]=tri[i]->Clone();
                
            }
            
            delete [] tri;
            tri=newtri;
            tri_cap*=2;
        }
        tri[it]=t.Clone();
        
        it++;
    }
    void add(Circle c)
    {
        if(ic==cir_cap) 
        {
            Circle **newcir=new Circle*[cir_cap*2];
            cout<<"Increasing capacity of circles from "<<cir_cap<<"to "<<cir_cap*2<<endl;
            for(int i=0;i<ic;i++)
            {
                newcir[i]=cir[i]->clone();
                
            }
            
            delete [] cir;
            cir=newcir;
            cir_cap*=2; 
        }
        cir[ic]=c.clone();
               
        ic++;
    }

    void printRectangles()
    {
        for(int i=0;i<ir;i++) 
        {
            cout<<"rectangle "<<i<<":"<<"length: "<<rect[i]->getl()<<" width: "<<rect[i]->getw()<<endl;
        }
    }
    void printTriangles()
    {
        for(int i=0;i<it;i++) 
        {
            cout<<"Triangle "<<i<<":"<<"a: "<<tri[i]->geta()<<" b: "<<tri[i]->getb()<<" c: "<<tri[i]->getcc()<<endl;
        }
    }
    void printCircles()
    {
        for(int i=0;i<ic;i++) 
        {
            cout<<"Circle "<<i<<":"<<"radius: "<<cir[i]->getr()<<endl;
        }
    }

    ~ShapeCollection()
    {
        for(int i=0;i<ir;i++) delete rect[i];
        delete [] rect;

        for(int i=0;i<it;i++) delete tri[i];
        delete [] tri;

        for(int i=0;i<ic;i++) delete cir[i];
        delete [] cir;
    }
};







int main()
{
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    /*
    When constructing the ShapeCollection class, you will create dynamic for 
    rectangles, triangles and circles. You have to dynamically allocate memory for this.
    */ 
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by value to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied. So, you have to write copy contructor so that 
    memory allocation is properly done and no double free error occurs.
    */ 
 
 
    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);
 
    Rectangle r2(15, 25, "Black");
    Rectangle r3(150, 225, "Green");
    shapes.add(r2);
    shapes.add(r3);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);
 
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
    return 0;





    // Triangle t2(7,8,9,"red");
    // shapes.addTriangle(&t1);
    // shapes.addTriangle(&t2);

    // Circle c2(89,"dark red");

    // shapes.addCircle(&c1);
    // shapes.addCircle(&c2);

    // cout<<"no of rect "<<shapes.getRectCount()<<endl;
    // cout<<"no of tri "<<shapes.getTriCount()<<endl;
    // cout<<"no of tri "<<shapes.getCircCount()<<endl;

     
    // shapes.printRectangles();
    // shapes.printTriangles();
    // shapes.printCircles();
    
    
    
}