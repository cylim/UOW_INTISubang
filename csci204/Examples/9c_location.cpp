class Loc{
private:
  int longitude, latitude;
public:
  Loc(){};	
  Loc(int lg, int lt) {longitude = lg;
					latitude = lt; }
  void show() const {
    	cout<<longitude << " " << latitude << endl;}
  Loc operator+(Loc op2);
  Loc operator()(int lg, int lt);
};

Loc Loc::operator+(Loc op2){
  Loc tmp;
  tmp.longitude = op2.longitude+longitude;
  tmp.latitude = op2.latitude+latitude;
  return tmp;
}
Loc Loc::operator()(int lg, int lt){
  longitude = lg;
  latitude = lt;
  return *this;
}

int main(){
  Loc ob1(10,20), ob2(1,1);
  ob1.show();
  ob1(7,8);
  ob1.show();

  ob1 = ob2 + ob1(10,10);
  ob1.show();
  return 0;
}
