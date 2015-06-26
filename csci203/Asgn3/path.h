class path{
	public:
		bool up;
		bool right;

		path(bool up, bool right){
			this->up = up;
			this->right = right;
		}

		path(){
			up = false;
			right = false;
		}	
};