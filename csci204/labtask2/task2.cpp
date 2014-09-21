//The program asked user to input temperature and convert it
//to other temperature format, no matter user input Celsius, Fahrenheit or Kelvin
//the class is used to store Kelvin, other tempature will convert to Kelvin for storing
//then convert to Fahrenheit and Celsius for display
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
using namespace std;

class Temperature{
	float kelvin;

public:
	void setTempKelvin(float);
	void setTempFahrenheit(float);
	void setTempCelsius(float);
	float getTempKelvin();
	float getTempFahrenheit();
	float getTempCelsius();
	void display();
};
//implementation class function
	//set function is used to set value into
	//private variable in class
	void Temperature::setTempKelvin(float temp){
		kelvin = temp;
	}
	//calculation to convert fahrenheit and celsius to Kelvin
	//For storing purposes
	void Temperature::setTempFahrenheit(float temp){
		kelvin = ((temp-32)*5/9) + 273.15;
	}
	void Temperature::setTempCelsius(float temp){
		kelvin = temp + 273.15;
	}
	//get function is to retrieve the data from class
	float Temperature::getTempKelvin(){
		return kelvin;
	}
	//As the data is store in Kelvin
	//Conversion is nessasory for Celsius and Fahrenheit
	float Temperature::getTempFahrenheit(){
		return ((kelvin - 273.15) * 9 / 5) + 32;
	}
	float Temperature::getTempCelsius(){
		return kelvin - 273.15;
	}
	//display function act as a bridge for the driver program
	//to print out the value from class private variables. 
	void Temperature::display(){
		cout << "Kelvin: " << getTempKelvin() << endl
			<< "Fahrenheit: " << getTempFahrenheit() << endl
			<< "Celsius: " << getTempCelsius() << endl;
	}

int main(){
	Temperature convertTemp;
	char type;
	float temp;
	cout << "Please input temperature: ";
	cin >> temp;
	cout << "k: Kelvin, f: Fahrenheit, c:Celsius\n"
		<<	"Please choose Temperature input type: ";
	cin >> type;
	//switch case statement to make the funciton accept
	//both capital and lower case character.
	switch(type){
		case 'k':
		case 'K':
			convertTemp.setTempKelvin(temp);
			break;
		case 'f':
		case 'F':
			convertTemp.setTempFahrenheit(temp);
			break;
		case 'c':
		case 'C':
			convertTemp.setTempCelsius(temp);
			break;
		default:
			cout << "Wrong type!";
			return 0;
	}
	//call class function to display the temparature
	//in Kelvin, Fehrenheit and Celsius
	convertTemp.display();
 }