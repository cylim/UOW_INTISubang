class Circle{
	static const double pi;
	double radius;
public:
	Circle(); //Constructor
	void setRadius(double radius); //Mutator
	double getRadius(); //Accessor
	double calArea(); //count area
	double calDiameter(); //count diameter
	double calCircumference(); // count circumference
};