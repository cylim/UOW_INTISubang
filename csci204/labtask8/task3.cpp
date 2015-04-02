//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI204
//Task		: 8 - 3
//Date		: October 28th, 2014
//

#include "class.h"

template <class D>
int calcDistance(D d1, D d2){
	return d1 + d2;
}

int main(){
	int pen = 0, ven = 40;
	float mar = 92.4;
	double kl = 353.2;
	City Penang("Penang", pen);
	City KualaLumpur("Kuala Lumpur", kl);
	Planet Venus("Venus", ven);
	Planet Mars("Mars", mar);

	City temp1;
	Planet temp2;

	temp1 = Penang + KualaLumpur;
	temp1.setDistance(calcDistance(Penang.getDistance(), KualaLumpur.getDistance()));
	temp2 = Venus + Mars;
	temp2.setDistance(calcDistance(Venus.getDistance(), Mars.getDistance()));

	temp1.display();
	temp2.display(); 	
}